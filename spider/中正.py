# coding=Big5
import requests
from bs4 import BeautifulSoup
import sys

http = "http://www.ccsh.tp.edu.tw/front/bin/home.phtml"
r = requests.get("http://www.ccsh.tp.edu.tw/front/bin/home.phtml") #將網頁資料GET下來
#r.encoding='big5' #轉換編碼
r.encoding = r.apparent_encoding
soup = BeautifulSoup(r.text,"html.parser") #將網頁資料以html.parser
sel = soup.select("a.shadow-link font") #取HTML標中的 <div class="title"></div> 中的<a>標籤存入sel
#print(sel[0].text)
url = []
for s in sel:
        print(s.text)
while(1):
    a = int(input())
    print(url[a])
