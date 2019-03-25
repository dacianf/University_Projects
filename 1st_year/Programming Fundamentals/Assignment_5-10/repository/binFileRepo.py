'''
Created on 4 Dec 2018

@author: Daci
'''
from repository.repo import Repository
from settings.fileOperations import readFromBin, writeIntoBin


class BinRepository(Repository):
    '''
    '''

    def __init__(self, fileName, Obj):
        Repository.__init__(self)
        self._fileName = fileName
        self._obj = Obj
        self._objects = readFromBin(fileName)

    def add(self, obj):
        Repository.add(self, obj)
        writeIntoBin(self._fileName, self.getAll())

    def remove(self, objectID):
        Repository.remove(self, objectID)
        writeIntoBin(self._fileName, self.getAll())

    def removeGrade(self, grade):
        Repository.removeGrade(self, grade)
        writeIntoBin(self._fileName, self.getAll())

    def update(self, obj):
        Repository.update(self, obj)
        writeIntoBin(self._fileName, self.getAll())
