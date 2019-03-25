'''
Created on 1 Feb 2019

@author: Daci
'''
from copy import deepcopy
from texttable import Texttable
from string import ascii_uppercase
from domain.square import Square


class Board():
    
    def __init__(self):
        self._len = 8
        self._hei = 8
        self._board = [[' ' for x in range(8)] for y in range(8)]
    
    @property
    def lenght(self):
        return self._len

    @property
    def height(self):
        return self._hei

    @property
    def board(self):
        return self._board
    
    @board.setter
    def board(self, bd):
        self._board = bd
    def getSquare(self, square):
        '''
            Returns the value from the given square on the board
        '''
        if type(square) != Square:
            raise TypeError("Square must be of Square type!")
        self.__validateSquare(square)
        return self._board[square.y][square.x]

    def copy(self):
        '''
            Returns a deepcopy of current board
        '''
        return deepcopy(self._board)

    @property
    def clear(self):
        '''
            Clear the board by putting -1 in every square
        '''
        self._board = [[-1 for x in range(self.lenght)] for y in range(self.height)]

    def drawPoint(self, square):
        '''
            Writes on tabel the given char at the given square
        '''
        if self.__validateMove(square):
            self.board[square.y][square.x] = 'x'
    
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

