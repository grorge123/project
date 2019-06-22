import requests
import time
url = 'https://passport.sfacg.com/'
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
se = requests.session()
r = se.get(url, headers=headers)
#print(r.status_code)
r.encoding = r.apparent_encoding
#print(r.text)
headers2 = {
    'accept': 'application/json, text/javascript, */*; q=0.01',
    'Referer': 'http://book.sfacg.com/signin/',
    'upgrade-insecure-requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36',
    'cookie': 'UM_distinctid=16b2fb64fa7149-08dad89a9950df-e353165-1fa400-16b2fb64fa8180; _uab_collina=155987360871026469003698; dnttemplateid_2_5_0=1; nickNameCookie=5B72B187124820D5; lastolupdate=-1951982422; CNZZDATA30062359=cnzz_eid%3D98632568-1559868903-%26ntime%3D1559919022; CNZZDATA30013274=cnzz_eid%3D214933329-1559869544-%26ntime%3D1559921337; .SFCommunity=AA5062341B0BB96AC942CDB462ED1D1AB078F7F77EB7371888FCC2D748D1C11A5FFF599E1F28D643B458DB4922AAC68DC67CC536352099B6E3212BC8AF7BD442C8CF9DACD91B0E4E410BE991C2BAA03093433E1AD9726998EBD932EF751FCECE; dnt=userid=2519272&password=oTWPc0x5jOMYFVO8gwuYxlPrlwQ5g4lF6fSRY4zUjRg3uG8pJCiaBA%3d%3d&avatar=avatars%2fcommon%2f0.gif&tpp=0&ppp=0&pmsound=0&invisible=0&referer=index.aspx&sigstatus=0&expires=21600',
    'M-Requested-With' : 'XMLHttpRequest'
}
ticks = time.time()
url = 'http://book.sfacg.com/ajax/ashx/Common.ashx?op=signinNew&nid=0&_='
url += str(int(ticks))
print(url)
r = se.get(url, headers = headers2)
r.encoding = r.apparent_encoding
print(r.text)
