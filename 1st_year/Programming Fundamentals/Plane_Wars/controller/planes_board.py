'''
Created on 16 Dec 2018

@author: Daci
'''
from copy import deepcopy
from texttable import Texttable
from domain.square import Square
from string import ascii_uppercase
from auxiliary.planesGener import readFromBin
from random import choice, randint
from domain.board_exception import BoardException
import unittest


class Planes_Board:
    def __init__(self, board, nbPlanes=2, player=0, *planes):
        '''
            Player=(0,1) 0-computer; 1-human;
        '''
        self._board = board
        self._planes = []
        if player == 1:
            if len(planes):
                self._planes = planes
                for plane in self._planes:
                    self.drawPlane(plane)
        elif player == 0:
            self._setComputerPlanes(nbPlanes)
        self._aiHittingPos = []
        for i in range(self._board.height):
            for j in range(self._board.lenght):
                self._aiHittingPos.append(Square(i, j))
        self._aiSmarterMoves = []
        self._aiMovesNb = self._board.lenght * self._board.height
        self._alivePlanes = nbPlanes

    @property
    def alivePlanes(self):
        return self._alivePlanes

    def drawPlane(self, plane):
        '''
            Draws a plane on the board.
            Planes cabin is denoted by 9 and the rest of it is 8
            Input: - plane - Plane
            Output: - True - if plane was successfully placed
                    - False - otherwise
        '''
        coords = plane.getCoords
        if self._board.validatePlaneCoords(plane):
            self._board.drawPoint(coords[0][0], 9)
            for i in range(1, len(coords)):
                for sq in coords[i]:
                    self._board.drawPoint(sq, 8)
            self._planes.append(plane)
            return True
        raise BoardException("The plane cannot be placed there!")

    def printBoard(self, btype='player'):
        '''
                Returns a textable with the current board using boardType(btype)
            to know if planes should be displayed or not
            Input: - btaype - string, by default is 'player' and displays the planes
                            if it's not player it will not display the planes
            Output: - table - string which contains the board to be print
        '''
        boardToPrint = deepcopy(self._board).board
        table = Texttable()
        let = ['']
        for i in range(self._board.lenght):
            let.append(ascii_uppercase[i])
        table.add_row(let)
        for i in range(self._board.height):
            for j in range(self._board.lenght):
                if boardToPrint[i][j] == 0:
                    boardToPrint[i][j] = "O"
                elif boardToPrint[i][j] == 1:
                    boardToPrint[i][j] = "X"
                elif boardToPrint[i][j] == 8 and btype == "player":
                    boardToPrint[i][j] = "*"
                elif boardToPrint[i][j] == 9 and btype == "player":
                    x = self.__findPlane(Square(i, j))
                    if x.orientation == "up":
                        boardToPrint[i][j] = "^"
                    elif x.orientation == "down":
                        boardToPrint[i][j] = "v"
                    elif x.orientation == "left":
                        boardToPrint[i][j] = "<"
                    elif x.orientation == "right":
                        boardToPrint[i][j] = ">"
                else:
                    boardToPrint[i][j] = " "
            boardToPrint[i].insert(0, str(i + 1))
            table.add_row(boardToPrint[i])
        return table.draw()

    def _setComputerPlanes(self, nb=2):
        '''
                Inserts in the self._planes list computers planes which are taken random
            from a file with all planes that can be on a 8x8 grid.
            Input: - nb - int which is number of computer's planes
                        which is 2 by default
        '''
        validPlanes = readFromBin("auxiliary\\valid_5x3-Planes_on_8x8-Board")
        while nb:
            try:
                pl = choice(validPlanes)
                self.drawPlane(pl)
                nb -= 1
            except Exception:
                pass

    def __findPlane(self, cabinPos):
        '''
            Returns a plane with given cabinPosition
            Input: - cabinPos - Square
            Output: - plane - Plane
                    - False - if there is no plane with given cabin
        '''
        if len(self._planes):
            for plane in self._planes:
                if plane.cabinPos == cabinPos:
                    return plane
        return False

    def hit(self, square):
        '''
            Hits on a given square.
            If given square is a cabin => entire plane will be marked as hitted
            If given square is a part of the plane => given square will be marked as hitted
            If given square is not a valid square or was already hitted there a BoardException will be raised
            Input: - square - Square
            Output: - sqHitted - list of hitted squares
        '''
        x = self._board.getSquare(square)
        sqHitted = []
        if x == 1 or x == 0:
            raise BoardException(str(square) + " was already hit!")
        elif x == 9:
            self._alivePlanes -= 1
            wreck = self.__findPlane(square).getCoords
            for coords in wreck:
                for sq in coords:
                    self._board.hit(sq)
                    sqHitted.append(sq)
        elif x == 8:
            self._board.hit(square)
            sqHitted.append(square)
        else:
            self._board.hit(square)
            sqHitted.append(square)
        return sqHitted

    def aiHit(self):
        '''
            Computers plays tottaly random
            Output: - hittedSq - list of hitted squares
                    - htSqStat - status of first hitted square
        '''
        while True:
            try:
                index = randint(0, self._aiMovesNb - 1)
                sq = self._aiHittingPos[index]
                htSqStat = self.getSquareStatus(sq)
                hittedSq = self.hit(self._aiHittingPos.pop(index))
                self._aiMovesNb -= 1
                return hittedSq, htSqStat
            except Exception:
                pass

    def aiHitSmarter(self):
        '''
            Computers plays random untill finds a plane part and then
            it hits around that point
            Output: - sqHitted - list of hitted squares
                    - status - status of first hitted square
        '''
        if not len(self._aiSmarterMoves):
            sqHitted, status = self.aiHit()
            if status == 8:
                self._addSqToQ(self._aiSmarterMoves, sqHitted[0])
            return sqHitted, status
        else:
            while len(self._aiSmarterMoves):
                try:
                    sq = self._aiSmarterMoves.pop(randint(0, len(self._aiSmarterMoves) - 1))
                    status = self.getSquareStatus(sq)
                    sqHitted = self.hit(sq)
                    if status == 8:
                        self._addSqToQ(self._aiSmarterMoves, sqHitted[0])
                    if status == 9:
                        self._aiSmarterMoves = []
                    return sqHitted, status
                except Exception:
                    pass

    def _addSqToQ(self, q, sq):
        '''
            Adds valid squares around given one into list q
            Input: - q - list of squares
                   - sq - Square
        '''
        for i in [-1, 1]:
            sq1 = Square(sq.longitude + i, sq.latitude)
            sq2 = Square(sq.longitude, sq.latitude + i)
            if 0 <= sq1.latitude <= 7 and self.getSquareStatus(sq1) != 0 and self.getSquareStatus(sq1) != 1:
                q.append(Square(sq.longitude + i, sq.latitude))
            if 0 <= sq2.latitude <= 7 and self.getSquareStatus(sq1) != 0 and self.getSquareStatus(sq1) != 1:
                q.append(Square(sq.longitude, sq.latitude + i))

    def cleanPlanes(self):
        '''
            Removes exited planes
        '''
        self._board.clear
        self._planes = []

    def getSquareStatus(self, square):
        '''
            Returns what given square contains
        '''
        return self._board.getSquare(square)


