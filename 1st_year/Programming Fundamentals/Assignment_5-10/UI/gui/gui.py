# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'GUI_assig5-8.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets
from functools import partial
from UI.gui.addSt import Ui_w_AddSt
from UI.gui.addAs import Ui_w_AddAs
from UI.gui.setGrade import Ui_w_SetGrade
from UI.gui.setAsigToGr import Ui_w_SetAsigToGr
from UI.gui.setAsigToSt import Ui_w_SetAsigToSt
from PyQt5.Qt import QAction


class Ui_StudentsManagement(QtWidgets.QMainWindow):

    def __init__(self, undoC, studC, assignC, gradeC, statistics):
        '''
            To create a CliMenu you need to provide:
                undoController
                studentController
                assignmentController
                gradeController
                statisticsClass
        '''
        self._undo = undoC
        self._stud = studC
        self._assign = assignC
        self._grade = gradeC
        self._stat = statistics

    def setupUi(self, StudentsManagement):
        StudentsManagement.setObjectName("StudentsManagement")
        StudentsManagement.resize(1010, 767)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(StudentsManagement.sizePolicy().hasHeightForWidth())
        StudentsManagement.setSizePolicy(sizePolicy)
        StudentsManagement.setMinimumSize(QtCore.QSize(0, 604))
        StudentsManagement.setMaximumSize(QtCore.QSize(16777215, 860))
        StudentsManagement.setStyleSheet("background-color: rgb(255, 248, 238);")
        self.centralwidget = QtWidgets.QWidget(StudentsManagement)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        spacerItem = QtWidgets.QSpacerItem(20, 18, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        self.gridLayout.addItem(spacerItem, 6, 0, 1, 2)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setSizeConstraint(QtWidgets.QLayout.SetFixedSize)
        self.horizontalLayout_2.setContentsMargins(30, -1, 30, -1)
        self.horizontalLayout_2.setSpacing(0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        spacerItem1 = QtWidgets.QSpacerItem(80, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem1)
        self.label_st_list = QtWidgets.QLabel(self.centralwidget)
        font = QtGui.QFont()
        font.setFamily("Monotype Corsiva")
        font.setPointSize(22)
        font.setBold(False)
        font.setItalic(True)
        font.setUnderline(False)
        font.setWeight(50)
        self.label_st_list.setFont(font)
        self.label_st_list.setObjectName("label_st_list")
        self.horizontalLayout_2.addWidget(self.label_st_list)
        spacerItem2 = QtWidgets.QSpacerItem(100, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem2)
        self.label_as_list = QtWidgets.QLabel(self.centralwidget)
        font = QtGui.QFont()
        font.setFamily("Monotype Corsiva")
        font.setPointSize(22)
        font.setBold(False)
        font.setItalic(True)
        font.setUnderline(False)
        font.setWeight(50)
        self.label_as_list.setFont(font)
        self.label_as_list.setObjectName("label_as_list")
        self.horizontalLayout_2.addWidget(self.label_as_list)
        spacerItem3 = QtWidgets.QSpacerItem(150, 20, QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem3)
        self.label_gr_list = QtWidgets.QLabel(self.centralwidget)
        font = QtGui.QFont()
        font.setFamily("Monotype Corsiva")
        font.setPointSize(22)
        font.setBold(False)
        font.setItalic(True)
        font.setUnderline(False)
        font.setWeight(50)
        self.label_gr_list.setFont(font)
        self.label_gr_list.setObjectName("label_gr_list")
        self.horizontalLayout_2.addWidget(self.label_gr_list)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSizeConstraint(QtWidgets.QLayout.SetFixedSize)
        self.horizontalLayout.setContentsMargins(30, -1, 30, -1)
        self.horizontalLayout.setSpacing(10)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.listWidget_Students = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget_Students.setStyleSheet("background-color: rgb(255, 255, 255);\n"
"border: 2px solid black;\n"
"font-family: Arial;\n"
"font-size: 12px;")
        self.listWidget_Students.setObjectName("listWidget_Students")
        self.horizontalLayout.addWidget(self.listWidget_Students)
        self.listWidget_Assignments = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget_Assignments.setStyleSheet("background-color: rgb(255, 255, 255);\n"
"border: 2px solid black;")
        self.listWidget_Assignments.setObjectName("listWidget_Assignments")
        self.horizontalLayout.addWidget(self.listWidget_Assignments)
        self.listWidget_Grade = QtWidgets.QListWidget(self.centralwidget)
        self.listWidget_Grade.setStyleSheet("background-color: rgb(255, 255, 255);\n"
"border: 2px solid black;")
        self.listWidget_Grade.setObjectName("listWidget_Grade")
        self.horizontalLayout.addWidget(self.listWidget_Grade)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.gridLayout.addLayout(self.verticalLayout, 0, 0, 1, 2)
        spacerItem4 = QtWidgets.QSpacerItem(20, 18, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        self.gridLayout.addItem(spacerItem4, 4, 0, 1, 2)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setContentsMargins(50, -1, 50, -1)
        self.horizontalLayout_3.setSpacing(50)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.splitter_3 = QtWidgets.QSplitter(self.centralwidget)
        self.splitter_3.setOrientation(QtCore.Qt.Horizontal)
        self.splitter_3.setObjectName("splitter_3")
        self.splitter = QtWidgets.QSplitter(self.splitter_3)
        self.splitter.setOrientation(QtCore.Qt.Vertical)
        self.splitter.setObjectName("splitter")
        self.pushButton_addStud = QtWidgets.QPushButton(self.splitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_addStud.sizePolicy().hasHeightForWidth())
        self.pushButton_addStud.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_addStud.setFont(font)
        self.pushButton_addStud.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_addStud.setObjectName("pushButton_addStud")
        self.pushButton_UpdSt = QtWidgets.QPushButton(self.splitter)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_UpdSt.sizePolicy().hasHeightForWidth())
        self.pushButton_UpdSt.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_UpdSt.setFont(font)
        self.pushButton_UpdSt.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_UpdSt.setObjectName("pushButton_UpdSt")
        self.splitter_2 = QtWidgets.QSplitter(self.splitter_3)
        self.splitter_2.setOrientation(QtCore.Qt.Vertical)
        self.splitter_2.setObjectName("splitter_2")
        self.pushButton_RmvSt = QtWidgets.QPushButton(self.splitter_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_RmvSt.sizePolicy().hasHeightForWidth())
        self.pushButton_RmvSt.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_RmvSt.setFont(font)
        self.pushButton_RmvSt.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_RmvSt.setObjectName("pushButton_RmvSt")
        self.pushButton_listSt = QtWidgets.QPushButton(self.splitter_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_listSt.sizePolicy().hasHeightForWidth())
        self.pushButton_listSt.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_listSt.setFont(font)
        self.pushButton_listSt.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_listSt.setObjectName("pushButton_listSt")
        self.horizontalLayout_3.addWidget(self.splitter_3)
        self.splitter_6 = QtWidgets.QSplitter(self.centralwidget)
        self.splitter_6.setOrientation(QtCore.Qt.Horizontal)
        self.splitter_6.setObjectName("splitter_6")
        self.splitter_4 = QtWidgets.QSplitter(self.splitter_6)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.splitter_4.sizePolicy().hasHeightForWidth())
        self.splitter_4.setSizePolicy(sizePolicy)
        self.splitter_4.setOrientation(QtCore.Qt.Vertical)
        self.splitter_4.setObjectName("splitter_4")
        self.pushButton_addAsig = QtWidgets.QPushButton(self.splitter_4)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_addAsig.sizePolicy().hasHeightForWidth())
        self.pushButton_addAsig.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_addAsig.setFont(font)
        self.pushButton_addAsig.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_addAsig.setObjectName("pushButton_addAsig")
        self.pushButton_UpdAs = QtWidgets.QPushButton(self.splitter_4)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_UpdAs.sizePolicy().hasHeightForWidth())
        self.pushButton_UpdAs.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_UpdAs.setFont(font)
        self.pushButton_UpdAs.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_UpdAs.setObjectName("pushButton_UpdAs")
        self.splitter_5 = QtWidgets.QSplitter(self.splitter_6)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.splitter_5.sizePolicy().hasHeightForWidth())
        self.splitter_5.setSizePolicy(sizePolicy)
        self.splitter_5.setOrientation(QtCore.Qt.Vertical)
        self.splitter_5.setObjectName("splitter_5")
        self.pushButton_RmvAs = QtWidgets.QPushButton(self.splitter_5)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_RmvAs.sizePolicy().hasHeightForWidth())
        self.pushButton_RmvAs.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_RmvAs.setFont(font)
        self.pushButton_RmvAs.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_RmvAs.setObjectName("pushButton_RmvAs")
        self.pushButton_listAs = QtWidgets.QPushButton(self.splitter_5)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_listAs.sizePolicy().hasHeightForWidth())
        self.pushButton_listAs.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_listAs.setFont(font)
        self.pushButton_listAs.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_listAs.setObjectName("pushButton_listAs")
        self.horizontalLayout_3.addWidget(self.splitter_6)
        self.splitter_9 = QtWidgets.QSplitter(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.splitter_9.sizePolicy().hasHeightForWidth())
        self.splitter_9.setSizePolicy(sizePolicy)
        self.splitter_9.setOrientation(QtCore.Qt.Horizontal)
        self.splitter_9.setObjectName("splitter_9")
        self.splitter_7 = QtWidgets.QSplitter(self.splitter_9)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.splitter_7.sizePolicy().hasHeightForWidth())
        self.splitter_7.setSizePolicy(sizePolicy)
        self.splitter_7.setOrientation(QtCore.Qt.Vertical)
        self.splitter_7.setObjectName("splitter_7")
        self.pushButton_addAsigToSt = QtWidgets.QPushButton(self.splitter_7)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_addAsigToSt.sizePolicy().hasHeightForWidth())
        self.pushButton_addAsigToSt.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_addAsigToSt.setFont(font)
        self.pushButton_addAsigToSt.setContextMenuPolicy(QtCore.Qt.CustomContextMenu)
        self.pushButton_addAsigToSt.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.pushButton_addAsigToSt.setAutoFillBackground(False)
        self.pushButton_addAsigToSt.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_addAsigToSt.setIconSize(QtCore.QSize(40, 40))
        self.pushButton_addAsigToSt.setAutoDefault(False)
        self.pushButton_addAsigToSt.setObjectName("pushButton_addAsigToSt")
        self.pushButton_addAsigToGr = QtWidgets.QPushButton(self.splitter_7)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_addAsigToGr.sizePolicy().hasHeightForWidth())
        self.pushButton_addAsigToGr.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_addAsigToGr.setFont(font)
        self.pushButton_addAsigToGr.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_addAsigToGr.setObjectName("pushButton_addAsigToGr")
        self.splitter_8 = QtWidgets.QSplitter(self.splitter_9)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.splitter_8.sizePolicy().hasHeightForWidth())
        self.splitter_8.setSizePolicy(sizePolicy)
        self.splitter_8.setOrientation(QtCore.Qt.Vertical)
        self.splitter_8.setObjectName("splitter_8")
        self.pushButton_SetGr = QtWidgets.QPushButton(self.splitter_8)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_SetGr.sizePolicy().hasHeightForWidth())
        self.pushButton_SetGr.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_SetGr.setFont(font)
        self.pushButton_SetGr.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_SetGr.setObjectName("pushButton_SetGr")
        self.pushButton_listGr = QtWidgets.QPushButton(self.splitter_8)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_listGr.sizePolicy().hasHeightForWidth())
        self.pushButton_listGr.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(-1)
        font.setUnderline(False)
        font.setStrikeOut(False)
        self.pushButton_listGr.setFont(font)
        self.pushButton_listGr.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_listGr.setObjectName("pushButton_listGr")
        self.horizontalLayout_3.addWidget(self.splitter_9)
        self.gridLayout.addLayout(self.horizontalLayout_3, 2, 0, 2, 2)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setContentsMargins(100, -1, 100, -1)
        self.horizontalLayout_4.setSpacing(250)
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.splitter_11 = QtWidgets.QSplitter(self.centralwidget)
        self.splitter_11.setOrientation(QtCore.Qt.Horizontal)
        self.splitter_11.setObjectName("splitter_11")
        self.pushButton_statStGivAs = QtWidgets.QPushButton(self.splitter_11)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_statStGivAs.sizePolicy().hasHeightForWidth())
        self.pushButton_statStGivAs.setSizePolicy(sizePolicy)
        self.pushButton_statStGivAs.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_statStGivAs.setObjectName("pushButton_statStGivAs")
        self.pushButton_statLateSt = QtWidgets.QPushButton(self.splitter_11)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_statLateSt.sizePolicy().hasHeightForWidth())
        self.pushButton_statLateSt.setSizePolicy(sizePolicy)
        self.pushButton_statLateSt.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_statLateSt.setObjectName("pushButton_statLateSt")
        self.horizontalLayout_4.addWidget(self.splitter_11)
        self.splitter_10 = QtWidgets.QSplitter(self.centralwidget)
        self.splitter_10.setOrientation(QtCore.Qt.Horizontal)
        self.splitter_10.setObjectName("splitter_10")
        self.pushButton_statBestSit = QtWidgets.QPushButton(self.splitter_10)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_statBestSit.sizePolicy().hasHeightForWidth())
        self.pushButton_statBestSit.setSizePolicy(sizePolicy)
        self.pushButton_statBestSit.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;")
        self.pushButton_statBestSit.setObjectName("pushButton_statBestSit")
        self.pushButton_statAllGradedAsig = QtWidgets.QPushButton(self.splitter_10)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pushButton_statAllGradedAsig.sizePolicy().hasHeightForWidth())
        self.pushButton_statAllGradedAsig.setSizePolicy(sizePolicy)
        self.pushButton_statAllGradedAsig.setStyleSheet("background-color: #ffb162;\n"
"border: 1px solid #684a25;\n"
"color: black;\n"
"padding: 5px;\n"
"text-align: center;\n"
"text-decoration: none;\n"
"display: inline-block;\n"
"font-size: 16px;\n"
"cursor: pointer;\n"
"border-radius: 8px;\n"
"hover\n"
"{\n"
"  border: 1px solid red;\n"
"}")
        self.pushButton_statAllGradedAsig.setObjectName("pushButton_statAllGradedAsig")
        self.horizontalLayout_4.addWidget(self.splitter_10)
        self.gridLayout.addLayout(self.horizontalLayout_4, 5, 0, 1, 2)
        spacerItem5 = QtWidgets.QSpacerItem(20, 10, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        self.gridLayout.addItem(spacerItem5, 1, 0, 1, 2)
        self.gridLayout_2.addLayout(self.gridLayout, 0, 0, 1, 1)
        StudentsManagement.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(StudentsManagement)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1010, 21))
        self.menubar.setStyleSheet("background-color: rgb(230, 224, 215);")
        self.menubar.setObjectName("menubar")
        StudentsManagement.setMenuBar(self.menubar)

        self.undoAct = QAction("Undo")
        self.undoAct.setShortcut('Ctrl+Z')
        self.undoAct.triggered.connect(partial(self.doUndo))
        self.menubar.addAction(self.undoAct)

        self.redoAct = QAction("Redo")
        self.redoAct.setShortcut('Ctrl+Y')
        self.redoAct.triggered.connect(partial(self.doRedo))
        self.menubar.addAction(self.redoAct)

        self.retranslateUi(StudentsManagement)
        QtCore.QMetaObject.connectSlotsByName(StudentsManagement)
        self.events()

    def retranslateUi(self, StudentsManagement):
        _translate = QtCore.QCoreApplication.translate
        StudentsManagement.setWindowTitle(_translate("StudentsManagement", "MainWindow"))
        self.label_st_list.setText(_translate("StudentsManagement", "Students list"))
        self.label_as_list.setText(_translate("StudentsManagement", "Assignments list"))
        self.label_gr_list.setText(_translate("StudentsManagement", "Grades list"))
        self.pushButton_addStud.setText(_translate("StudentsManagement", "Add Student"))
        self.pushButton_UpdSt.setText(_translate("StudentsManagement", "Update Student"))
        self.pushButton_RmvSt.setText(_translate("StudentsManagement", "Remove Student"))
        self.pushButton_listSt.setText(_translate("StudentsManagement", "List Students"))
        self.pushButton_addAsig.setText(_translate("StudentsManagement", "Add Assignment"))
        self.pushButton_UpdAs.setText(_translate("StudentsManagement", "Update Assignment"))
        self.pushButton_RmvAs.setText(_translate("StudentsManagement", "Remove Assignment"))
        self.pushButton_listAs.setText(_translate("StudentsManagement", "List Assignments"))
        self.pushButton_addAsigToSt.setText(_translate("StudentsManagement", "Add Assignment\n"
"to Student"))
        self.pushButton_addAsigToGr.setText(_translate("StudentsManagement", "Add Assignment\n"
"to Grop"))
        self.pushButton_SetGr.setText(_translate("StudentsManagement", "Set Grade"))
        self.pushButton_listGr.setText(_translate("StudentsManagement", "List Grades"))
        self.pushButton_statStGivAs.setText(_translate("StudentsManagement", "Students who\n"
"received a given\n"
" assignment"))
        self.pushButton_statLateSt.setText(_translate("StudentsManagement", "Students who\n"
"are late with\n"
"assignments"))
        self.pushButton_statBestSit.setText(_translate("StudentsManagement", "Students with\n"
"best school\n"
"situation"))
        self.pushButton_statAllGradedAsig.setText(_translate("StudentsManagement", "All assignments\n"
"graded"))

    def events(self):
        self.pushButton_listSt.clicked.connect(partial(self.listObj, self._stud, self.listWidget_Students))
        self.pushButton_listGr.clicked.connect(partial(self.listObj, self._grade, self.listWidget_Grade))
        self.pushButton_listAs.clicked.connect(partial(self.listObj, self._assign, self.listWidget_Assignments))
        self.pushButton_addStud.clicked.connect(partial(self.openWindow, Ui_w_AddSt, self._grade))
        self.pushButton_addAsig.clicked.connect(partial(self.openWindow, Ui_w_AddAs, self._grade))
        self.pushButton_RmvSt.clicked.connect(partial(self.rmvSt, self.listWidget_Students.currentItem, self._grade.removeStud))
        self.pushButton_RmvAs.clicked.connect(partial(self.rmvAs, self.listWidget_Assignments.currentItem, self._grade.removeAssign))
        self.pushButton_UpdSt.clicked.connect(partial(self.openUpdateSt))
        self.pushButton_UpdAs.clicked.connect(partial(self.openUpdateAs))
        self.pushButton_SetGr.clicked.connect(partial(self.openWindow, Ui_w_SetGrade, self._grade))
        self.pushButton_addAsigToGr.clicked.connect(partial(self.openWindow, Ui_w_SetAsigToGr, self._grade))
        self.pushButton_addAsigToSt.clicked.connect(partial(self.openWindow, Ui_w_SetAsigToSt, self._grade))
        self.pushButton_statAllGradedAsig.clicked.connect(partial(self.statAllGradedAsig))
        self.pushButton_statBestSit.clicked.connect(partial(self.statBestSit))
        self.pushButton_statLateSt.clicked.connect(partial(self.statLateSt))
        self.pushButton_statStGivAs.clicked.connect(partial(self.statStGivAs))

    def listObj(self, obj, listW):
        listW.clear()
        for ob in obj.getAll():
            listW.addItem(str(ob))

    def rmv(self, selected, rmvFunc):
        selected = selected()
        if type(selected) != QtWidgets.QListWidgetItem:
            raise Exception("Plese select a student from the list!")
        strg = selected.text().strip()
        ind = ""
        i = 0
        while(not strg[i].isdigit()):
            i += 1
        while(strg[i].isdigit()):
            ind += strg[i]
            i += 1
        rmvFunc(int(ind))

    def rmvSt(self, selected, rmvFunc):
        try:
            self.rmv(selected, rmvFunc)
            self.createDialog("Student was removed!", "Operation succeded!", QtWidgets.QMessageBox.Information)
            self.refreshLists()
        except Exception as err:
            self.createDialog(str(err), "Error!", QtWidgets.QMessageBox.Critical)

    def rmvAs(self, selected, rmvFunc):
        try:
            self.rmv(selected, rmvFunc)
            self.createDialog("Assignment was removed!", "Operation succeded!", QtWidgets.QMessageBox.Information)
            self.refreshLists()
        except Exception as err:
            self.createDialog(str(err), "Error!", QtWidgets.QMessageBox.Critical)

    def openWindow(self, window, ctr):
        self.window = QtWidgets.QDialog()
        self.ui = window(ctr)
        self.ui.setupUi(self.window)
        self.window.show()

    def openUpdateSt(self):
        self.window = QtWidgets.QDialog()
        self.ui = Ui_w_AddSt(self._stud)
        self.ui.setupUi(self.window)
        self.ui.changeWindowName(self.window, "UpdateStudent")
        self.ui.changeAddBut("Update")
        self.window.show()

    def openUpdateAs(self):
        self.window = QtWidgets.QDialog()
        self.ui = Ui_w_AddAs(self._assign)
        self.ui.setupUi(self.window)
        self.ui.changeWindowName(self.window, "UpdateAssignment")
        self.ui.changeAddBut("Update")
        self.window.show()

    def createDialog(self, err, title, iccon):
        qDial = QtWidgets.QMessageBox()
        qDial.setIcon(iccon)
        qDial.setText(err)
        qDial.setWindowTitle(title)
        qDial.exec_()

    def doUndo(self):
        try:
            self._undo.undo()
            self.refreshLists()
        except Exception as err:
            self.createDialog(str(err), "Warning!", QtWidgets.QMessageBox.Information)

    def doRedo(self):
        try:
            self._undo.redo()
            self.refreshLists()
        except Exception as err:
            self.createDialog(str(err), "Warning!", QtWidgets.QMessageBox.Information)

    def statAllGradedAsig(self):
        try:
            x = self._stat.getAssigByGrade()
            if len(x) > 0:
                strg = "All students who received a given assignment, ordered alphabetically or\nby average grade for that assignment\n"
                for i in x:
                    strg += str(i) + "\n"
                x = ScrollMessageBox(QtWidgets.QMessageBox.Information, "Students which received an assignment!", strg)
            else:
                raise Exception("No student satisffies this condition!")
        except Exception as err:
            self.createDialog(str(err), "Warning!", QtWidgets.QMessageBox.Information)

    def statBestSit(self):
        try:
            x = self._stat.getStudBestGrSchool()
            if len(x) > 0:
                strg = "Students with the best school situation, sorted in descending order of the average grade received for all assignments\n"
                for i in x:
                    strg += str(i) + "\n"
                x = ScrollMessageBox(QtWidgets.QMessageBox.Information, "Students with bests results!", strg)
            else:
                raise Exception("No student satisffies this condition!")
        except Exception as err:
            self.createDialog(str(err), "Warning!", QtWidgets.QMessageBox.Information)

    def statLateSt(self):
        try:
            x = self._stat.getLateStuds()
            if len(x) > 0:
                strg = "All students who are late in handing in at least one assignment.\nThese are all the students who have an ungraded assignment for which the deadline has passed\n"
                for i in x:
                    strg += str(i) + "\n"
                x = ScrollMessageBox(QtWidgets.QMessageBox.Information, "Students who are late!", strg)
            else:
                raise Exception("No student satisffies this condition!")
        except Exception as err:
            self.createDialog(str(err), "Warning!", QtWidgets.QMessageBox.Information)

    def statStGivAs(self):
        try:
            x = self.listWidget_Assignments.currentItem()
            if type(x) != QtWidgets.QListWidgetItem:
                raise Exception("Plese select the assignment from the list!")
            strg = x.text()
            aID = ""
            i = 0
            while(not strg[i].isdigit() and i < len(strg)):
                i += 1
            while(strg[i].isdigit() and i < len(strg)):
                aID += strg[i]
                i += 1
            aID = int(aID)
            x = self._stat.getStudGivenAssig(aID)
            if len(x) > 0:
                strg = "All students who received a given assignment, ordered alphabetically or by average grade for that assignment\n"
                for i in x:
                    strg += str(i) + "\n"
                x = ScrollMessageBox(QtWidgets.QMessageBox.Information, "Students who received the assignment with id " + str(aID), strg)
            else:
                raise Exception("No student satisffies this condition!")
        except Exception as err:
            self.createDialog(str(err), "Warning!", QtWidgets.QMessageBox.Information)

    def refreshLists(self):
        self.listObj(self._stud, self.listWidget_Students)
        self.listObj(self._grade, self.listWidget_Grade)
        self.listObj(self._assign, self.listWidget_Assignments)


class ScrollMessageBox(QtWidgets.QMessageBox):
    def __init__(self, *args, **kwargs):
        QtWidgets.QMessageBox.__init__(self, *args, **kwargs)
        chldn = self.children()
        scrll = QtWidgets.QScrollArea(self)
        scrll.setWidgetResizable(True)
        grd = self.findChild(QtWidgets.QGridLayout)
        lbl = QtWidgets.QLabel(chldn[1].text(), self)
        lbl.setWordWrap(True)
        scrll.setWidget(lbl)
        scrll.setMinimumSize(500, 300)
        grd.addWidget(scrll, 0, 1)
        chldn[1].setText('')
        self.exec_()
