import threading 
import socket, sys
import os
'''
#建立socket :通過server接收
#繫結目的ip和埠號
#設定監聽
#建立連線Socket,Address接收資訊
#資料互動senddata 傳送資料
         receive 接收資料
'''
ID = 0

def threadWork(client):
    global ID
    nowID = ID
    ID += 1
    while True:
        msg = client.recv(1024).decode(encoding='utf_8', errors='strict')
        if not msg:
            pass
        else:
            print("Client",ID,"send: %s" % msg )
            # client.send(text.encode(encoding='utf_8', errors='strict'))
    client.close()

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM) #TCP
# server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) #UDP
server.bind(("192.168.43.191",8080)) #繫結的ip和埠在元組中

server.listen(5)   #引數為監聽的數目
print("{}啟動成功，等待{}連線".format("伺服器","客戶端"))
# Socket.sendto("你好，歡迎訪問伺服器".encode("utf-8"),("192.168.43.28",8080))
while True :
    # Socket, Adress = server.recvfrom(2048)
    # if not Socket:
    #     print("client has exist")
    #     break
    # print(Socket, Adress)

    print("Listening ... ")
    (csock, adr) = server.accept()
    print("Client Info: " , csock , adr )
    thread = threading.Thread(target=threadWork,args=(csock,))   # 設定線程
    thread.start()# 啟動線程

sock.close()

