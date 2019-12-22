import pandas as pd
import requests
import json

df = pd.read_csv('save1.csv')
lis = list(df[['縣市','緯度','經度']].values.tolist())
cnt = 0

def get_addr(addr, api_key):
    url = "https://maps.googleapis.com/maps/api/geocode/json?key=" + api_key + "&address=" + addr
    re = requests.get(url)
    js = json.loads(re.text)
    location = {}
    print(addr)
    if len(js['results']) == 0:
        return {'lat':0, 'lng':0}
    for key, values in js['results'][0]['geometry']['location'].items():
        location[key] = values
        print(key, values)
    return location

with open('save2.csv','w') as fi:
    for i in range(len(lis)):
        if lis[i][1] == '0' and cnt < 25:
            location = get_addr(lis[i][0], 'AIzaSyBy3DZKBd5yAyIefybiwBcvAcOqtDN6Wyc')
            lis[i][1] = location['lat']
            lis[i][2] = location['lng']
            print(cnt)
        fi.write(lis[i][0]+','+str(lis[i][1])+',' + str(lis[i][2]) + '\n')
