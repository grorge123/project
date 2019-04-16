import sound
import random
import os
def readtxt():
    chi = open("chi.txt",'r')
    eng = open("eng.txt",'r')
    chi = chi.readlines()
    eng = eng.readlines()
    for i in range(len(chi) - 1):
        chi[i] = chi[i][0:len(chi[i]) - 1]
    for i in range(len(eng) -
                   1):
        eng[i] = eng[i][0:len(eng[i]) - 1]
    return chi, eng
def check_down(eng):
    
    print("下載影音檔案:")
    print("現在進度" + "0" + "%")
    os.chdir("./sound")
    sound_list = []
    for i in eng:
        if not os.path.exists(i + '.mp3'):
            sound_list.append(i)
    add = 0
    if len(sound_list) == 0:
        add = 100
    else:
        add = 100 / len(sound_list)
    now = 0
    for i in sound_list:
        sound.download_mp3(i, 'en')
        now += add
        print("現在進度%.2f" % (now))
    if now != 100:
        print("現在進度" + "100" + "%")
    os.getcwd()
if __name__ == '__main__':
    chi, eng = readtxt()
    check_down(eng)
    while(len(chi) != 0):
        ra = random.randint(0, len(chi) - 1)
        print(chi[ra] + ' ' + str(eng[ra].count(' ') + 1) + ' ' +str(len(chi)))
        inp = input()
        if(inp == eng[ra]):
            print("YES")
            sound.Text2Voice(eng[ra], 'en')
            chi.pop(ra)
            eng.pop(ra)
        else:
            print(eng[ra])
            sound.Text2Voice(eng[ra], 'en')
    print("test finished")
