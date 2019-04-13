import pyglet
import time
from gtts import gTTS
import urllib.request
from urllib.request import quote
import os

def download_mp3(source_txt, language):
    if os.path.exists(source_txt+".mp3"):
        return source_txt+".mp3"
    else:
        #url = 'http://tts.baidu.com/text2audio?lan='+language+'&ie=UTF-8&text='+quote(source_txt)
        #request = urllib.request.Request(url)
        #response = urllib.request.urlopen(request)
        savePath = source_txt+'.mp3'
        #f = open(savePath,'wb')
        #f.write(response.read())
        #f.close()
        print(savePath)
        tts = gTTS(text = source_txt, lang=language)
        tts.save(savePath)
        return savePath
def exit_playaudio(audio):
    pyglet.app.exit()
def Text2Voice(source_txt, language):
    mp3_audio = download_mp3(source_txt, language)
    #time.sleep(3)
    music = pyglet.media.load(mp3_audio)
    music.play()
    pyglet.clock.schedule_once(exit_playaudio, music.duration)
    pyglet.app.run()

