'''
Created on 15 Dec 2018

@author: Daci
'''
from domain.plane_validator import PlaneValidator
from domain.square import Square
from builtins import property
import unittest


class Plane:
    def __init__(self, cabinPos=Square(0, 0), orientation="up", upperWings=5, lowerWings=3, body=4):
        '''
            Initialize a plane with:
                cabin - Square which represents planes cabin position
                orientation - string between ["up", "down", "left", "right"] which are planes orientation
                uperWings - int lenght of upper planes wings (5 by default)
                lowerWings - int lenght of lower planes wings (3 by default)
                body - int lenght of body (4 by default)
        '''
        self._cabin = cabinPos
        self._orientation = orientation.lower()
        self._uw = upperWings
        self._lw = lowerWings
        self._bd = body
        PlaneValidator(self).validate()
        self._planeCoords = [[] for x in range(self.body)]
        self.__setOrientation()

    @property
    def cabinPos(self):
        return self._cabin

    @property
    def orientation(self):
        return self._orientation

    @property
    def upperWings(self):
        return self._uw

    @property
    def lowerWings(self):
        return self._lw

    @property
    def body(self):
        return self._bd

    @property
    def up(self):
        self.__clearCoords()
        self._planeCoords[0].append(self.cabinPos)
        for i in range(-(self.upperWings // 2), self.upperWings // 2 + 1):
            self._planeCoords[1].append(Square(1, i) + self.cabinPos)
        for i in range(2, self.body - 1):
            self._planeCoords[2].append(Square(i, 0) + self.cabinPos)
        lp = self.lowerWings // 2
        for i in range(-lp, lp + 1):
            self._planeCoords[3].append(Square(self.body - 1, i) + self.cabinPos)
        return self._planeCoords

    @property
    def left(self):
        self.__clearCoords()
        self._planeCoords[0].append(self.cabinPos)
        for i in range(-(self.upperWings // 2), self.upperWings // 2 + 1):
            self._planeCoords[1].append(Square(i, 1) + self.cabinPos)
        for i in range(2, self.body - 1):
            self._planeCoords[2].append(Square(0, i) + self.cabinPos)
        lp = self.lowerWings // 2
        for i in range(-lp, lp + 1):
            self._planeCoords[3].append(Square(i, self.body - 1) + self.cabinPos)
        return self._planeCoords

    @property
    def down(self):
        self.__clearCoords()
        self._planeCoords[0].append(self.cabinPos)
        for i in range(-(self.upperWings // 2), self.upperWings // 2 + 1):
            self._planeCoords[1].append(Square(self.cabinPos.longitude - 1, i + self.cabinPos.latitude))
        for i in range(self.body - 3, 0, -1):
            self._planeCoords[2].append(Square(self.cabinPos.longitude - i - 1, self.cabinPos.latitude))
        lp = self.lowerWings // 2
        for i in range(-lp, lp + 1):
            self._planeCoords[3].append(Square(self.cabinPos.longitude - self.body + 1, i + self.cabinPos.latitude))
        return self._planeCoords

    @property
    def right(self):
        self.__clearCoords()
        self._planeCoords[0].append(self.cabinPos)
        for i in range(-(self.upperWings // 2), self.upperWings // 2 + 1):
            self._planeCoords[1].append(Square(self.cabinPos.longitude + i, self.cabinPos.latitude - 1))
        for i in range(self.body - 3, 0, -1):
            self._planeCoords[2].append(Square(self.cabinPos.longitude, self.cabinPos.latitude - i - 1))
        lp = self.lowerWings // 2
        for i in range(-lp, lp + 1):
            self._planeCoords[3].append(Square(self.cabinPos.longitude + i, self.cabinPos.latitude - self.body + 1))
        return self._planeCoords

    @property
    def getCoords(self):
        return self._planeCoords

    def __clearCoords(self):
        for i in range(4):
            self._planeCoords[i].clear()

    def __setOrientation(self):
        orr = self._orientation
        if orr == "up":
            self.up
        elif orr == "down":
            self.down
        elif orr == "left":
            self.left
        elif orr == "right":
            self.right

    def __str__(self):
        strg = ""
        for i in range(self.body):
            for sq in self._planeCoords[i]:
                strg += "(" + str(sq) + ") "
            strg += "\n"
        return strg


class TestPlane(unittest.TestCase):
    def setUp(self):
        self.p = Plane(cabinPos=Square(0, 2))

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testCr(self):
        lis = [Square(0, 2), Square(1, 0), Square(1, 1), Square(1, 2), Square(1, 3), Square(1, 4), Square(1, 5), Square(2, 2), Square(3, 1), Square(3, 2), Square(3, 3)]
        liInd = 0
        for body in self.p.getCoords:
            for sq in body:
                if sq == lis[liInd]:
                    liInd += 1
                else:
                    self.assertFalse()
                