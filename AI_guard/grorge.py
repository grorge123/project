import logging         # Error message
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters

logging.basicConfig()

user_sta = {}

updater = Updater("")

def img_opn(path, user_id) : # img processing
    global user_sta
    img.pro(path)
    img_str = pytesseract.image_to_string(Image.open('test_img.jpg'))
    print(img_str)
    if len(img_str) and user_sta[user_id] == 'calc' :
        ans = ari.al(img_str)
        return str(ans)
    elif len(img_str) and user_sta[user_id] == 'tran' :
        ans = tran(img_str)
        return str(ans)
    else :
        return "null"

def dl_image(bot, update) : 
    file = bot.getFile(update.message.photo[-1].file_id)
    file.download(file.file_path[86:])
    update.message.reply_text(str(img_opn(file.file_path[86:], update.message.from_user.id)))

def bot_help(bot, update):
    update.message.reply_text("Welecome to use the bot")

dp = updater.dispatcher
dp.add_handler(MessageHandler(Filters.photo, dl_image))
dp.add_handler(CommandHandler("start", bot_help))

updater.start_polling()
updater.idle()
