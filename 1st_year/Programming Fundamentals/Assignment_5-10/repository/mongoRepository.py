'''
Created on 4 Dec 2018

@author: Daci
'''
from repository.repo import Repository
from pymongo import MongoClient
from repository.repositoryExceptions import RepoException
from domain.grade import Grade
from domain.assignment import Assignment
from domain.student import Student


class MongoRepository(Repository):
    '''
    '''

    def __init__(self, Obj):
        Repository.__init__(self)
        self._obj = Obj
        if Obj == Student:
            self._db = MongoClient('localhost', 27017).Students_Manager.Students
        elif Obj == Assignment:
            self._db = MongoClient('localhost', 27017).Students_Manager.Assignments
        elif Obj == Grade:
            self._db = MongoClient('localhost', 27017).Students_Manager.Grade
        else:
            raise RepoException("Object must be one of the following types (Student|Assignment|Grade)!")
        self._objects = []
        for dbObj in self._db.find(projection={'_id': False}):
            self._objects.append(Obj(*dbObj.values()))

    def add(self, obj):
        Repository.add(self, obj)
        self.__updateMongoCollection()

    def remove(self, objectID):
        Repository.remove(self, objectID)
        self.__updateMongoCollection()

    def removeGrade(self, grade):
        Repository.removeGrade(self, grade)
        self.__updateMongoCollection()

    def update(self, obj):
        Repository.update(self, obj)
        self.__updateMongoCollection()

    def __updateMongoCollection(self):
        self._db.delete_many({})
        objDict = []
        for obj in self._objects:
            objDict.append(obj.toDict())
        self._db.insert_many(objDict)
