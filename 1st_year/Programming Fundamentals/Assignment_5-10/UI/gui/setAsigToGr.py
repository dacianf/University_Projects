# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'setAsigToGr.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_w_SetAsigToGr(object):
    def __init__(self, controller):
        self._ctr = controller

    def setupUi(self, w_SetAsigToGr):
        self.wid = w_SetAsigToGr
        w_SetAsigToGr.setObjectName("w_SetAsigToGr")
        w_SetAsigToGr.setWindowModality(QtCore.Qt.ApplicationModal)
        w_SetAsigToGr.resize(620, 105)
        w_SetAsigToGr.setMinimumSize(QtCore.QSize(0, 0))
        w_SetAsigToGr.setMaximumSize(QtCore.QSize(620, 240))
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(w_SetAsigToGr)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.splitter_2 = QtWidgets.QSplitter(w_SetAsigToGr)
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
        self.label_asID = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_asID.setFont(font)
        self.label_asID.setAlignment(QtCore.Qt.AlignCenter)
        self.label_asID.setObjectName("label_asID")
        self.verticalLayout_2.addWidget(self.label_asID)
        self.label_Group = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label_Group.setFont(font)
        self.label_Group.setAlignment(QtCore.Qt.AlignCenter)
        self.label_Group.setObjectName("label_Group")
        self.verticalLayout_2.addWidget(self.label_Group)
        self.horizontalLayout.addLayout(self.verticalLayout_2)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.lineEdit_asID = QtWidgets.QLineEdit(self.widget)
        self.lineEdit_asID.setMinimumSize(QtCore.QSize(311, 30))
        self.lineEdit_asID.setMaximumSize(QtCore.QSize(311, 30))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_asID.setFont(font)
        self.lineEdit_asID.setInputMask("")
        self.lineEdit_asID.setObjectName("lineEdit_asID")
        self.verticalLayout.addWidget(self.lineEdit_asID)
        self.lineEdit_gr = QtWidgets.QLineEdit(self.widget)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(16)
        self.lineEdit_gr.setFont(font)
        self.lineEdit_gr.setObjectName("lineEdit_gr")
        self.verticalLayout.addWidget(self.lineEdit_gr)
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

        self.retranslateUi(w_SetAsigToGr)
        QtCore.QMetaObject.connectSlotsByName(w_SetAsigToGr)

        self.events()

    def retranslateUi(self, w_SetAsigToGr):
        _translate = QtCore.QCoreApplication.translate
        w_SetAsigToGr.setWindowTitle(_translate("w_SetAsigToGr", "Set Assignment to Group"))
        self.label_asID.setText(_translate("w_SetAsigToGr", "Assignment\n"
"ID:"))
        self.label_Group.setText(_translate("w_SetAsigToGr", "Group:"))
        self.pushButton_AddAsig.setText(_translate("w_SetAsigToGr", "Add"))
        self.pushButton_Close.setText(_translate("w_SetAsigToGr", "Close"))

    def events(self):
        self.pushButton_AddAsig.clicked.connect(self.addAsig)
        self.pushButton_Close.clicked.connect(self.wid.close)

    def addAsig(self):
        try:
            asID = self.lineEdit_asID.text()
            if not asID.isnumeric():
                raise ValueError("ID must be a natural number!")
            asID = int(asID)
            x = self._ctr.assignment.findByID(asID)
            if type(x) == int:
                raise ValueError("There is no such an assignment!")
            gr = self.lineEdit_gr.text()
            students = self._ctr.student.getStudByGroup(gr)
            if len(students) == 0:
                raise ValueError("There is no student in this group!")
            self._ctr.giveAssigToGroup(asID, gr)
            self.createDialog("Assignment with ID: " + str(asID) + " was bounded to group " + gr, "Operation succeded!", QtWidgets.QMessageBox.Information)
            self.lineEdit_gr.setText("")
            self.lineEdit_asID.setText("")
        except Exception as err:
            self.createDialog(str(err), "Error!", QtWidgets.QMessageBox.Critical)

    def createDialog(self, err, title, iccon):
        qDial = QtWidgets.QMessageBox()
        qDial.setIcon(iccon)
        qDial.setText(err)
        qDial.setWindowTitle(title)
        qDial.exec_()
