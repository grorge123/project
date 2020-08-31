
def change_data(date):
    date = date.split(' ')
    if len(date) != 2:
        return [0,[]]
    date[0] = date[0].split('.')
    if len(date[0]) != 3 or date[1].count('星期') != 1:
        return [0,[]]
    date[1] = date[1].replace('\n', '')
    return [1, date]

def format_time(time):
    re = ''
    re += time[0][0] + '年'
    re += time[0][1] + '月'
    re += time[0][2] + '日'
    re += time[1]
    re += time[2][0] + '點'
    re += time[2][1] + '分'
    return re



def change_expense(data, time):
    re = {}
    time.append(data[0].split()[0].split(':'))
    re['time'] = time
    re['timestr'] = format_time(time)
    re['type'] = ''.join(data[0].split()[1:-3])
    re['dollar'] = data[0].split()[-1]
    for i in data:
        if i.count('商店名稱:') != 0:
            re['store'] = i.split()[1]
        elif i .count('LINE Pay卡一般消費回饋:') !=0:
            re['back'] = i.split()[2]
    return re
filename = '[LINE]LINE錢包.txt'

data = []
with open(filename, 'r', encoding="utf-8") as f:
    data = f.readlines()

now_time = []
start = -1
record = []

for i in range(len(data)):
    success, date = change_data(data[i])
    if success == 1:
        now_time = date
    if data[i].count('付款') != 0 and data[i].count('付款完成。') == 0:
        if start != -1:
           record.append(change_expense(data[start:i], now_time.copy()))
        start = i 
column = ['編號', '時間', '付款方式', '商店名稱', '花費金錢', '回饋']
toeng = {'編號':'num', '時間':'timestr', '付款方式':'type', '商店名稱':'store', '花費金錢':'dollar', '回饋':'back'}
allmoney = 0
outputname = '計算表.csv'
year, month, day = list(map(int,input('請輸入限制時間:').split()))
with open(outputname, 'w') as f:
    for i in column:
        f.write(i)
        f.write(',')
    f.write('\n')
    for i in range(len(record)):
        if year >= int(record[i]['time'][0][0]):
            if month >= int(record[i]['time'][0][1]):
                if day > int(record[i]['time'][0][2]):
                    continue
        print(record[i]['timestr'])
        f.write(str(i+1))
        f.write(',')
        for q in column:
            if toeng[q] in record[i].keys():
                f.write(str(record[i][toeng[q]]))
                f.write(',')
        allmoney += int(record[i]['dollar'])
        f.write('\n')
    f.write('花費總額:,')
    f.write(str(allmoney))
    f.write('\n')