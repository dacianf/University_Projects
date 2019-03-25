# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'planeWar.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets
from controller.game import Game
from domain.square import Square
from domain.plane import Plane
from random import choice


class Ui_MainWindow(object):
    def __init__(self):
        self._game = Game()
        self._plPlanes = 0
        self._status = 1

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
        for i in range(1, 9): 
            item = QtWidgets.QTableWidgetItem()
            item.setTextAlignment(QtCore.Qt.AlignCenter)
            self.playerBoard.setItem(0, i, item)
            item = QtWidgets.QTableWidgetItem()
            item.setTextAlignment(QtCore.Qt.AlignCenter)
            self.playerBoard.setItem(i, 0, item)
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
        item.setFlags(QtCore.Qt.ItemIsSelectable | QtCore.Qt.ItemIsDragEnabled)
        self.aiBoard.setItem(0, 0, item)
        for i in range(1, 9): 
            item = QtWidgets.QTableWidgetItem()
            item.setTextAlignment(QtCore.Qt.AlignCenter)
            item.setFlags(QtCore.Qt.ItemIsSelectable | QtCore.Qt.ItemIsDragEnabled)
            self.aiBoard.setItem(0, i, item)
            item = QtWidgets.QTableWidgetItem()
            item.setFlags(QtCore.Qt.ItemIsSelectable | QtCore.Qt.ItemIsDragEnabled)
            item.setTextAlignment(QtCore.Qt.AlignCenter)
            self.aiBoard.setItem(i, 0, item)
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

        self.placePlane_Button.clicked.connect(self.placePlane)
        self.deletePlanes_Button.clicked.connect(self.clearBoard)
        self.startGame_Button.clicked.connect(self.startGame)
        self.restart_Button.clicked.connect(self.reset)
        self.exit_Button.clicked.connect(self.exit)
        self.aiBoard.cellClicked.connect(self.play)

        self.aiBoard.setEnabled(False)
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "PlaneWar"))
        __sortingEnabled = self.playerBoard.isSortingEnabled()
        self.playerBoard.setSortingEnabled(False)
        for i in range(8):
            item = self.playerBoard.item(0, i + 1)
            item.setText(_translate("MainWindow", chr(i + ord('A'))))
        for i in range(8):
            item = self.playerBoard.item(i + 1, 0)
            item.setText(_translate("MainWindow", chr(i + ord('1'))))

        self.playerBoard.setSortingEnabled(__sortingEnabled)
        __sortingEnabled = self.aiBoard.isSortingEnabled()
        self.aiBoard.setSortingEnabled(False)
        for i in range(8):
            item = self.aiBoard.item(0, i + 1)
            item.setText(_translate("MainWindow", chr(i + ord('A'))))
        for i in range(8):
            item = self.aiBoard.item(i + 1, 0)
            item.setText(_translate("MainWindow", chr(i + ord('1'))))
        item.setText(_translate("MainWindow", "8"))
        self.aiBoard.setSortingEnabled(__sortingEnabled)
        self.label_board.setText(_translate("MainWindow", "Your Board:"))
        self.label_board_2.setText(_translate("MainWindow", "Computer Board:"))
        self.startGame_Button.setText(_translate("MainWindow", "Start\nGame"))
        self.deletePlanes_Button.setText(_translate("MainWindow", "Delete Planes"))
        self.cabinSquare_Input.setText(_translate("MainWindow", "1C UP"))
        self.label.setText(_translate("MainWindow", "Position of plane\'s cabin and direction in which it points to"))
        self.placePlane_Button.setText(_translate("MainWindow", "Place Plane"))
        self.restart_Button.setText(_translate("MainWindow", "Restart"))
        self.exit_Button.setText(_translate("MainWindow", "Exit"))

    def createDialog(self, err, title, iccon):
        qDial = QtWidgets.QMessageBox()
        qDial.setIcon(iccon)
        qDial.setText(err)
        qDial.setWindowTitle(title)
        qDial.exec_()

    @staticmethod
    def strgToVal(char):
        if '1' <= char <= '8':
            return int(char) - 1
        if 'a' <= char <= 'h':
            return ord(char) - ord('a')
        if 'A' <= char <= 'H':
            return ord(char) - ord('A')

    def checkPos(self, strg):
        moves = "12345678ABCDEFGHabcdefgh"
        cmds = strg.split()
        if len(cmds) != 2:
            raise ValueError("Position must be of form: 3A UP(up|down|righ|left)!")
        if strg[0] not in moves or strg[1] not in moves:
            raise ValueError("Inccorect coords! They must be between 1-8 and A-H")
        if strg[0].isnumeric() and strg[1].isalpha():
            x = self.strgToVal(strg[0])
            y = self.strgToVal(strg[1])
        elif strg[1].isnumeric() and strg[0].isalpha():
            y = self.strgToVal(strg[0])
            x = self.strgToVal(strg[1])
        else:
            raise ValueError("Inccorect command!")
        return Square(x, y)

    def placePlane(self):
        try:
            colors = [QtGui.QColor(0, 93, 224), QtGui.QColor(230, 247, 0), QtGui.QColor(0, 214, 60)]
            if self._plPlanes < 2:
                strg = self.cabinSquare_Input.text()
                cabin = self.checkPos(strg)
                strg = strg.split()
                pl = Plane(cabin, orientation=strg[1])
                self._game.playerB.drawPlane(pl)
                col = choice(colors)
                for bodyPart in pl.getCoords:
                    for sq in bodyPart:
                        item = QtWidgets.QTableWidgetItem()
                        item.setBackground(col)
                        self.playerBoard.setItem(sq.longitude + 1, sq.latitude + 1, item)
                self._plPlanes += 1
                if self._plPlanes == 2:
                    self.startGame_Button.setEnabled(True)
            else:
                raise Exception("You can not have more than 2 planes on the board\n"
                                "if you want to change them press clear board")
        except Exception as err:
            self.createDialog(str(err), "Error!", QtWidgets.QMessageBox.Critical)

    def clearBoard(self):
        for i in range(1, 9):
            for j in range(1, 9):
                item = QtWidgets.QTableWidgetItem()
                item.setBackground(QtGui.QColor(255, 255, 255))
                self.playerBoard.setItem(i, j, item)
                item = QtWidgets.QTableWidgetItem()
                item.setBackground(QtGui.QColor(255, 255, 255))
                self.aiBoard.setItem(i, j, item)
        self._game.playerB.cleanPlanes()
        self._plPlanes = 0
        self.startGame_Button.setEnabled(False)
        self.createDialog("Board was deleted", "Info!", QtWidgets.QMessageBox.Information)

    def startGame(self):
        self.startGame_Button.setEnabled(False)
        self.placePlane_Button.setEnabled(False)
        self.deletePlanes_Button.setEnabled(False)
        self.cabinSquare_Input.setText("")
        self.cabinSquare_Input.setEnabled(False)
        self.aiBoard.setEnabled(True)
        playerRound = choice([True, False])
        if playerRound:
            msg = "You hit first!"
        else:
            msg = "Computer hits first!"
        self.createDialog(msg, "Game Started!", QtWidgets.QMessageBox.Information)
        if not playerRound:
            #sq, stat = self._game.playerB.aiHit()
            sq, stat = self._game.playerB.aiHitSmarter()
            self.hitOnBoard(sq, stat, self.playerBoard)
            playerRound = not playerRound

    def hitOnBoard(self, sq, status, board):
        item = QtWidgets.QTableWidgetItem()
        if status == 8:
            sq = sq[0]
            item.setBackground(QtGui.QColor(191, 19, 19))
            board.setItem(sq.longitude + 1, sq.latitude + 1, item)
        elif status == 9:
            wreck = sq
            for sq in wreck:
                item = QtWidgets.QTableWidgetItem()
                item.setBackground(QtGui.QColor(191, 19, 19))
                board.setItem(sq.longitude + 1, sq.latitude + 1, item)
        else:
            sq = sq[0]
            item.setBackground(QtGui.QColor(165, 165, 170))
            board.setItem(sq.longitude + 1, sq.latitude + 1, item)

    def exit(self):
        exit(0)

    def reset(self):
        self._game = Game()
        self._plPlanes = 0
        self.clearBoard()
        self.startGame_Button.setEnabled(False)
        self.placePlane_Button.setEnabled(True)
        self.deletePlanes_Button.setEnabled(True)
        self.cabinSquare_Input.setText("")
        self.cabinSquare_Input.setEnabled(True)
        self.aiBoard.setEnabled(True)

    def aiVsAi(self, playerRound):
        while not self._game.isOver():
            if playerRound:
                try:
                    sq, stat = self._game.aiB.aiHit()
                    self.hitOnBoard(sq, stat, self.aiBoard)
                    playerRound = not playerRound
                except Exception as err:
                    self.createDialog(str(err), "Error!", QtWidgets.QMessageBox.Critical)
                    playerRound = not playerRound
            else:
                sq, stat = self._game.playerB.aiHit()
                self.hitOnBoard(sq, stat, self.playerBoard)
                playerRound = not playerRound

    def checkGameOver(self):
        if self._game.isOver():
            self.aiBoard.setEnabled(False)
            if self._game.winner() == 1:
                msg = "Congrats man, you succeded to fight me!\nPlayer won!"
            else:
                msg = "Sorry bro, this time I was better that you.\nComputer won!"
            self.createDialog(msg, "Game is Over!", QtWidgets.QMessageBox.Information)
            return True
        return False

    def play(self):
        if self._status:
            crtIndex = self.aiBoard.currentIndex()
            sq = Square(crtIndex.row() - 1, crtIndex.column() - 1)
            if sq.latitude + 1 > 0 and sq.longitude + 1 > 0:
                try:
                    stat = self._game.aiB.getSquareStatus(sq)
                    sq = self._game.aiB.hit(sq)
                    self.hitOnBoard(sq, stat, self.aiBoard)
                    if not self.checkGameOver():
                        #sq, stat = self._game.playerB.aiHit()
                        sq, stat = self._game.playerB.aiHitSmarter()
                        self.hitOnBoard(sq, stat, self.playerBoard)
                        self.checkGameOver()
                except Exception as err:
                    self.createDialog(str(err), "Incorect hit!", QtWidgets.QMessageBox.Information)
