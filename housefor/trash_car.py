import pandas as pd
import os
import functools
import requests
import json

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

dic = []
os.chdir('trash_car')
df = pd.read_csv('car.csv', encoding='utf-8')
lis = list(df[['行政區', '清運點名稱']].values.tolist())
for i in range(len(lis)):
    dic.append('桃園市' + lis[i][0] + lis[i][1])

with open('save.csv','w') as fi:
    for i in range(len(dic)):
        location = get_addr(dic[i], 'AIzaSyBy3DZKBd5yAyIefybiwBcvAcOqtDN6Wyc')
        fi.write(dic[i] + ','+ str(location['lat']) + ',' + str(location['lng']) + '\n')
