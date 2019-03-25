'''
Created on 27 Nov 2018

@author: Daci
'''
from controller.controllerException import ControllerException
from copy import deepcopy


class UndoController:
    '''
        Manages undo/redo opperations
    '''

    def __init__(self):
        self._cmds = []
        self._index = -1
        self._undoFlag = False

    def addOperation(self, operation):
        if self._undoFlag:
            return
        if self._index != len(self._cmds) - 1:
            self._cmds = deepcopy(self._cmds[:self._index + 1])
        self._index += 1
        self._cmds.append(operation)

    def undo(self):
        if self._index <= -1:
            raise ControllerException(["No more undos available!"])
        self._undoFlag = True
        self._cmds[self._index].undo()
        self._undoFlag = False
        self._index -= 1

    def redo(self):
        if self._index >= len(self._cmds) - 1:
            raise ControllerException(["No more redos available!"])
        self._index += 1
        self._undoFlag = True
        self._cmds[self._index].redo()
        self._undoFlag = False
