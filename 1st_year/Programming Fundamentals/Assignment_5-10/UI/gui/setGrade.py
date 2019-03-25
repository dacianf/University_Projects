# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'setGrade.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_w_SetGrade(object):
    def __init__(self, controller):
        self._ctr = controller

    def setupUi(self, w_SetGrade):
        self.wid = w_SetGrade
        w_SetGrade.setObjectName("w_SetGrade")
        w_SetGrade.setWindowModality(QtCore.Qt.ApplicationModal)
        w_SetGrade.resize(620, 240)
        w_SetGrade.setMinimumSize(QtCore.QSize(580, 200))
        w_SetGrade.setMaximumSize(QtCore.QSize(620, 240))
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(w_SetGrade)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_ID = QtWidgets.QLabel(w_SetGrade)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_ID.setFont(font)
        self.label_ID.setObjectName("label_ID")
        self.horizontalLayout.addWidget(self.label_ID)
        spacerItem = QtWidgets.QSpacerItem(100, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.lineEdit_ID = QtWidgets.QLineEdit(w_SetGrade)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_ID.setFont(font)
        self.lineEdit_ID.setInputMask("")
        self.lineEdit_ID.setObjectName("lineEdit_ID")
        self.verticalLayout.addWidget(self.lineEdit_ID)
        self.verticalLayout_2.addLayout(self.verticalLayout)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_newGr = QtWidgets.QLabel(w_SetGrade)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_newGr.setFont(font)
        self.label_newGr.setObjectName("label_newGr")
        self.horizontalLayout_3.addWidget(self.label_newGr)
        spacerItem1 = QtWidgets.QSpacerItem(100, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem1)
        self.verticalLayout_2.addLayout(self.horizontalLayout_3)
        self.lineEdit_newGrade = QtWidgets.QLineEdit(w_SetGrade)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_newGrade.setFont(font)
        self.lineEdit_newGrade.setInputMask("")
        self.lineEdit_newGrade.setObjectName("lineEdit_newGrade")
        self.verticalLayout_2.addWidget(self.lineEdit_newGrade)
        self.horizontalLayout_4.addLayout(self.verticalLayout_2)
        spacerItem2 = QtWidgets.QSpacerItem(48, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_4.addItem(spacerItem2)
        self.listWidget = QtWidgets.QListWidget(w_SetGrade)
        self.listWidget.setObjectName("listWidget")
        self.horizontalLayout_4.addWidget(self.listWidget)
        self.verticalLayout_3.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        spacerItem3 = QtWidgets.QSpacerItem(20, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        self.horizontalLayout_5.addItem(spacerItem3)
        spacerItem4 = QtWidgets.QSpacerItem(400, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_5.addItem(spacerItem4)
        self.pushButton_findGrades = QtWidgets.QPushButton(w_SetGrade)
        self.pushButton_findGrades.setStyleSheet("background-color: lightgrey;\n"
"border: 1px solid black;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_findGrades.setObjectName("pushButton_findGrades")
        self.horizontalLayout_5.addWidget(self.pushButton_findGrades)
        self.verticalLayout_3.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        spacerItem5 = QtWidgets.QSpacerItem(300, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem5)
        self.pushButton_setGr = QtWidgets.QPushButton(w_SetGrade)
        self.pushButton_setGr.setStyleSheet("background-color: lightgrey;\n"
"border: 1px solid black;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_setGr.setObjectName("pushButton_setGr")
        self.horizontalLayout_2.addWidget(self.pushButton_setGr)
        self.pushButton_Close = QtWidgets.QPushButton(w_SetGrade)
        self.pushButton_Close.setStyleSheet("background-color: lightgrey;\n"
"border: 1px solid black;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_Close.setObjectName("pushButton_Close")
        self.horizontalLayout_2.addWidget(self.pushButton_Close)
        self.verticalLayout_3.addLayout(self.horizontalLayout_2)
        self.verticalLayout_4.addLayout(self.verticalLayout_3)

        self.retranslateUi(w_SetGrade)
        QtCore.QMetaObject.connectSlotsByName(w_SetGrade)

        self.events()

    def retranslateUi(self, w_SetGrade):
        _translate = QtCore.QCoreApplication.translate
        w_SetGrade.setWindowTitle(_translate("w_SetGrade", "Set Grade"))
        self.label_ID.setText(_translate("w_SetGrade", "ID: "))
        self.label_newGr.setText(_translate("w_SetGrade", "Grade:"))
        self.pushButton_findGrades.setText(_translate("w_SetGrade", "Find\n"
"grades"))
        self.pushButton_setGr.setText(_translate("w_SetGrade", "Set Grade"))
        self.pushButton_Close.setText(_translate("w_SetGrade", "Close"))

    def events(self):
        self.pushButton_Close.clicked.connect(self.wid.close)
        self.pushButton_findGrades.clicked.connect(self.listGr)
        self.pushButton_setGr.clicked.connect(self.settGR)

    def listGr(self):
        try:
            idS = self.lineEdit_ID.text()
            if not idS.isnumeric():
                raise ValueError("ID must be a natural number!")
            idS = int(idS)
            grades = self._ctr.getStudUngrade(idS)
            if grades == []:
                raise ValueError("There is no assignment bound to this student!")
            for gr in grades:
                self.listWidget.addItem(str(gr))
        except ValueError as er:
            self.createDialog(str(er), "Warning", QtWidgets.QMessageBox.Information)
        except Exception as er:
            self.createDialog(str(er), "Error", QtWidgets.QMessageBox.Critical)

    def settGR(self):
        gr = self.lineEdit_newGrade.text()
        try:
            try:
                gr = float(gr)
            except ValueError:
                raise ValueError("Grade must be a real number between 0 and 10!")
            if type(self.listWidget.currentItem()) != QtWidgets.QListWidgetItem:
                raise Exception("Please select a grade from the list!")
            strg = self.listWidget.currentItem().text()
            i = 0
            asID, i = self.findIdFromStr(strg, i)
            stID, i = self.findIdFromStr(strg, i)
            self._ctr.setGrade(int(stID), int(asID), gr)
            self.createDialog("Student with ID: " + stID + " was graded!", "Operation succeded!", QtWidgets.QMessageBox.Information)
            self.lineEdit_ID.setText("")
            self.lineEdit_newGrade.setText("")
            self.listWidget.clear()
        except Exception as er:
            self.createDialog(str(er), "Error", QtWidgets.QMessageBox.Critical)

    def createDialog(self, err, title, iccon):
        qDial = QtWidgets.QMessageBox()
        qDial.setIcon(iccon)
        qDial.setText(err)
        qDial.setWindowTitle(title)
        qDial.exec_()

    def findIdFromStr(self, strg, i):
        ind = ""
        while(not strg[i].isdigit()):
            i += 1
        while(strg[i].isdigit()):
            ind += strg[i]
            i += 1
        return ind, i
