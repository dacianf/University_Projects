'''
Created on 7 Dec 2018

@author: Daci
'''
from repository.repo import Repository
from settings.fileOperations import readFromJson, writeIntoJson


class JsonRepository(Repository):
    '''
    '''

    def __init__(self, fileName, Obj):
        Repository.__init__(self)
        self._fileName = fileName
        self._obj = Obj
        self._objects = readFromJson(fileName, Obj)

    def add(self, obj):
        Repository.add(self, obj)
        writeIntoJson(self._fileName, self.getAll())

    def remove(self, objectID):
        Repository.remove(self, objectID)
        writeIntoJson(self._fileName, self.getAll())

    def removeGrade(self, grade):
        Repository.removeGrade(self, grade)
        writeIntoJson(self._fileName, self.getAll())

    def update(self, obj):
        Repository.update(self, obj)
        writeIntoJson(self._fileName, self.getAll())
