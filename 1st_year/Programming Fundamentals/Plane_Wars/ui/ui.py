'''
Created on 17 Dec 2018

@author: Daci
'''
from controller.game import Game
from domain.plane import Plane
from domain.square import Square
from random import choice


class CLI_UI:
    '''
    '''
    @staticmethod
    def printBanner():
        strg = "\tWelcome to the airplanes war! The grid below is your map.\n"
        strg += "there you have to place 2 planes and after that the game will begin.\n"
        strg += "\tTake into consideration that a plane looks like the one below and for\n"
        strg += "placing one you have to write planes cabin position and its orientation\n"
        strg += "where orientation means the direction in which cabin points to.\n"
        strg += "\tFor example: 1C up\n"
        strg += "\t\t  *\n\t\t*****\n\t\t  *\n\t\t ***"
        print(strg)

    @staticmethod
    def strgToVal(char):
        if '1' <= char <= '8':
            return int(char) - 1
        if 'a' <= char <= 'h':
            return ord(char) - ord('a')
        if 'A' <= char <= 'H':
            return ord(char) - ord('A')

    def inputPosToSquare(self, strg):
        moves = "123456789ABCDEFGHabcdefgh"
        if len(strg) != 2:
            raise ValueError("Inccorect command!")
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

    def __init__(self):
        self._game = Game()

    def printAiBoard(self):
        print(self._game.aiB.printBoard(btype="ai"))

    def printPlBoard(self):
        print(self._game.playerB.printBoard())

    def menu(self):
        self.printBanner()
        self.printPlBoard()
        print("You can start the game by pressing 's' but only after you place 2 planes!\nPlanes position:")
        self.playerSetUp()
        #self._game.playerB.drawPlane(Plane(cabinPos=Square(2,7), orientation="right"))
        #self._game.playerB.drawPlane(Plane(cabinPos=Square(7,2), orientation="down"))
        print("Game started!\n(you have to write now where you want to shoot for example 3H)")
        playerRound = choice([True, False])
        if playerRound:
            print("You hit first!")
        else:
            print("Computer hits first!")
        self.printPlBoard()
        self.printAiBoard()
        while not self._game.isOver():
            if playerRound:
                try:
                    cmd = input('>')
                    if cmd == '0' or cmd == 'exit':
                        return 0
                    self._game.aiB.hit(self.inputPosToSquare(cmd))
                    playerRound = not playerRound
                except Exception as err:
                    print(err)
            else:
                self._game.playerB.aiHitSmarter()
                playerRound = not playerRound
            self.printPlBoard()
            self.printAiBoard()
        if self._game.winner() == 1:
            print("Congrats man, you succeded to fight me!\nPlayer won!")
        else:
            print("Sorry bro, this time I was better that you.\nComputer won!")
        x = input("For restarting the game type 1. Anything else will close the game.")
        if x == '1':
            CLI_UI().menu()
        else:
            print("Was a plesure for me to play with you! Good bye and have a nice day!")
            return 0

    def playerSetUp(self, nbPlayerPlanes=0):
        while True:
            try:
                cmd = input(">")
                if cmd == '0' or cmd == 'exit':
                    exit(0)
                if cmd == 's' and nbPlayerPlanes == 2:
                    break
                elif cmd == 's':
                    raise ValueError("You can only start the game after you have 2 planes on the board!")
                if cmd == 'clear':
                    self._game.playerB.cleanPlanes()
                    nbPlayerPlanes = 0
                    self.printPlBoard()
                    continue
                cmdL = cmd.split()
                if len(cmdL) != 2:
                    print("Inccorect command!")
                else:
                    if nbPlayerPlanes == 2:
                        raise Exception("You can only have 2 planes on the board. If you want\nto change the plane you can clear the board using 'clear' command.")
                    self._game.playerB.drawPlane(Plane(cabinPos=self.inputPosToSquare(cmdL[0]), orientation=cmdL[1]))
                    self.printPlBoard()
                    nbPlayerPlanes += 1
            except Exception as err:
                print(err)
