#encoding: utf-8
#author: walker
#date:  2017-12-01 
#summary: 用socket創建tcp server以接收文件 

import os, time
import socket
import struct
import shutil
from azure.cognitiveservices.vision.customvision.prediction import CustomVisionPredictionClient
import numpy as np
import cv2

cur_dir_fullpath = os.path.dirname(os.path.abspath(__file__))

Host = '192.168.163.1'
Port = 6789
BufSize = 8196
FmtHead = '256sHL'	#L決定單個文件必須小於4G
FmtHeadLen = struct.calcsize(FmtHead)
DstRoot = os.path.join(cur_dir_fullpath, 'output')	#目標目錄
StartTime = time.time()		#開始時間	
def CV(fname,img):
    fname = fname[:fname.find('.')] + '.jpg'
    cv2.imwrite(fname, img)
    ENDPOINT = "https://southcentralus.api.cognitive.microsoft.com"
    predictor = CustomVisionPredictionClient("74845b27d7b747f7b3f9f85f4515be96", endpoint=ENDPOINT)
    with open(fname, mode="rb") as test_data:
        results = predictor.detect_image("ac90b148-4334-49b3-921c-d08e8da2b5e4", "findhole",test_data)
    for prediction in results.predictions:
        if prediction.probability >= 0.8:
            bd = prediction.bounding_box
            cv2.rectangle(img, (int(bd.width * img.shape[1]) + int(bd.left * img.shape[1]), int(bd.height * img.shape[0]) + int(bd.top * img.shape[0])), (int(bd.left * img.shape[1]), int(bd.top * img.shape[0])), (0, 0, 255), 2)

    with open(fname, mode="rb") as test_data:
        results = predictor.detect_image("729bf71b-467f-4c8f-988c-ec06e060a2e4", "findLP", test_data)
    for prediction in results.predictions:
        if prediction.probability >= 0.7:
            bd = prediction.bounding_box
            print(prediction.probability)
            cv2.rectangle(img, (int(bd.width * img.shape[1]) + int(bd.left * img.shape[1]), int(bd.height * img.shape[0]) + int(bd.top * img.shape[0])), (int(bd.left * img.shape[1]), int(bd.top * img.shape[0])), (0, 0, 255), 2)
    return img

def ProcAll():
	cnt = 0
	fileSizeTotal = 0
	sockServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sockServer.bind((Host, Port))
	print('Listen prot %d ...' % Port)
	sockServer.listen(1)
	sock, addr = sockServer.accept()
	print('local: %s:%d' % (sock.getsockname()))
	print('client: %s:%d' % addr)
	while True:
		#接收數據包頭（相對路徑，相對路徑長度，文件大小）
		pkgHead = sock.recv(FmtHeadLen)
		relPath, relPathLen, fileSize = struct.unpack(FmtHead, pkgHead)
		relPath = relPath.decode('utf8')[0:relPathLen]
		if relPath == 'OVER' and fileSize == 0:
			print('All file recv over!')
			break
		pathfile = os.path.join(DstRoot, relPath)
		dstDir = os.path.dirname(pathfile)
		if not os.path.exists(dstDir):
			os.makedirs(dstDir)
		with open(pathfile, mode='wb') as f:
			recvSize = 0	#單文件已接收數據量
			while True:
				if recvSize >= fileSize:
					break
				bufSize = BufSize
				if fileSize - recvSize < BufSize:	#剩余數據量小於BufSize
					bufSize = fileSize - recvSize
				buf = sock.recv(bufSize)
				f.write(buf)
				recvSize += len(buf)
			fileSizeTotal += recvSize
		cnt += 1
		print('cnt: %d, time cost: %.2fs, %s'% (cnt, time.time()-StartTime, pathfile))
				
	sock.close()
	sockServer.close()
	
	print('cnt: %d, time total: %.2fs, send bytes:%ld B'% (cnt, time.time()-StartTime, fileSizeTotal))

now = 0
def AI_video():
    os.chdir("output")
    for f in os.listdir("."):
        vc = cv2.VideoCapture(f)
        rval = vc.isOpened()
        fps = 25
        fourcc = cv2.VideoWriter_fourcc(*'MP4V')
        videoWriter = cv2.VideoWriter("../deal/" + f,fourcc,fps,(960, 540))#最后一个是保存图片的尺寸
        while rval:
            rval, frame = vc.read()
            global now
            print(now)
            now += 1
            if frame is None:
                break
            frame = cv2.resize(frame, (960, 540), interpolation=cv2.INTER_CUBIC)
            videoWriter.write(CV(f, frame))
            # videoWriter.write(frame)
        fname = f[:f.find('.')] + '.jpg'
        # os.remove(fname)
        vc.release()
        videoWriter.release()
        shutil.move(f,"../old/"+f)
    os.chdir("..")
if __name__ == '__main__':
	ProcAll()
	AI_video()
	print('Time total:%.2fs' % (time.time() - StartTime))