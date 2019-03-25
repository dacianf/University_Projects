# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'addStudent.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets
from domain.student import Student
from functools import partial


class Ui_w_AddSt(object):
    def __init__(self, controller):
        self._ctr = controller

    def setupUi(self, w_AddAs):
        self.wid = w_AddAs
        w_AddAs.setObjectName("w_AddAs")
        w_AddAs.setWindowModality(QtCore.Qt.ApplicationModal)
        w_AddAs.resize(580, 200)
        w_AddAs.setMinimumSize(QtCore.QSize(580, 200))
        w_AddAs.setMaximumSize(QtCore.QSize(620, 240))
        self.gridLayout_2 = QtWidgets.QGridLayout(w_AddAs)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        spacerItem = QtWidgets.QSpacerItem(20, 13, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        self.gridLayout.addItem(spacerItem, 0, 0, 1, 1)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setContentsMargins(30, -1, 15, -1)
        self.horizontalLayout.setSpacing(15)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_ID = QtWidgets.QLabel(w_AddAs)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_ID.setFont(font)
        self.label_ID.setObjectName("label_ID")
        self.verticalLayout_2.addWidget(self.label_ID)
        self.label_Name = QtWidgets.QLabel(w_AddAs)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_Name.setFont(font)
        self.label_Name.setObjectName("label_Name")
        self.verticalLayout_2.addWidget(self.label_Name)
        self.label_Group = QtWidgets.QLabel(w_AddAs)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_Group.setFont(font)
        self.label_Group.setObjectName("label_Group")
        self.verticalLayout_2.addWidget(self.label_Group)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.lineEdit_ID = QtWidgets.QLineEdit(w_AddAs)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_ID.setFont(font)
        self.lineEdit_ID.setInputMask("")
        self.lineEdit_ID.setObjectName("lineEdit_ID")
        self.verticalLayout.addWidget(self.lineEdit_ID)
        self.lineEdit_Name = QtWidgets.QLineEdit(w_AddAs)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_Name.setFont(font)
        self.lineEdit_Name.setInputMask("")
        self.lineEdit_Name.setObjectName("lineEdit_Name")
        self.verticalLayout.addWidget(self.lineEdit_Name)
        self.lineEdit_Group = QtWidgets.QLineEdit(w_AddAs)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_Group.setFont(font)
        self.lineEdit_Group.setObjectName("lineEdit_Group")
        self.verticalLayout.addWidget(self.lineEdit_Group)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.gridLayout.addLayout(self.horizontalLayout, 1, 0, 1, 1)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        spacerItem1 = QtWidgets.QSpacerItem(300, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem1)
        self.pushButton_AddSt = QtWidgets.QPushButton(w_AddAs)
        self.pushButton_AddSt.setStyleSheet("background-color: lightgrey;\n"
"border: 1px solid black;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_AddSt.setObjectName("pushButton_AddSt")
        self.horizontalLayout_2.addWidget(self.pushButton_AddSt)
        self.pushButton_Close = QtWidgets.QPushButton(w_AddAs)
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
        self.gridLayout.addLayout(self.horizontalLayout_2, 2, 0, 1, 1)
        spacerItem2 = QtWidgets.QSpacerItem(20, 13, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        self.gridLayout.addItem(spacerItem2, 3, 0, 1, 1)
        self.gridLayout_2.addLayout(self.gridLayout, 0, 0, 1, 1)

        self.retranslateUi(w_AddAs)
        QtCore.QMetaObject.connectSlotsByName(w_AddAs)

        self.events(w_AddAs)

    def retranslateUi(self, w_AddSt):
        _translate = QtCore.QCoreApplication.translate
        w_AddSt.setWindowTitle(_translate("w_AddSt", "AddStudent"))
        self.label_ID.setText(_translate("w_AddSt", "ID: "))
        self.label_Name.setText(_translate("w_AddSt", "Name:"))
        self.label_Group.setText(_translate("w_AddSt", "Group:"))
        self.pushButton_AddSt.setText(_translate("w_AddSt", "Add"))
        self.pushButton_Close.setText(_translate("w_AddSt", "Close"))

    def events(self, w_AddSt):
        self.pushButton_AddSt.clicked.connect(self.addSt)
        self.pushButton_Close.clicked.connect(w_AddSt.close)

    def addSt(self):
        idS = self.lineEdit_ID.text().strip()
        name = self.lineEdit_Name.text().strip()
        group = self.lineEdit_Group.text().strip()
        if self.wid.windowTitle() == "AddStudent":
            cmd = self._ctr.student.add
        else:
            cmd = self._ctr.update
        try:
            if idS.isnumeric():
                idS = int(idS)
            else:
                raise ValueError("ID must be a natural number!")
            cmd(Student(idS, name, group))
            self.lineEdit_ID.setText("")
            self.lineEdit_Name.setText("")
            self.lineEdit_Group.setText("")
            self.createDialog("Student with Name: " + name + " and ID: " + str(idS) + " was successfully added!", "Operation succeded!", QtWidgets.QMessageBox.Information)
        except Exception as er:
            self.createDialog(str(er), "Error!", QtWidgets.QMessageBox.Critical)

    def changeWindowName(self, window, text):
        _translate = QtCore.QCoreApplication.translate
        window.setWindowTitle(_translate("w_AddSt", text))

    def changeAddBut(self, text):
        _translate = QtCore.QCoreApplication.translate
        self.pushButton_AddSt.setText(_translate("w_AddSt", text))

    def createDialog(self, err, title, iccon):
        qDial = QtWidgets.QMessageBox()
        qDial.setIcon(iccon)
        qDial.setText(err)
        qDial.setWindowTitle(title)
        qDial.exec_()
