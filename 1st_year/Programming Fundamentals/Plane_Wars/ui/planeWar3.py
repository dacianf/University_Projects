# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'planeWar.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 517)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setMinimumSize(QtCore.QSize(800, 517))
        MainWindow.setMaximumSize(QtCore.QSize(800, 517))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.playerBoard = QtWidgets.QTableWidget(self.centralwidget)
        self.playerBoard.setEnabled(True)
        self.playerBoard.setGeometry(QtCore.QRect(10, 30, 362, 362))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(100)
        sizePolicy.setVerticalStretch(100)
        sizePolicy.setHeightForWidth(self.playerBoard.sizePolicy().hasHeightForWidth())
        self.playerBoard.setSizePolicy(sizePolicy)
        self.playerBoard.setMinimumSize(QtCore.QSize(362, 362))
        self.playerBoard.setMaximumSize(QtCore.QSize(497, 497))
        self.playerBoard.setContextMenuPolicy(QtCore.Qt.NoContextMenu)
        self.playerBoard.setAutoScroll(False)
        self.playerBoard.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)
        self.playerBoard.setTabKeyNavigation(False)
        self.playerBoard.setProperty("showDropIndicator", False)
        self.playerBoard.setDragDropOverwriteMode(False)
        self.playerBoard.setAlternatingRowColors(False)
        self.playerBoard.setSelectionMode(QtWidgets.QAbstractItemView.NoSelection)
        self.playerBoard.setIconSize(QtCore.QSize(5, 5))
        self.playerBoard.setGridStyle(QtCore.Qt.SolidLine)
        self.playerBoard.setWordWrap(False)
        self.playerBoard.setCornerButtonEnabled(False)
        self.playerBoard.setRowCount(9)
        self.playerBoard.setColumnCount(9)
        self.playerBoard.setObjectName("playerBoard")
        item = QtWidgets.QTableWidgetItem()
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 0))
        brush.setStyle(QtCore.Qt.NoBrush)
        item.setBackground(brush)
        item.setFlags(QtCore.Qt.NoItemFlags)
        self.playerBoard.setItem(0, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 1, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 2, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 3, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 4, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 5, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 6, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 7, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(0, 8, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(1, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(2, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(3, 0, item)
        item = QtWidgets.QTableWidgetItem()
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 0, 0))
        brush.setStyle(QtCore.Qt.SolidPattern)
        item.setBackground(brush)
        brush = QtGui.QBrush(QtGui.QColor(234, 42, 23, 34))
        brush.setStyle(QtCore.Qt.NoBrush)
        item.setForeground(brush)
        self.playerBoard.setItem(3, 1, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(4, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(5, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(6, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(7, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.playerBoard.setItem(8, 0, item)
        self.playerBoard.horizontalHeader().setVisible(False)
        self.playerBoard.horizontalHeader().setDefaultSectionSize(40)
        self.playerBoard.horizontalHeader().setHighlightSections(False)
        self.playerBoard.horizontalHeader().setMinimumSectionSize(10)
        self.playerBoard.verticalHeader().setVisible(False)
        self.playerBoard.verticalHeader().setDefaultSectionSize(40)
        self.playerBoard.verticalHeader().setHighlightSections(False)
        self.playerBoard.verticalHeader().setMinimumSectionSize(10)
        self.aiBoard = QtWidgets.QTableWidget(self.centralwidget)
        self.aiBoard.setGeometry(QtCore.QRect(420, 30, 362, 362))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(100)
        sizePolicy.setVerticalStretch(100)
        sizePolicy.setHeightForWidth(self.aiBoard.sizePolicy().hasHeightForWidth())
        self.aiBoard.setSizePolicy(sizePolicy)
        self.aiBoard.setMinimumSize(QtCore.QSize(362, 362))
        self.aiBoard.setMaximumSize(QtCore.QSize(497, 497))
        self.aiBoard.setContextMenuPolicy(QtCore.Qt.NoContextMenu)
        self.aiBoard.setEditTriggers(QtWidgets.QAbstractItemView.SelectedClicked)
        self.aiBoard.setTabKeyNavigation(False)
        self.aiBoard.setProperty("showDropIndicator", False)
        self.aiBoard.setAlternatingRowColors(False)
        self.aiBoard.setSelectionMode(QtWidgets.QAbstractItemView.SingleSelection)
        self.aiBoard.setIconSize(QtCore.QSize(5, 5))
        self.aiBoard.setGridStyle(QtCore.Qt.SolidLine)
        self.aiBoard.setWordWrap(False)
        self.aiBoard.setCornerButtonEnabled(False)
        self.aiBoard.setRowCount(9)
        self.aiBoard.setColumnCount(9)
        self.aiBoard.setObjectName("aiBoard")
        item = QtWidgets.QTableWidgetItem()
        brush = QtGui.QBrush(QtGui.QColor(0, 0, 0))
        brush.setStyle(QtCore.Qt.NoBrush)
        item.setBackground(brush)
        item.setFlags(QtCore.Qt.ItemIsSelectable|QtCore.Qt.ItemIsDragEnabled)
        self.aiBoard.setItem(0, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 1, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 2, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 3, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 4, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 5, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 6, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 7, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(0, 8, item)
        item = QtWidgets.QTableWidgetItem()
        item.setTextAlignment(QtCore.Qt.AlignCenter)
        self.aiBoard.setItem(1, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(2, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(3, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(4, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(5, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(6, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(7, 0, item)
        item = QtWidgets.QTableWidgetItem()
        self.aiBoard.setItem(8, 0, item)
        self.aiBoard.horizontalHeader().setVisible(False)
        self.aiBoard.horizontalHeader().setDefaultSectionSize(40)
        self.aiBoard.horizontalHeader().setHighlightSections(False)
        self.aiBoard.horizontalHeader().setMinimumSectionSize(10)
        self.aiBoard.verticalHeader().setVisible(False)
        self.aiBoard.verticalHeader().setDefaultSectionSize(40)
        self.aiBoard.verticalHeader().setHighlightSections(False)
        self.aiBoard.verticalHeader().setMinimumSectionSize(10)
        self.label_board = QtWidgets.QLabel(self.centralwidget)
        self.label_board.setGeometry(QtCore.QRect(10, 0, 141, 31))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.label_board.setFont(font)
        self.label_board.setObjectName("label_board")
        self.label_board_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_board_2.setGeometry(QtCore.QRect(420, 0, 161, 31))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.label_board_2.setFont(font)
        self.label_board_2.setObjectName("label_board_2")
        self.startGame_Button = QtWidgets.QPushButton(self.centralwidget)
        self.startGame_Button.setEnabled(False)
        self.startGame_Button.setGeometry(QtCore.QRect(10, 460, 71, 51))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.startGame_Button.setFont(font)
        self.startGame_Button.setObjectName("startGame_Button")
        self.deletePlanes_Button = QtWidgets.QPushButton(self.centralwidget)
        self.deletePlanes_Button.setGeometry(QtCore.QRect(180, 470, 121, 31))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.deletePlanes_Button.sizePolicy().hasHeightForWidth())
        self.deletePlanes_Button.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.deletePlanes_Button.setFont(font)
        self.deletePlanes_Button.setObjectName("deletePlanes_Button")
        self.cabinSquare_Input = QtWidgets.QLineEdit(self.centralwidget)
        self.cabinSquare_Input.setGeometry(QtCore.QRect(10, 420, 81, 31))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.cabinSquare_Input.sizePolicy().hasHeightForWidth())
        self.cabinSquare_Input.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.cabinSquare_Input.setFont(font)
        self.cabinSquare_Input.setMaxLength(8)
        self.cabinSquare_Input.setAlignment(QtCore.Qt.AlignCenter)
        self.cabinSquare_Input.setClearButtonEnabled(False)
        self.cabinSquare_Input.setObjectName("cabinSquare_Input")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(10, 400, 291, 16))
        self.label.setObjectName("label")
        self.placePlane_Button = QtWidgets.QPushButton(self.centralwidget)
        self.placePlane_Button.setGeometry(QtCore.QRect(180, 420, 121, 31))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.placePlane_Button.sizePolicy().hasHeightForWidth())
        self.placePlane_Button.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.placePlane_Button.setFont(font)
        self.placePlane_Button.setObjectName("placePlane_Button")
        self.restart_Button = QtWidgets.QPushButton(self.centralwidget)
        self.restart_Button.setGeometry(QtCore.QRect(510, 430, 81, 51))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.restart_Button.sizePolicy().hasHeightForWidth())
        self.restart_Button.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.restart_Button.setFont(font)
        self.restart_Button.setObjectName("restart_Button")
        self.exit_Button = QtWidgets.QPushButton(self.centralwidget)
        self.exit_Button.setGeometry(QtCore.QRect(640, 430, 81, 51))
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.exit_Button.sizePolicy().hasHeightForWidth())
        self.exit_Button.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(12)
        self.exit_Button.setFont(font)
        self.exit_Button.setObjectName("exit_Button")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "PlaneWar"))
        __sortingEnabled = self.playerBoard.isSortingEnabled()
        self.playerBoard.setSortingEnabled(False)
        item = self.playerBoard.item(0, 1)
        item.setText(_translate("MainWindow", "A"))
        item = self.playerBoard.item(0, 2)
        item.setText(_translate("MainWindow", "B"))
        item = self.playerBoard.item(0, 3)
        item.setText(_translate("MainWindow", "C"))
        item = self.playerBoard.item(0, 4)
        item.setText(_translate("MainWindow", "D"))
        item = self.playerBoard.item(0, 5)
        item.setText(_translate("MainWindow", "E"))
        item = self.playerBoard.item(0, 6)
        item.setText(_translate("MainWindow", "F"))
        item = self.playerBoard.item(0, 7)
        item.setText(_translate("MainWindow", "G"))
        item = self.playerBoard.item(0, 8)
        item.setText(_translate("MainWindow", "H"))
        item = self.playerBoard.item(1, 0)
        item.setText(_translate("MainWindow", "1"))
        item = self.playerBoard.item(2, 0)
        item.setText(_translate("MainWindow", "2"))
        item = self.playerBoard.item(3, 0)
        item.setText(_translate("MainWindow", "3"))
        item = self.playerBoard.item(4, 0)
        item.setText(_translate("MainWindow", "4"))
        item = self.playerBoard.item(5, 0)
        item.setText(_translate("MainWindow", "5"))
        item = self.playerBoard.item(6, 0)
        item.setText(_translate("MainWindow", "6"))
        item = self.playerBoard.item(7, 0)
        item.setText(_translate("MainWindow", "7"))
        item = self.playerBoard.item(8, 0)
        item.setText(_translate("MainWindow", "8"))
        self.playerBoard.setSortingEnabled(__sortingEnabled)
        __sortingEnabled = self.aiBoard.isSortingEnabled()
        self.aiBoard.setSortingEnabled(False)
        item = self.aiBoard.item(0, 1)
        item.setText(_translate("MainWindow", "A"))
        item = self.aiBoard.item(0, 2)
        item.setText(_translate("MainWindow", "B"))
        item = self.aiBoard.item(0, 3)
        item.setText(_translate("MainWindow", "C"))
        item = self.aiBoard.item(0, 4)
        item.setText(_translate("MainWindow", "D"))
        item = self.aiBoard.item(0, 5)
        item.setText(_translate("MainWindow", "E"))
        item = self.aiBoard.item(0, 6)
        item.setText(_translate("MainWindow", "F"))
        item = self.aiBoard.item(0, 7)
        item.setText(_translate("MainWindow", "G"))
        item = self.aiBoard.item(0, 8)
        item.setText(_translate("MainWindow", "H"))
        item = self.aiBoard.item(1, 0)
        item.setText(_translate("MainWindow", "1"))
        item = self.aiBoard.item(2, 0)
        item.setText(_translate("MainWindow", "2"))
        item = self.aiBoard.item(3, 0)
        item.setText(_translate("MainWindow", "3"))
        item = self.aiBoard.item(4, 0)
        item.setText(_translate("MainWindow", "4"))
        item = self.aiBoard.item(5, 0)
        item.setText(_translate("MainWindow", "5"))
        item = self.aiBoard.item(6, 0)
        item.setText(_translate("MainWindow", "6"))
        item = self.aiBoard.item(7, 0)
        item.setText(_translate("MainWindow", "7"))
        item = self.aiBoard.item(8, 0)
        item.setText(_translate("MainWindow", "8"))
        self.aiBoard.setSortingEnabled(__sortingEnabled)
        self.label_board.setText(_translate("MainWindow", "Your Board:"))
        self.label_board_2.setText(_translate("MainWindow", "Opponet Board:"))
        self.startGame_Button.setText(_translate("MainWindow", "Start\n"
"Game"))
        self.deletePlanes_Button.setText(_translate("MainWindow", "Delete Planes"))
        self.cabinSquare_Input.setText(_translate("MainWindow", "2A right"))
        self.label.setText(_translate("MainWindow", "Position of plane\'s cabin and direction in which it points to"))
        self.placePlane_Button.setText(_translate("MainWindow", "Place Plane"))
        self.restart_Button.setText(_translate("MainWindow", "Restart"))
        self.exit_Button.setText(_translate("MainWindow", "Exit"))

