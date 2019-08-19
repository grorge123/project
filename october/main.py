
#%%
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
import time
import requests
import json

browser = webdriver.Firefox()
api_key = ''
worked = []

def get_addr(addr, api_key):
    url = "https://maps.googleapis.com/maps/api/geocode/json?key=" + api_key + "&address=" + addr
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
    return len(js['results']), re

while True:
    for current_window in browser.window_handles:
        if worked.count(current_window):
            continue
        else:
            worked.append(current_window)
        if browser.current_url.count("rent.591.com.tw"):
            browser.switch_to.window(current_window)
            time.sleep(0.5)
            print(browser.current_url)
            element = []
            time.sleep(0.5)
            try:
                element = browser.find_element_by_css_selector("span.addr")
            except:
                continue
            addr = element.text
            print(element.text)
            
#%%
