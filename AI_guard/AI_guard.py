import logging         # Error message
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
import os
import cv2
import time
import json

logging.basicConfig()
user_sta = {}

with open("user.json", "r") as f:
    user_sta = json.load(f)
passwd = []
with open("passwd.txt", "r") as pas:
    for i in pas:
        passwd.append(i)
passwd = passwd[0].split(' ')

updater = Updater("959627051:AAFqoYga-LZi7fe_EHRhyg9of4MZGcP5u3o")

# def img_opn(path, user_id) : # img processing
#     global user_sta
#     img.pro(path)
#     img_str = pytesseract.image_to_string(Image.open('test_img.jpg'))
#     print(img_str)
#     if len(img_str) and user_sta[user_id] == 'calc' :
#         ans = ari.al(img_str)
#         return str(ans)
#     elif len(img_str) and user_sta[user_id] == 'tran' :
#         ans = tran(img_str)
#         return str(ans)
#     else :
#         return "null"

# def dl_image(bot, update) : 
#     file = bot.getFile(update.message.photo[-1].file_id)
#     file.download(file.file_path[86:])
#     update.message.reply_text(str(img_opn(file.file_path[86:], update.message.from_user.id)))

def check_time(now, check, time):
    later = now.copy()
    later[4] += time
    later[3] += int(later[4]/60)
    later[4] = later[4]%60
    later[2] += int(later[3]/24)
    later[3] = later[3]%24 
    for i in range(len(now)):
        if now[i]<check[i] or check[i] < later[i]:
            return True
        if now[i]>check[i] or check[i]>later[i]:
            print(i, now[i], check[i], later[i])
            return False
    if check[len(now)-1] == later[len(now)-1]:
        return False
    return True
def dl_text(bot, update):
    user_id = str(update.message.from_user.id)
    cmd = update.message.text.split(' ')
    path = ""
    if cmd[0] == "GET":
        if not (cmd[1] == "deal" or cmd[1] == "old"):
            update.message.reply_text("指令錯誤")
            return
        cmd[2] = cmd[2].split('-')
        if user_id in user_sta: 
            path = cmd[1] + '/' + user_sta[user_id]
        else:
            update.message.reply_text("尚未登入")
            return
        cmd[3] = int(cmd[3])
        for i in range(5):
            cmd[2][i] = int(cmd[2][i])
    elif cmd[0]=="LOGIN":
        if passwd.count(cmd[1]) == 0:
            update.message.reply_text("查無此人")
            return  
        else:
            
            user_sta[user_id] = cmd[1]
            with open("user.json", "w") as js:
                json.dump(user_sta, js)
            update.message.reply_text("登入成功")
            return
    else:
        update.message.reply_text("無此指令")
        return
    os.chdir(path)
    fps = 25
    now_page = 0
    fourcc = cv2.VideoWriter_fourcc(*'MP4V')
    videoWriter = cv2.VideoWriter("out.mp4",fourcc,fps,(960, 540))#最后一个是保存图片的尺寸
    number = 0
    for f in os.listdir("."):
        check = f[:f.find('.')].split('-')
        if check[0] == "out":
            continue
        for i in range(5):
            check[i] = int(check[i])
        if check_time(cmd[2], check, cmd[3]):
            number += 1
            vc = cv2.VideoCapture(f)
            rval = vc.isOpened()
            while rval and now_page<cmd[3]*25*60:
                rval, frame = vc.read()
                if frame is None:
                    break
                frame = cv2.resize(frame, (960, 540), interpolation=cv2.INTER_CUBIC)
                now_page += 1
                videoWriter.write(frame)
            vc.release()
            videoWriter.release()
    if number != 0:
        print("NUMBER:",number)
        update.message.reply_video(video = open('out.mp4', 'rb'),timeout=60000)
    else:
        print(number)
        update.message.reply_text("範圍內無紀錄")
    os.chdir("../")
    
def location(bot, update):
    user_id = str(update.message.from_user.id)
    cmd = update.message.text.split(' ')
    if len(cmd) == 1:
        update.message.reply_text("目前位置: \"台北市中山區松江路126號\"")
    else:
        update.message.reply_text("您在這段時間內從\"台北市 松山鎮, 南京東路三段253號\"移動到\"台北市中山區松江路126號\"")

def test(bot, update):
    time.sleep(5)
    update.message.reply_text("警告!!!系統檢測使用者行進時發生異常\n目前使用者正在:\"台北市中山區松江路126號\"\n請輸入以下指令:\n{}\n{}".format("/call 1 (聯絡預設聯絡人)","/call 2 (取消此次警告))"))

def call(bot, update):
    user_id = str(update.message.from_user.id)
    cmd = update.message.text.split(' ')
    update.message.reply_text("以依照您的操作進行處理!")

def bot_help(bot, update):
    update.message.reply_text("{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n".format("Welcom to use AI_guard"
                                                              , "指令教學:"
                                                              ,"LOGIN ID"
                                                              ,"登入ID的帳號"
                                                              ,"GET old year-month-day-hour-minute minute1"
                                                              ,"取得要求時間的原檔案並且播放minute1秒"
                                                              ,"GET deal year-month-day-hour-minute minute1"
                                                              ,"取得要求時間的辨識過檔案並且播放minute1分鐘"
                                                              ,"/location"
                                                              ,"取得使用者目前位置"
                                                              ,"/location year1-month1-day1-hour1-minute1 year2-month2-day2-hour2-minute2"
                                                              ,"取得使用者在兩段時間內的位置資訊"))

dp = updater.dispatcher
# dp.add_handler(MessageHandler(Filters.photo, dl_image))
dp.add_handler(MessageHandler(Filters.text, dl_text))
dp.add_handler(CommandHandler("start", bot_help))
dp.add_handler(CommandHandler("location", location))
dp.add_handler(CommandHandler("test", test))
dp.add_handler(CommandHandler("call",call))
updater.start_polling()
updater.idle()
