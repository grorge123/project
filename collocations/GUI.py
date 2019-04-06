# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'D:\桌面\GITHUB\project\collocations\main.ui'
#
# Created by: PyQt5 UI code generator 5.12.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_GUI(object):
    def setupUi(self, GUI):
        GUI.setObjectName("GUI")
        GUI.resize(805, 506)
        font = QtGui.QFont()
        font.setPointSize(15)
        GUI.setFont(font)
        self.buttonBox = QtWidgets.QDialogButtonBox(GUI)
        self.buttonBox.setGeometry(QtCore.QRect(390, 460, 351, 32))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.buttonBox.setFont(font)
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.label = QtWidgets.QLabel(GUI)
        self.label.setGeometry(QtCore.QRect(200, 120, 381, 71))
        font = QtGui.QFont()
        font.setFamily("標楷體")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setCursor(QtGui.QCursor(QtCore.Qt.IBeamCursor))
        self.label.setFocusPolicy(QtCore.Qt.NoFocus)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.lineEdit = QtWidgets.QLineEdit(GUI)
        self.lineEdit.setGeometry(QtCore.QRect(160, 320, 481, 41))
        self.lineEdit.setObjectName("lineEdit")
        #self.lineEdit.editingFinished.connect(self.accept)
        self.lineEdit.returnPressed.connect(self.accept)
        self.label_2 = QtWidgets.QLabel(GUI)
        self.label_2.setGeometry(QtCore.QRect(700, 20, 91, 21))
        font = QtGui.QFont()
        font.setFamily("Segoe Print")
        font.setPointSize(14)
        font.setKerning(False)
        self.label_2.setFont(font)
        self.label_2.setCursor(QtGui.QCursor(QtCore.Qt.IBeamCursor))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(GUI)
        self.label_3.setGeometry(QtCore.QRect(180, 250, 421, 41))
        font = QtGui.QFont()
        font.setFamily("Courier")
        self.label_3.setFont(font)
        self.label_3.setCursor(QtGui.QCursor(QtCore.Qt.IBeamCursor))
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.pushButton = QtWidgets.QPushButton(GUI)
        self.pushButton.setGeometry(QtCore.QRect(50, 460, 75, 23))
        font = QtGui.QFont()
        font.setPointSize(9)
        self.pushButton.setFont(font)
        self.pushButton.setObjectName("pushButton")

        self.retranslateUi(GUI)
        self.buttonBox.accepted.connect(GUI.accept)
        self.buttonBox.rejected.connect(GUI.reject)
        self.pushButton.clicked.connect(GUI.start)
        QtCore.QMetaObject.connectSlotsByName(GUI)
        self.setFixedSize(811, 529)
    def retranslateUi(self, GUI):
        _translate = QtCore.QCoreApplication.translate
        GUI.setWindowTitle(_translate("GUI", "collocations"))
        self.label.setText(_translate("GUI", "Welcome"))
        self.label_2.setText(_translate("GUI", "0/0"))
        self.label_3.setText(_translate("GUI", "collocations"))
        self.pushButton.setText(_translate("GUI", "start"))
