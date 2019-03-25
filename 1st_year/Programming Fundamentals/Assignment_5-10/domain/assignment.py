'''
Created on 19 Nov 2018

@author: Daci
'''
import unittest
from domain.assignmentValidator import AssignmentValidator
from domain.validatorException import ValidatorException


class Assignment:
    '''
        Assignment class has 3 attributes:
            -id- positive integer
            -description- string
            -deadline- date of form dd/mm/yyyy
        and properties to get and set those values
    '''

    def __init__(self, assigID, description, deadline):
        self.__aID = assigID
        self.__desc = description
        self.__deadline = deadline

    @property
    def id(self):
        return self.__aID

    @id.setter
    def id(self, newID):
        self.__aID = newID

    @property
    def description(self):
        return self.__desc

    @description.setter
    def description(self, newDescription):
        self.__desc = newDescription

    @property
    def deadline(self):
        return self.__deadline

    @deadline.setter
    def deadline(self, newDeadline):
        self.__deadline = newDeadline

    def __eq__(self, other):
        return self.id == other.id

    def toDict(self):
        return {"ID": self.id, "Description": self.description, "Deadline": self.deadline}

    def __repr__(self):
        return "Assignment(" + str(self.id) + "," + self.description + "," + self.deadline + ")"

    def __str__(self):
        return "ID: " + str(self.id).ljust(5) + "Description: " + self.description.ljust(28) + "Deadline: " + self.deadline


class UnitTestAssignmnet(unittest.TestCase):
    '''
        Provides Unittests for Assignment domain
    '''

    def setUp(self):
        self.a = Assignment(1, "FP", "01/02/2019")
        self.v = AssignmentValidator()

    def tearDown(self):
        unittest.TestCase.tearDown(self)
        self.a = None
        self.v = None

    def testID(self):
        self.assertEqual(self.v.validate(self.a), True)
        self.a.id = 0
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.id = -1
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.id = "d"
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.id = "1"
        self.assertRaises(ValidatorException, self.v.validate, self.a)

    def testDescription(self):
        self.a.description = ""
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.description = 5
        self.assertRaises(ValidatorException, self.v.validate, self.a)

    def testDeadline(self):
        self.a.deadline = 5
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.deadline = "-1/5/1000"
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.deadline = "30/2/2000"
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.deadline = "32/5/2000"
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.deadline = "5/0/1200"
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.a.deadline = "5/13/2010"
        self.assertRaises(ValidatorException, self.v.validate, self.a)
        self.assertTrue(str(self.a))
        self.assertTrue(repr(self.a))
