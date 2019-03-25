'''
Created on 19 Nov 2018

@author: Daci
'''
from copy import deepcopy
from domain.grade import Grade
from repository.repositoryExceptions import RepoException
import unittest
from domain.student import Student


class Repository:
    '''
        Repository creates a list of domain's objects and has the following methods
            -add-
            -remove-
            -update-
            -list-
    '''

    def __init__(self):
        self._objects = []

    def add(self, obj):
        '''
            Adds a new object into repo list
            Input: -obj- object
            Output: True - if adding succeded
                    raises RepoException
        '''
        if self.find(obj.id) == -1 or type(obj) == Grade:
            self._objects.append(obj)
            return True

        raise RepoException("An object with this ID already exists!")

    def remove(self, objectID):
        '''
            Removes an object from repo list
            Input: -objID- positive integer
            Output: True - if removing succeded
                    raises RepoException
        '''
        if type(objectID) != int or objectID <= 0:
            raise RepoException("ObjectID must be a positive integer!")
        pos = self.find(objectID)
        if pos != -1:
            del self._objects[pos]
            return True
        raise RepoException("An object with this ID does not exit!")

    def removeGrade(self, grade):
        '''
            Removes a grade from repo list
            Input: -grade- Grade object
            Output: True - if removing succeded
                    raises RepoException
        '''
        for gr in self._objects:
            if type(gr) != Grade or type(grade) != Grade:
                raise RepoException("This method can only be used with Grade objects!")
        for i in range(len(self._objects)):
            if self._objects[i] == grade:
                del self._objects[i]
                return True
        raise RepoException("In this repository does not exit such a grade!")

    def update(self, obj):
        '''
            Updates an object from repo list
            Input: -obj- object
            Output: True - if update succeded
                    False - otherwise
        '''
        if type(obj) == Grade:
            for i in range(len(self._objects)):
                if self._objects[i].assignID == obj.assignID and self._objects[i].studentID == obj.studentID:
                    self._objects[i] = deepcopy(obj)
                    return True
        else:
            pos = self.find(obj.id)
            if pos != -1 and type(obj) != Grade:
                    self._objects[pos] = deepcopy(obj)
                    return True
            raise RepoException("There is no object with such id in the database!")

    def find(self, objectID):
        '''
            Finds an object from repo list
            Input: -objID- positive integer
            Output: - i - int which is position of element with given id
                    - -1 - if there is no object with given id
        '''
        if type(objectID) != int or objectID <= 0:
            raise RepoException("ObjectID must be a positive integer!")
        for i in range(len(self._objects)):
            if self._objects[i].id == objectID:
                return i
        return -1

    def getAll(self):
        return self._objects

    def __len__(self):
        return len(self._objects)

    def __str__(self):
        r = ""
        for e in self._objects:
            r += str(e)
            r += "\n"
        return r


class UnitTestRepo(unittest.TestCase):
    '''
    '''

    def setUp(self):
        self.s = Student(1, "John", "315")
        self.g = Grade(1, 1, 0.0)
        self.r = Repository()

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testAdd(self):
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.assertRaises(RepoException, self.r.add, self.s)
        self.s.id = 2
        self.assertTrue(self.r.add(self.s))

    def testRmv(self):
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 2
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 3
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 4
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.assertEqual(len(self.r), 4)
        self.assertTrue(self.r.remove(3))
        self.assertEqual(len(self.r), 3)
        self.assertRaises(RepoException, self.r.remove, 12)
        self.assertRaises(RepoException, self.r.remove, -1)

    def testUpdate(self):
        self.r.add(deepcopy(self.s))
        self.s.name = "Marry"
        self.assertTrue(self.r.update(deepcopy(self.s)))
        self.s.id = 5
        self.assertRaises(RepoException, self.r.update, self.s)
        self.r.remove(1)
        self.r.add(deepcopy(self.g))
        self.g.grade = 4.25
        self.assertTrue(self.r.update(deepcopy(self.g)))

    def testFind(self):
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 2
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 3
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 4
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.assertEqual(self.r.find(1), 0)
        self.assertEqual(self.r.find(3), 2)
        self.assertEqual(self.r.find(11), -1)
        self.assertRaises(RepoException, self.r.find, -1)
        self.assertRaises(RepoException, self.r.find, "d")

    def testGetAll(self):
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.assertEqual(len(self.r.getAll()), 1)
        self.s.id = 2
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 3
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.s.id = 4
        self.assertTrue(self.r.add(deepcopy(self.s)))
        self.assertEqual(len(self.r.getAll()), 4)

    def testRemoveGrade(self):
        gr = Grade(2, 3, 6.3)
        self.r.add(gr)
        self.r.add(self.g)
        self.assertEqual(len(self.r.getAll()), 2)
        self.assertRaises(RepoException, self.r.removeGrade, self.s)
        self.r.removeGrade(gr)
        self.assertEqual(len(self.r.getAll()), 1)
        self.assertRaises(RepoException, self.r.removeGrade, gr)

    def testRepoEx(self):
        x = RepoException("Test")
        self.assertEqual(x.messages, "Test")
        self.assertEqual(str(x), "Test")
        self.r.add(self.g)
        self.assertEqual(type(str(self.r)), str)
