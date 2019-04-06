from PyQt5.QtWidgets import QMainWindow
import GUI
import sys
from PyQt5.QtWidgets import QApplication
from PyQt5 import QtCore, QtGui, QtWidgets
import sound
import random
import os
import time

class Main(QMainWindow, GUI.Ui_GUI):
    def __init__(self):
        super(self.__class__, self).__init__()
        self.setupUi(self)
        self.start_flag = 0
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
    def start(self):
        self.chi, self.eng = self.readtxt()
        self.all_eng = len(self.eng)
        self.now_eng = 0
        self.label_2.setText("%d / %d" %(self.now_eng, self.all_eng))
        self.label.setText("下載影音檔案:")
        self.check_down()
        self.label_3.setText("")
        self.set_pro()
        self.start_flag = 1
        #self.pushButton
        self.pushButton.setGeometry(QtCore.QRect(0, 0, 0, 0))
    def reject(self):
        self.close()
    def set_pro(self):
        self.ra = random.randint(0, len(self.chi) - 1)
        self.label.setText(self.chi[self.ra] + '[' + str(self.eng[self.ra].count(' ') + 1) +']')
    def accept(self):
        if self.start_flag == 0 or len(self.eng) == 0:
            return
        print(self.lineEdit.text())
        if self.lineEdit.text() == self.eng[self.ra]:
            print("YES")
            self.label_3.setText("YES")
            sound.Text2Voice(self.eng[self.ra], 'en')
            self.chi.pop(self.ra)
            self.eng.pop(self.ra)
            self.now_eng += 1
        else:
            self.label_3.setText(self.eng[self.ra])
            sound.Text2Voice(self.eng[self.ra], 'en')
        self.lineEdit.setText('')
        self.label_2.setText("%d / %d" %(self.now_eng, self.all_eng))
        print(len(self.eng))
        if len(self.eng) == 0:
            self.label.setText("finish test")
            return
        self.ra = random.randint(0, len(self.chi) - 1)
        print(self.chi[self.ra] + '[' + str(self.eng[self.ra].count(' ') + 1) +']')
        self.label.setText(self.chi[self.ra] + '[' + str(self.eng[self.ra].count(' ') + 1) +']')
    def check_down(self):        
        print("下載影音檔案:")
        print("現在進度" + "0" + "%")
        self.label_3.setText("現在進度" + "0" + "%")
        if not os.path.isdir("./sound"):
            os.mkdir("./sound")
        os.chdir("./sound")
        sound_list = []
        for i in self.eng:
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
            self.label_3.setText("現在進度%.2f" % (now))
        if now != 100:
            print("現在進度" + "100" + "%")
            self.label_3.setText("現在進度" + "100" + "%")
        os.getcwd()
if __name__ == "__main__":
    app = QApplication(sys.argv)
    MainWindow = Main()
    MainWindow.show()
    chi,eng = MainWindow.readtxt()
    #MainWindow.start(chi, eng)
    sys.exit(app.exec_())
    