from domain.plane import Plane
from domain.board import Board

class TestPlanesBoard(unittest.TestCase):
    def setUp(self):
        self.ai = Planes_Board(board=Board())
        self.pl = Planes_Board(board=Board(), player=1)

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testDrawing(self):
        self.pl.drawPlane(Plane(Square(0, 2)))
        self.assertEqual(1, len(self.pl._planes))
        self.pl.cleanPlanes()
        self.assertEqual(0, len(self.pl._planes))
        self.pl.drawPlane(Plane(Square(0, 2)))
        self.pl.drawPlane(Plane(Square(7, 4), orientation="down"))
        self.assertEqual(2, len(self.pl._planes))
        self.assertEqual(2, self.pl.alivePlanes)

        self.assertEqual(2, len(self.ai._planes))

    def testHit(self):
        self.pl.drawPlane(Plane(Square(0, 2)))
        self.pl.drawPlane(Plane(Square(7, 4), orientation="down"))
        self.assertEqual(2, len(self.pl._planes))
        x = self.pl.hit(Square(0, 2))
        self.assertEqual(len(x), 10)
        x = self.pl.hit(Square(5, 4))
        self.assertEqual(len(x), 1)
        x = self.pl.hit(Square(0, 0))
        self.assertEqual(len(x), 1)
