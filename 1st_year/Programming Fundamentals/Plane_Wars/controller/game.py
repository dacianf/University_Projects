'''
Created on 8 Jan 2019

@author: Daci
'''
from domain.board import Board
from controller.planes_board import Planes_Board
import unittest


class Game():
    def __init__(self):
        self._plBoard = Planes_Board(board=Board(), player=1)
        self._aiBoard = Planes_Board(board=Board(), player=0)

    @property
    def playerB(self):
        return self._plBoard

    @property
    def aiB(self):
        return self._aiBoard

    def isOver(self):
        '''
            Checks if game is over. This happens when one of the players have no more alive planes.
        '''
        if self.aiB.alivePlanes > 0 and self.playerB.alivePlanes > 0:
            return False
        return True

    def winner(self):
        '''
            Returns 1 if player won and 0 otherwise
        '''
        if self.isOver():
            if self.aiB.alivePlanes == 0:
                return 1
            if self.playerB.alivePlanes == 0:
                return 0
        raise Exception("Both players have plane which can fly!")


class TestGame(unittest.TestCase):
    def setUp(self):
        self.g = Game()

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def test(self):
        self.assertEqual(self.g.isOver(), False)
        self.g.aiB._alivePlanes = 1
        self.assertEqual(self.g.isOver(), False)
        self.g.aiB._alivePlanes = 0
        self.assertEqual(self.g.isOver(), True)
        self.assertEqual(self.g.winner(), 0)
