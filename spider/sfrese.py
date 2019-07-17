#!/usr/bin/env python
# coding: utf-8

# In[1]:


import requests
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
import time
import os


# In[2]:


cookie = ''
if(os.path.exists('cookies.txt')):
    fi = open('cookies.txt', 'r+')
    cookie = fi.read()
    fi.close()
log = open('log.txt', 'a')
url = 'https://passport.sfacg.com/'
url = 'http://book.sfacg.com/ajax/ashx/Common.ashx?op=signinNew&nid=0&_=' #登入介面
headers = {
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3',
    'accept-encoding': 'gzip, deflate, br',
    'accept-language': 'zh-TW,zh;q=0.9,en-US;q=0.8,en;q=0.7',
    'cache-control': 'max-age=0',
    'connection': 'keep-alive',
    'cookie':'UM_distinctid=16b2fb64fa7149-08dad89a9950df-e353165-1fa400-16b2fb64fa8180; _uab_collina=155987360871026469003698; dnttemplateid_2_5_0=1; nickNameCookie=5B72B187124820D5; lastolupdate=-1951982422; CNZZDATA30062359=cnzz_eid%3D98632568-1559868903-%26ntime%3D1559919022; CNZZDATA30013274=cnzz_eid%3D214933329-1559869544-%26ntime%3D1559921337; .SFCommunity=AA5062341B0BB96AC942CDB462ED1D1AB078F7F77EB7371888FCC2D748D1C11A5FFF599E1F28D643B458DB4922AAC68DC67CC536352099B6E3212BC8AF7BD442C8CF9DACD91B0E4E410BE991C2BAA03093433E1AD9726998EBD932EF751FCECE; dnt=userid=2519272&password=oTWPc0x5jOMYFVO8gwuYxlPrlwQ5g4lF6fSRY4zUjRg3uG8pJCiaBA%3d%3d&avatar=avatars%2fcommon%2f0.gif&tpp=0&ppp=0&pmsound=0&invisible=0&referer=index.aspx&sigstatus=0&expires=21600',
    'host': 'passport.sfacg.com',
    'Referer': 'https://passport.sfacg.com/Message.aspx?msg=LoginSuccessToHome&rul=/',
    'upgrade-insecure-requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36'
}
headers2 = {
    'accept': 'application/json, text/javascript, */*; q=0.01',
    'Referer': 'http://book.sfacg.com/signin/',
    'upgrade-insecure-requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36',
    'cookie': 'UM_distinctid=16ba8b899f423b-06fed66d9b60ab-e343166-1fa400-16ba8b899f565; _uab_collina=156190380126320538145968; CNZZDATA30013274=cnzz_eid%3D1420627595-1561899553-%26ntime%3D1561899553; CNZZDATA30062359=cnzz_eid%3D1941657490-1561899088-%26ntime%3D1561899088; .SFCommunity=D5EA76C489B0344B7B0E20C4B9E597FB506EF9140EC18B3E6CBD3DD5BC75097BD92FC3ED32C6CBA6EBD568B35727F6DB2C2D0D27AB33D1B5D4DF5829C5CA1FF97E59724EF94AF4ED64F912E633843325765194BD9A3DD45D6F204000CB530A8C; dnt=userid=2519272&password=oTWPc0x5jOMYFVO8gwuYxlPrlwQ5g4lF6fSRY4zUjRg3uG8pJCiaBA%3d%3d&avatar=avatars%2fcommon%2f0.gif&tpp=0&ppp=0&pmsound=0&invisible=0&referer=index.aspx&sigstatus=0&expires=21600; dnttemplateid_2_5_0=1; lastolupdate=77926237; session_PC_5B72B187124820D5=5E60D6DE99D888BD2DFDF6E04AC19CFD',
    'M-Requested-With' : 'XMLHttpRequest'
}
headers2['cookie'] = cookie



# In[3]:


se = requests.session()
# r.encoding = r.apparent_encoding
r = se.get(url, headers = headers2)
log.write(time.asctime( time.localtime(time.time()) ) + '\n')


# In[6]:


if r.text.count('200'):
    print('登入成功')
    log.write('登入成功\n')
if r.text.count('您今天已经签过到了,请明天再来'):
    print('您今天已经签过到了,请明天再来')
    log.write('您今天已經簽到過了\n')
if r.text.count('需要登录才能执行该操作'):
    em = ''
    pa = ''
    success = 0
    try:
        browser = webdriver.Firefox()
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
        cookies = browser.get_cookies()
    finally:
        browser.close()
    print(cookies)
    fi = open('cookies.txt', 'w')
    cookie = ''
    for i in cookies:
        if not i == cookies[0]:
            cookie += '; '
        cookie += i['name']
        cookie += '='
        cookie += i['value']
    fi.write(cookie)
    print(cookie)
    fi.close()
    log.write('cookies失效,已用selinum登入\n')
    log.close()


# In[ ]:




