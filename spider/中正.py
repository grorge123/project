# coding=Big5
import requests
from bs4 import BeautifulSoup
import sys

http = "http://www.ccsh.tp.edu.tw/front/bin/home.phtml"
r = requests.get("http://www.ccsh.tp.edu.tw/front/bin/home.phtml") #�N�������GET�U��
#r.encoding='big5' #�ഫ�s�X
r.encoding = r.apparent_encoding
soup = BeautifulSoup(r.text,"html.parser") #�N������ƥHhtml.parser
sel = soup.select("a.shadow-link font") #��HTML�Ф��� <div class="title"></div> ����<a>���Ҧs�Jsel
#print(sel[0].text)
url = []
for s in sel:
        print(s.text)
while(1):
    a = int(input())
    print(url[a])
