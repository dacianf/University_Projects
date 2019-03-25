# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'setAsigToSt.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_w_SetAsigToSt(object):
    def __init__(self, controller):
        self._ctr = controller

    def setupUi(self, w_SetAsigToSt):
        self.wid = w_SetAsigToSt
        w_SetAsigToSt.setObjectName("w_SetAsigToSt")
        w_SetAsigToSt.setWindowModality(QtCore.Qt.ApplicationModal)
        w_SetAsigToSt.resize(620, 105)
        w_SetAsigToSt.setMinimumSize(QtCore.QSize(0, 0))
        w_SetAsigToSt.setMaximumSize(QtCore.QSize(620, 240))
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(w_SetAsigToSt)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.splitter_2 = QtWidgets.QSplitter(w_SetAsigToSt)
        self.splitter_2.setOrientation(QtCore.Qt.Horizontal)
        self.splitter_2.setObjectName("splitter_2")
        self.widget = QtWidgets.QWidget(self.splitter_2)
        self.widget.setObjectName("widget")
        self.gridLayout = QtWidgets.QGridLayout(self.widget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.gridLayout.addLayout(self.verticalLayout_3, 0, 1, 1, 1)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setContentsMargins(30, -1, 15, -1)
        self.horizontalLayout.setSpacing(15)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_stID = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_stID.setFont(font)
        self.label_stID.setObjectName("label_stID")
        self.verticalLayout_2.addWidget(self.label_stID)
        self.label_AssID = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_AssID.setFont(font)
        self.label_AssID.setAlignment(QtCore.Qt.AlignCenter)
        self.label_AssID.setObjectName("label_AssID")
        self.verticalLayout_2.addWidget(self.label_AssID)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.lineEdit_stID = QtWidgets.QLineEdit(self.widget)
        self.lineEdit_stID.setMinimumSize(QtCore.QSize(311, 30))
        self.lineEdit_stID.setMaximumSize(QtCore.QSize(311, 30))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_stID.setFont(font)
        self.lineEdit_stID.setInputMask("")
        self.lineEdit_stID.setObjectName("lineEdit_stID")
        self.verticalLayout.addWidget(self.lineEdit_stID)
        self.lineEdit_asID = QtWidgets.QLineEdit(self.widget)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_asID.setFont(font)
        self.lineEdit_asID.setObjectName("lineEdit_asID")
        self.verticalLayout.addWidget(self.lineEdit_asID)
        self.horizontalLayout.addLayout(self.verticalLayout)
        self.gridLayout.addLayout(self.horizontalLayout, 0, 0, 1, 1)
        self.splitter = QtWidgets.QSplitter(self.splitter_2)
        self.splitter.setOrientation(QtCore.Qt.Vertical)
        self.splitter.setObjectName("splitter")
        self.pushButton_AddAsig = QtWidgets.QPushButton(self.splitter)
        self.pushButton_AddAsig.setStyleSheet("background-color: lightgrey;\n"
"border: 1px solid black;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_AddAsig.setObjectName("pushButton_AddAsig")
        self.pushButton_Close = QtWidgets.QPushButton(self.splitter)
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
        self.horizontalLayout_2.addWidget(self.splitter_2)

        self.retranslateUi(w_SetAsigToSt)
        QtCore.QMetaObject.connectSlotsByName(w_SetAsigToSt)

        self.events()

    def retranslateUi(self, w_SetAsigToSt):
        _translate = QtCore.QCoreApplication.translate
        w_SetAsigToSt.setWindowTitle(_translate("w_SetAsigToSt", "Set Assignment to Student"))
        self.label_stID.setText(_translate("w_SetAsigToSt", "Student ID:"))
        self.label_AssID.setText(_translate("w_SetAsigToSt", "Assignment\n"
"ID:"))
        self.pushButton_AddAsig.setText(_translate("w_SetAsigToSt", "Add"))
        self.pushButton_Close.setText(_translate("w_SetAsigToSt", "Close"))

    def events(self):
        self.pushButton_AddAsig.clicked.connect(self.addAsig)
        self.pushButton_Close.clicked.connect(self.wid.close)

    def addAsig(self):
        try:
            asID = self.lineEdit_asID.text()
            stID = self.lineEdit_stID.text()
            if not asID.isnumeric() or not stID.isnumeric():
                raise ValueError("ID must be a natural number!")
            asID = int(asID)
            stID = int(stID)
            x = self._ctr.assignment.findByID(asID)
            if type(x) == int:
                raise ValueError("There is no such an assignment!")
            x = self._ctr.assignment.findByID(stID)
            if type(x) == int:
                raise ValueError("There is no such a student!")
            self._ctr.setAssigStud(asID, stID)
            self.createDialog("Assignment with ID: " + str(asID) + " was bounded to student with ID: " + str(stID), "Operation succeded!", QtWidgets.QMessageBox.Information)
            self.lineEdit_stID.setText("")
            self.lineEdit_asID.setText("")
        except Exception as err:
            self.createDialog(str(err), "Error!", QtWidgets.QMessageBox.Critical)

    def createDialog(self, err, title, iccon):
        qDial = QtWidgets.QMessageBox()
        qDial.setIcon(iccon)
        qDial.setText(err)
        qDial.setWindowTitle(title)
        qDial.exec_()