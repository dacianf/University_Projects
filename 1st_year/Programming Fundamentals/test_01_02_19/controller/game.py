'''
Created on 1 Feb 2019

@author: Daci
'''
from domain.board import Board
from copy import deepcopy
from domain.square import Square
from auxx.auxFunc import readState, writeFile, readPattern


class Game():
    def __init__(self):
        self._board = Board()
    
    @property
    def board(self):
        return self._board
    
    def displayBoard(self):
        return str(self._board)
    
    def placePattern(self, patt, sq):
        '''
            Places a given pattern at the given square
            if it can not do this throws an error
            Input: patt - matrix with the pattern
                   sq - Square where the pattern will be placed
        '''
        bku = deepcopy(self._board)
        try:
            for i in range(len(patt[1])):
                for j in range(len(patt[1])):
                    if patt[i][j] == ' ':
                        try:
                            print(patt[i][j])
                            bku.board[i + sq.y][j + sq.x] = patt[i][j]
                        except Exception:
                            pass
                    bku.board[i + sq.y][j + sq.x] = patt[i][j]
            self._board = deepcopy(bku)
        except Exception:
            raise ValueError("Pattern cannot be placed there")

    def update(self, nTimes=1):
        '''
            Updates the tables status of nTimes by default being 1 using given rules
            input: nTimes - integer
        '''
        newSt = Board()
        while nTimes > 0:
            nTimes -= 1
            for i in range(8):
                for j in range(8):
                    nei = self.getNbOfNei(Square(i, j))
                    if nei == 2 or nei == 3:
                        newSt.board[i][j] = 'x'
                    if self._board.board[i][j] == '0' and nei == 3:
                        newSt.board.board[i][j] = 'x'
        self._board = deepcopy(newSt)

    def getNbOfNei(self, sq):
        '''
            Gets how many neighbors given sq has
        '''
        x = [-1,  0,  1, 1, -1, 1, -1, 0]
        y = [-1, -1, -1, 0,  0, 1,  1, 1]
        sum = 0
        
        for i in range(8):
            try:
                if self._board.board[y[i] + sq.y][x[i] + sq.x] == 'x':
                    sum += 1
            except Exception:
                pass
        return sum

    def loadPattern(self, patt):
        '''
            Loads a pattern from file
        '''
        return readPattern('patterns.txt', patt)

    def loadState(self, fileName):
        self._board.board = readState(fileName)

    def saveState(self, fileName):
        #try:
            sqList = []
            for i in range(8):
                for j in range(8):
                    if self._board.board[i][j] == 'x':
                        sqList.append(Square(i, j))
            writeFile(fileName, sqList)


def testUpdate():
    x = Game()
    patt = x.loadPattern('block')
    x.placePattern(patt, Square(0, 0))
    x.update()
    sm = 0
    for i in range(8):
        for j in range(8):
            if x.board.board[i][j] == 'x':
                sm += 1
    assert sm == 4
    
    
def testPlace():
    x = Game()
    patt = x.loadPattern('block')
    x.placePattern(patt, Square(0, 0))
    sm = 0
    for i in range(8):
        for j in range(8):
            if x.board.board[i][j] == 'x':
                sm += 1
    assert sm == 4
    x.placePattern(patt, Square(3, 3))
    sm = 0
    for i in range(8):
        for j in range(8):
            if x.board.board[i][j] == 'x':
                sm += 1
    assert sm == 8
    try:
        x.placePattern(patt, Square(0, 0))
        assert False
    except Exception:
        assert True
    
#testUpdate()
#testPlace()

