'''
Created on 19 Nov 2018

@author: Daci
'''
import unittest
from domain.studentValidator import StudentValidator
from domain.validatorException import ValidatorException


class Student:
    '''
        Student class has 3 attributes:
            -id- positive integer
            -name- string
            -group- string
        and properties to get and set those
    '''

    def __init__(self, studID, name, group):
        self.__sID = studID
        self.__name = name
        self.__group = group

    @property
    def id(self):
        return self.__sID

    @id.setter
    def id(self, newID):
        self.__sID = newID

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, newName):
        self.__name = newName

    @property
    def group(self):
        return self.__group

    @group.setter
    def group(self, newGroup):
        self.__group = newGroup

    def __le__(self, y):
        return self.id <= y.id

    def __eq__(self, other):
        return self.id == other.id

    def __str__(self):
        return "ID: " + str(self.id).ljust(5) + "Name: " + self.name.ljust(20) + "Group: " + self.group


class UnitTestStudent(unittest.TestCase):
    '''
        Provides Unittests for Student Domain
    '''
    def setUp(self):
        self.v = StudentValidator()
        self.s = Student(1, "Matei", "913")

    def tearDown(self):
        unittest.TestCase.tearDown(self)
        self.s = None
        self.v = None

    def testID(self):
        self.s.id = -5
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.id = 0
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.id = None
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.id = "1"
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.id = 1
        self.assertEqual(self.v.validate(self.s), True)
        self.assertTrue(self.s <= Student(2, "zoro", "913"))
        self.assertTrue(str(self.s))

    def testName(self):
        self.s.name = ""
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.name = 3
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.name = None
        self.assertRaises(ValidatorException, self.v.validate, self.s)

    def testGroup(self):
        self.s.group = ""
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.group = 3
        self.assertRaises(ValidatorException, self.v.validate, self.s)
        self.s.group = None
        self.assertRaises(ValidatorException, self.v.validate, self.s)
