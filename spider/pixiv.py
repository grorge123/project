from bs4 import BeautifulSoup
import requests

headers_1 = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36'
}
url = 'https://accounts.pixiv.net/login?lang=zh_tw&source=pc&view_type=page&ref=wwwtop_accounts_index'
se = requests.session()
get_1 = se.get(url, headers = headers_1)
get_1.encoding = get_1.apparent_encoding
soup = BeautifulSoup(get_1.text, 'lxml')
post_key = soup.find(attrs={'name': 'post_key'})['value']
print('post_key=', post_key)

headers_2 = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36',
    'accept': 'application/json',
    'accept-encoding': 'gzip, deflate, br',
    'accept-language': 'zh-TW,zh;q=0.9,en-US;q=0.8,en;q=0.7',
    'referer': 'https://accounts.pixiv.net/login?lang=zh_tw&source=pc&view_type=page&ref=wwwtop_accounts_index'
}
pixiv_id = 'user_tkfd4227'
password = '987890123'
data = {
    'pixiv_id': pixiv_id,
    'password': password,
    'post_key': post_key,
    'return_to': 'https://www.pixiv.net/'
}
re = se.post(url, headers=headers_2, data=data)
print(re.status_code)
