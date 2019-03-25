'''
Created on 3 Dec 2018

@author: Daci
'''
from repository.repo import Repository
from settings.fileOperations import readStFromFile, writeStInFile


class TextFileRepo(Repository):
    '''
    '''

    def __init__(self, fileName, Obj):
        Repository.__init__(self)
        self._fileName = fileName
        self._obj = Obj
        self._objects = readStFromFile(fileName, Obj)

    def add(self, obj):
        Repository.add(self, obj)
        writeStInFile(self._fileName, self.getAll())

    def remove(self, objectID):
        Repository.remove(self, objectID)
        writeStInFile(self._fileName, self.getAll())

    def removeGrade(self, grade):
        Repository.removeGrade(self, grade)(self, grade)
        writeStInFile(self._fileName, self.getAll())

    def update(self, obj):
        Repository.update(self, obj)
        writeStInFile(self._fileName, self.getAll())
