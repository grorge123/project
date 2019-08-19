import pandas as pd
import os
import functools
import math

def scmp(a):
    return int(a[1])

dic = {}
os.chdir('traffic')

for i in range(101,106):
    df = pd.read_csv(str(i)+'.csv')
    lis = list(df[['縣市','區','街道','死','受傷','街道1','道路','附近']].values.tolist())
    for i in range(len(lis)):
        if type(lis[i][2]) == float:
            if type(lis[i][5]) == float:
                lis[i][2] = lis[i][6]
            else:
                lis[i][2] = lis[i][5]
        if type(lis[i][2]) == float:
            continue
        if  math.isnan(lis[i][3] + lis[i][4]):
            contiune
        if lis[i][0] + lis[i][1]+lis[i][2] in dic:
            dic[lis[i][0] + lis[i][1] + lis[i][2]] += lis[i][3] + lis[i][4]
        else:
            dic[lis[i][0] + lis[i][1] + lis[i][2]] = lis[i][3] + lis[i][4]

for i in range(106,109):
    df = pd.read_csv(str(i)+'.csv')
    lis = list(df[['發生縣市名稱','發生市區鄉鎮名稱','發生地址_路街','死亡人數_24小時內','死亡人數_2_30日內','受傷人數','發生地址_其他']].values.tolist())
    for i in range(len(lis)):
        #if len(lis[i][2]) <= 1 or lis[i][2] == "NA":
         #   lis[i][2] = lis[i][6]
        if len(lis[i][2]) <= 1 or lis[i][2] == "NA":
            continue
        #print(lis[i][0] + lis[i][1] + lis[i][2])
        if  math.isnan(lis[i][3] + lis[i][4] + lis[i][5]):
            continue
        if lis[i][0] + lis[i][1]+lis[i][2] in dic:
            dic[lis[i][0] + lis[i][1] + lis[i][2]] += lis[i][3] + lis[i][4] + lis[i][5]
        else:
            dic[lis[i][0] + lis[i][1] + lis[i][2]] = lis[i][3] + lis[i][4] + lis[i][5]

sort_list = []

for key, values in dic.items():
    sort_list.append((key, values))
sort_list = sorted(sort_list, key=scmp, reverse=True)
#print(sort_list[0:40])
dic = {}
for i in range(len(sort_list)):
    if sort_list[i][1] > 96:
        dic[sort_list[i][0]] = sort_list[i][1]
    else:
        break
print(len(dic))
