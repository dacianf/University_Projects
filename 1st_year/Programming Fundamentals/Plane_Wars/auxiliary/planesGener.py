'''
Created on 17 Dec 2018

@author: Daci
'''
from domain.plane import Plane
#from domain.board import Board
import pickle
from domain.square import Square


def genPlanes(board):
    '''
        Generates valid plane's for a given board
        Input: - plane - Plane
               - board - Board
        Output: - planesL - List of valid Planes
    '''
    planesL = []
    for i in range(board.height):
        for j in range(board.lenght):
            for ori in ["up", "down", "left", "right"]:
                try:
                    pl = Plane(Square(i, j), orientation=ori)
                    board.validatePlaneCoords(pl)
                    planesL.append(pl)
                except Exception:
                    pass
    return planesL


def readFromBin(fileName):
    '''
        Reads from a binary file the objects and returns a list of them
        Input: - fileName - string
        Output: - objects - list of objects from file
    '''
    objects = []
    try:
        f = open(fileName, "rb")
        x = pickle.load(f)
        f.close()
        for obj in x:
            objects.append(obj)
        return objects
    except Exception as e:
        print("Error: " + str(e))
    return objects


def writeIntoBin(fileName, objects):
    '''
        Writes into a binary file a list of objects
        Input: - fileName - string
               - objects - list of objects
    '''
    f = open(fileName, "wb+")
    pickle.dump(objects, f)
    f.close()
