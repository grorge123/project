#encoding: utf-8
#author: walker
#date: 2017-12-01 
#summary: 用socket連接tcp server以傳送文件

import os, time
import socket
import struct

cur_dir_fullpath = os.path.dirname(os.path.abspath(__file__))

Host = '192.168.43.191'
Port = 6789
BufSize = 8196
FmtHead = '256sHL'	#L決定單個文件必須小於4G
SrcRoot = os.path.join(cur_dir_fullpath, '.')	#源目錄
print(SrcRoot)
ExtSet = {'.pdf', '.html', '.htm','.mp4'}		#後綴列表
StartTime = time.time()		#開始時間


def ProcAll():
	cnt = 0
	fileSizeTotal = 0
	sockClient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	print('Connect %s:%d ...' % (Host, Port))
	sockClient.connect((Host, Port))
	print('local: %s:%d' % (sockClient.getsockname()))
	for parent, dirnames, filenames in os.walk(SrcRoot):
		for filename in filenames:
			if os.path.splitext(filename)[1].lower() not in ExtSet:	#排除非指定後綴的文件
				continue
			pathfile = os.path.join(parent, filename)
			relPath = pathfile[len(SrcRoot):].strip(os.path.sep)	#相對路徑（相對於SrcRoot）
			fileSize = os.path.getsize(pathfile)
			#發送數據包頭（相對路徑，相對路徑長度，文件大小）
			pkgHead = struct.pack(FmtHead, relPath.encode('utf8'), len(relPath), fileSize)
			sockClient.sendall(pkgHead)
			with open(pathfile, mode='rb') as f:
				while True:
					buf = f.read(BufSize)
					if len(buf) < 1:
						break
					sockClient.sendall(buf)
			fileSizeTotal += fileSize
			cnt += 1
			print('cnt: %d, time cost: %.2fs, %s'% (cnt, time.time()-StartTime, pathfile))
	
	#發送文件傳送結束消息
	pkgHead = struct.pack(FmtHead, 'OVER'.encode('utf8'), len('OVER'), 0)
	sockClient.sendall(pkgHead)
	
	sockClient.close()
	
	print('cnt: %d, time total: %.2fs, send bytes:%ld B'% (cnt, time.time()-StartTime, fileSizeTotal))
	

if __name__ == '__main__':

    ProcAll()
    
    print('Time total:%.2fs' % (time.time() - StartTime))