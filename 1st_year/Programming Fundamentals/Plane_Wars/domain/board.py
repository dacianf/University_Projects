'''
Created on 15 Dec 2018

@author: Daci
'''
from builtins import property
from texttable import Texttable
from string import ascii_uppercase
from copy import deepcopy
from domain.board_exception import BoardException
from domain.square import Square
import unittest
from domain.square_exception import SquareException


class Board():
    '''
    '''

    def __init__(self, lenght=8, height=8):
        if lenght < 1 or height < 1:
            raise BoardException("Lenght and height of the domain must be at least 1")
        self._len = lenght
        self._hei = height
        self._board = [[-1 for x in range(lenght)] for y in range(height)]

    @property
    def lenght(self):
        return self._len

    @property
    def height(self):
        return self._hei

    @property
    def board(self):
        return self._board

    def getSquare(self, square):
        '''
            Returns the value from the given square on the board
        '''
        if type(square) != Square:
            raise TypeError("Square must be of Square type!")
        self.__validateSquare(square)
        return self._board[square.longitude][square.latitude]

    def copy(self):
        '''
            Returns a deepcopy of current board
        '''
        return deepcopy(self.board)

    @property
    def clear(self):
        '''
            Clear the board by putting -1 in every square
        '''
        self._board = [[-1 for x in range(self.lenght)] for y in range(self.height)]

    def drawPoint(self, square, char):
        '''
            Writes on tabel the given char at the given square
        '''
        if self.__validateMove(square):
            self.board[square.longitude][square.latitude] = char

    def hit(self, square):
        '''
            Writes on the board 1 if the given square is part of a plane
            and 0 oterwise
        '''
        if self.__validateSquare(square):
            if self.board[square.longitude][square.latitude] == -1:
                self.board[square.longitude][square.latitude] = 0
            else:
                self.board[square.longitude][square.latitude] = 1

    def __validateSquare(self, square):
        '''
            Checks if the given square is in the board
            Input: - square - Square
            Output: - True - if it's a valid square
                    raise BoardException otherwise
        '''
        if type(square) != Square:
            raise TypeError("You must give Square type object!")
        msg = []
        if square.latitude < 0 or square.latitude >= self.lenght:
            msg.append("Move's latitude must be between 0 and " + str(self.lenght) + "!")
        if square.longitude < 0 or square.longitude >= self.height:
            msg.append("Move's longitude must be between 0 and " + str(self.height) + "!")
        if len(msg):
            raise BoardException(msg)
        return True

    def __validateMove(self, square):
        '''
            Checks if the given square is a valid move
            Input: - square - Square
            Output: - True - if it's a valid move
                    raise BoardException otherwise
        '''
        self.__validateSquare(square)
        if self.board[square.longitude][square.latitude] != -1:
            raise BoardException(str(square) + " is already occupied!")
        return True

    def validatePlaneCoords(self, plane):
        '''
            Checks if the board's squares in which given
            plane will be placed, are empty
            Input: - plane - Plane
            Output: - True - if board's square coresponding to plane's coords are empty
                    - False - otherwise
        '''
        coords = plane.getCoords
        for i in range(4):
            for co in coords[i]:
                if co.latitude < 0 or co.longitude < 0 or self.board[co.longitude][co.latitude] != -1:
                    return False
        return True

    def __repr__(self):
        return "Board(" + str(self.lenght) + "," + self.height + ")" + 0

    def __str__(self):
        txt = Texttable()
        let = ['']
        for i in range(self.lenght):
            let.append(ascii_uppercase[i])
        txt.add_row(let)
        board = self.copy()
        for i in range(self.height):
            board[i].insert(0, i + 1)
            txt.add_row(board[i])
        return(txt.draw())


from domain.plane import Plane


class TestBoard(unittest.TestCase):
    def setUp(self):
        self.b = Board()

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testGetSq(self):
        sq = Square(-1, 5)
        self.assertRaises(TypeError, self.b.getSquare, 4)
        self.assertRaises(BoardException, self.b.getSquare, sq)
        self.b.board[3][2] = 1
        self.assertEqual(self.b.board[3][2], self.b.getSquare(Square(3, 2)))

    def testDrawPoint(self):
        sq = Square(-1, 5)
        self.assertRaises(TypeError, self.b.getSquare, 4)
        self.assertRaises(BoardException, self.b.getSquare, sq)
        sq = Square(3, 2)
        self.b.drawPoint(sq, 3)
        self.assertEqual(3, self.b.getSquare(Square(3, 2)))

    def testHit(self):
        sq = Square(3, 2)
        self.b.drawPoint(sq, 8)
        self.b.hit(sq)
        self.assertEqual(1, self.b.getSquare(sq))
        sq = Square(5, 2)
        self.b.hit(sq)
        self.assertEqual(0, self.b.getSquare(sq))

    def testValidPlane(self):
        self.assertTrue(self.b.validatePlaneCoords(Plane(cabinPos=Square(0, 2))))
        self.b.hit(Square(2, 2))
        self.assertFalse(self.b.validatePlaneCoords(Plane(cabinPos=Square(2, 2))))