from PyQt5.QtWidgets import QMainWindow
import GUI
import sys
from PyQt5.QtWidgets import QApplication
import sound
import random
import os
import time

class Main(QMainWindow, GUI.Ui_Dialog):
    def __init__(self):
        super(self.__class__, self).__init__()
        self.setupUi(self)
    def readtxt(self):
        chi = open("chi.txt",'r')
        eng = open("eng.txt",'r')
        chi = chi.readlines()
        eng = eng.readlines()
        for i in range(len(chi) - 1):
            chi[i] = chi[i][0:len(chi[i]) - 1]
        for i in range(len(eng) - 1):
            eng[i] = eng[i][0:len(eng[i]) - 1]
        return chi, eng
    def start(self, chi, eng):
        all_eng = len(eng)
        now_eng = len(eng)
        self.label_2.setText("%d / %d" %(now_eng, all_eng))
        self.label_3.setText("")
        self.label.setText("下載影音檔案:")
        self.check_down(eng)
    def check_down(self, eng):        
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
if __name__ == "__main__":
    app = QApplication(sys.argv)
    MainWindow = Main()
    MainWindow.show()
    chi,eng = MainWindow.readtxt()
    MainWindow.start(chi, eng)
    sys.exit(app.exec_())
    
