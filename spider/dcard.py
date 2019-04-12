import requests
from bs4 import BeautifulSoup


http = "https://www.dcard.tw"
r = requests.get("https://www.dcard.tw/f/sex") #將網頁資料GET下來
soup = BeautifulSoup(r.text,"html.parser") #將網頁資料以html.parser
sel = soup.select("div.PostList_entry_1rq5Lf a.PostEntry_root_V6g0rd") #取HTML標中的 <div class="title"></div> 中的<a>標籤存入sel
#print(sel[0].text)
url = []
for s in sel:
        print(len(url),s.find("h3").text)
        url.append(http + s["href"][0:s["href"].find('-')])
while(1):
    a = int(input())
    print(url[a])
