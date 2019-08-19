
#%%
from selenium import webdriver
from math import radians, cos, sin, asin, sqrt
import time
import requests
import json
import pandas as pd
import os
import numpy as np
#https://rent.591.com.tw/rent-detail-8045820.html
browser = webdriver.Firefox()
api_key = ''
worked = []


def haversine(lon1, lat1, lon2, lat2): # 經度1 緯度1　經度2　緯度2
    lon1 = float(lon1)
    lat1 = float(lat1)
    lon2 = float(lon2)
    lat2 = float(lat2)
    lon1, lat1, lon2, lat2 = map(radians, [lon1, lat1, lon2, lat2])
    dlon = lon2 - lon1 
    dlat = lat2 - lat1 
    a = sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlon/2)**2
    c = 2 * asin(sqrt(a)) 
    r = 6371 
    return c * r * 1000
'''
def haversine(lon1, lat1, lon2, lat2): # 經度1 緯度1　經度2　緯度2
    
    A = np.matrix([[lat1, lon1]])
    B = np.matrix([[lat2, lon2]])
    ra = 6378140  # radius of equator: meter
    rb = 6356755  # radius of polar: meter
    flatten = 0.003353 # Partial rate of the earth
    # change angle to radians
    
    radLatA = np.radians(A[:,0])
    radLonA = np.radians(A[:,1])
    radLatB = np.radians(B[:,0])
    radLonB = np.radians(B[:,1])
 
    pA = np.arctan(rb / ra * np.tan(radLatA))
    pB = np.arctan(rb / ra * np.tan(radLatB))
    
    x = np.arccos( np.multiply(np.sin(pA),np.sin(pB)) + np.multiply(np.multiply(np.cos(pA),np.cos(pB)),np.cos(radLonA - radLonB)))
    c1 = np.multiply((np.sin(x) - x) , np.power((np.sin(pA) + np.sin(pB)),2)) / np.power(np.cos(x / 2),2)
    c2 = np.multiply((np.sin(x) + x) , np.power((np.sin(pA) - np.sin(pB)),2)) / np.power(np.sin(x / 2),2)
    dr = flatten / 8 * (c1 - c2)
    distance = ra * (x + dr)
    return distance[0]
'''
def get_addr(addr, api_key):
    url = "https://maps.googleapis.com/maps/api/geocode/json?key=" + api_key + "&address=" + addr
    print("requests url:{}".format(url))
    re = requests.get(url)
    js = json.loads(re.text)
    location = {}
    for key, values in js['results'][0]['geometry']['location'].items():
        location[key] = values
        print(key, values)
    return location

def have_building(location, typ, api_key):
    url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json?location=" + str(location['lat']) + ',' + str(location['lng']) + "&radius=100&types=" + typ + "&key="+api_key
    re = requests.get(url)
    print("have_building:{} {}".format(typ, url))
    js = json.loads(re.text)
    if len(js['results']) > 0:
        return len(js['results']), js['results'][0]['name']
    return len(js['results']), re

def get_traffic(location):
    path = os.getcwd()
    os.chdir('traffic')
    df = pd.read_csv('save.csv')
    os.chdir(path)
    lis = list(df[['縣市', '經度', '緯度']].values.tolist())
    for i in range(len(lis)):
        if haversine(location['lng'], location['lat'], lis[i][1], lis[i][2]) < 100:
            print('traffic:{}'.format(lis[0]))
            return True
    return False


def get_trash_car(location):
    path = os.getcwd()
    os.chdir('trash_car')
    df = pd.read_csv('save2.csv')
    os.chdir(path)
    lis = list(df[['縣市', '經度', '緯度']].values.tolist())
    MIN = 1000000000
    add = ''
    for i in range(len(lis)):
        print(haversine(location['lng'], location['lat'], lis[i][1], lis[i][2]), MIN)
        if haversine(location['lng'], location['lat'], lis[i][1], lis[i][2]) < MIN:
            MIN = haversine(location['lng'], location['lat'], lis[i][1], lis[i][2])
            add = lis[i][0]
    return add, MIN

def write_info(info, addr):
    path = os.getcwd()
    os.chdir('main/data')
    if len(info) == 0:
        info.append("無特殊資訊")
    with open(addr+'.txt','w') as fi:
        for i in info:
            fi.write(i)
    os.chdir(path)
    return

while True:
    for current_window in browser.window_handles:
        if worked.count(current_window):
            continue
        else:
            worked.append(current_window)
        if browser.current_url.count("rent.591.com.tw"):
            browser.switch_to.window(current_window)
            time.sleep(0.5)
            print("web url:{}".format(browser.current_url))
            element = []
            time.sleep(0.5)
            try:
                element = browser.find_element_by_css_selector("span.addr")
            except:
                continue
            addr = element.text
            print("house address:{}".format(element.text))
            info = []
            location = get_addr(addr, api_key)
            if get_traffic(location):
                info.append('此地點附近有高交通事故路段!!!<br>')
            trash_add, trash_dis = get_trash_car(location)
            info.append('最近倒垃圾位置為:{} 距離:{} m<br>'.format(trash_add, int(trash_dis)))
            build, name = have_building(location, 'cemetery', api_key)
            if build != 0:
                info.append('此地點附近有殯儀館/墓地 名稱為{}<br>'.format(name))
            build, name = have_building(location, 'night_club', api_key)
            if build != 0:
                info.append('此地點附近有夜店 名稱為{}<br>'.format(name))
            build, name = have_building(location, 'gas_station', api_key)
            if build != 0:
                info.append('此地點附近有加油站 名稱為{}<br>'.format(name))
            build, name = have_building(location, 'gas_station', api_key)
            if build != 0:
                info.append('此地點附近有酒吧 名稱為{}<br>'.format(name))
            write_info(info, addr)
#%%
