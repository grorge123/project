
#%%
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
import time

browser = webdriver.Firefox()
worked = []
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
