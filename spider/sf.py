from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
import time

browser = webdriver.Firefox()
em = ''
pa = ''
log = open('log.txt','a')
success = 0
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
            try:
                browser.find_element_by_id('reg-link')
                success = 2
                break
            except:
                time.sleep(1)
    while success != 2:
        try:
            browser.find_element_by_link_text('签到得代劵').click()
            break
        except:
            time.sleep(1)
    while success != 2:
        try:
            browser.find_element_by_class_name('sign-btn').find_element_by_tag_name('a').click()
            success = 0
            break
        except:
            time.sleep(1)
    time.sleep(3)
    try:
        browser.find_element_by_class_name('sign-btn  signed')
        success = 1
    except:
        success = 0
    log.write(time.asctime( time.localtime(time.time()) ) + '\n')
    if success == 0:
        log.write('successful login\n')
    elif success == 1:
        log.write('you have checked in\n')
    elif success == 2:
        log.write('wrong email or passwd\n')
    print("finish")
finally:
    browser.close()
    log.close()
