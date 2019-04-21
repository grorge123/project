from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
import time

browser = webdriver.Firefox()
em = ''
pa = ''

try:
    #browser.get('https://passport.sfacg.com/Login.aspx')
    browser.get('https://www.facebook.com/v2.8/dialog/oauth?client_id=314584345382224&response_type=code&redirect_uri=https://proxypassport.sfacg.com/oauth/facebook/authsuccess-1.ashx&state=sf&scope=email')
    login_em = browser.find_element_by_id('email')
    login_pa = browser.find_element_by_id('pass')
    login_em.send_keys(em)
    login_pa.send_keys(pa)
    login_pa.send_keys(Keys.ENTER)
    while 1:
        try:
            browser.find_element_by_class_name('redfont_input').click()
            break
        except:
            time.sleep(1)
    while 1:
        try:
            browser.find_element_by_link_text('签到得代劵').click()
            break
        except:
            time.sleep(1)
    while 1:
        try:
            browser.find_element_by_class_name('sign-btn').find_element_by_tag_name('a').click()
            break
        except:
            try:
                browser.find_element_by_class_name('sign-btn signed')
                break
            except:
                time.sleep(1)
    print("finish")
finally:
    browser.close()
