import requests
from bs4 import BeautifulSoup
import os
from os import listdir
import time
 
def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass
 
    try:
        import unicodedata
        unicodedata.numeric(s)
        return True
    except (TypeError, ValueError):
        pass
 
    return False
 
def format(st):
    head = toil = 0
    for i in range(len(st)):
        if is_number(st[i]):
            head = i
            break
    for i in range(1,len(st)):
        if is_number(st[-i]):
            toil = -i
            break
    st = st[head:toil+1]
    st = st.replace(':','-')
    return st

old_url = "https://data.tycg.gov.tw"
url = "https://data.tycg.gov.tw/opendata/datalist/datasetMeta?oid=f4cc0b12-86ac-40f9-8745-885bddc18f79"
os.chdir("opendata")
now_time = ""

while 1==1:
    se = requests.session()
    se = se.get(url)
    soup = BeautifulSoup(se.text,"lxml")
    sel = soup.find_all("tr")
    update_time = "";
    for i in sel:
        if i.find_all("td")[0].text.count("最後更新時間"):
            update_time = i.find_all("td")[1].text
            break
    update_time = format(update_time)
    print(update_time)
    if now_time != update_time:
        now_time = update_time
        hre = soup.select(".resource-url-analytics")
        hre = hre[0]["href"]
        hre = old_url + hre
        r = requests.get(hre)
        #print(r.text)
        name = now_time + '.json'
        with open(name, 'w') as f:
            f.write(r.text)
            f.close()
    time.sleep(180)
