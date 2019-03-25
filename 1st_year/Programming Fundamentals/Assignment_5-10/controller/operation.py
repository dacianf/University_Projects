'''
Created on 27 Nov 2018

@author: Daci
'''


class Operation():
    '''
    '''

    def __init__(self, doCommand, undoCommand):
        self._cmdDo = doCommand
        self._cmdUndo = undoCommand

    def undo(self):
        self._cmdUndo.call()

    def redo(self):
        self._cmdDo.call()
