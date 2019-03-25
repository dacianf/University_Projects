'''
Created on 27 Nov 2018

@author: Daci
'''


class OperationsCascade:
    '''
    classdocs
    '''

    def __init__(self):
        self._operations = []

    def addOp(self, operation):
        self._operations.append(operation)

    def undo(self):
        for o in self._operations:
            o.undo()

    def redo(self):
        for o in self._operations:
            o.redo()

    def __len__(self):
        return len(self._operations)

    def reverseOper(self):
        self._operations.reverse()
