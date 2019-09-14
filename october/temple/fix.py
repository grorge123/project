import pandas as pd
import requests
import json

df = pd.read_csv('temple.csv')
lis = list(df['住址'].values.tolist())
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
#print(lis[0:10])
with open('save.csv','w') as fi:
    for i in range(len(lis)):
        location = get_addr(lis[i], '')
        fi.write(lis[i]+','+str(location['lat'])+',' + str(location['lng']) + '\n')
