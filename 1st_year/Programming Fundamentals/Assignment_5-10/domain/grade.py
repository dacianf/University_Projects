'''
Created on 19 Nov 2018

@author: Daci
'''
import unittest
from domain.gradeValidator import GradeValidator
from domain.validatorException import ValidatorException


class Grade:
    '''
        Student class has 3 attributes:
            -assignmentID- positive integer
            -studentID- positive integer
            -grade- float belonging [0,10]
        and properties to get and set those
    '''

    def __init__(self, assignmentID, studentID, grade):
        self.__gID = 1
        self.__assignmentID = assignmentID
        self.__studentID = studentID
        self.__grade = grade

    @property
    def id(self):
        return self.__gID

    @id.setter
    def id(self, newID):
        self.__gID = newID

    @property
    def assignID(self):
        return self.__assignmentID

    @assignID.setter
    def assignID(self, newAssignID):
        self.__assignmentID = newAssignID

    @property
    def studentID(self):
        return self.__studentID

    @studentID.setter
    def studentID(self, newStudentID):
        self.__studentID = newStudentID

    @property
    def grade(self):
        return self.__grade

    @grade.setter
    def grade(self, newGrade):
        self.__grade = newGrade

    def toDict(self):
        return {"AssignmentID": self.assignID, "StudentID": self.studentID, "Grade": self.grade}

    def __eq__(self, other):
        return self.assignID == other.assignID and self.studentID == other.studentID and self.grade == other.grade

    def __repr__(self):
        return "Grade(" + str(self.assignID) + "," + str(self.studentID) + "," + str(self.grade) + ")"

    def __str__(self):
        return "AssignmentID: " + str(self.assignID).ljust(5) + "StudentID: " + str(self.studentID).ljust(5) + "Grade: " + str(self.grade)


class UnitTestGrade(unittest.TestCase):
    '''
    '''

    def setUp(self):
        self.g = Grade(1, 1, 0.0)
        self.v = GradeValidator()

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testID(self):
        self.assertTrue(self.v.validate, self.g)
        self.g.assignID = 0
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.assignID = -1
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.assignID = "1"
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.assignID = 1
        self.g.studentID = 0
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.studentID = -1
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.studentID = "1"
        self.assertRaises(ValidatorException, self.v.validate, self.g)

    def testGrade(self):
        self.g.grade = -1
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.grade = 11
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.grade = -0.1
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.grade = 10.1
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.grade = "3"
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.id = 4
        self.g.grade = 3.2
        self.assertTrue(str(self.g))
        self.assertTrue(self.g.id == 4)
        self.assertEqual(self.g, Grade(1, 1, 3.2))
        self.g.id = "2"
        self.assertRaises(ValidatorException, self.v.validate, self.g)
        self.g.id = 2
        self.assertEqual(self.v.validate(self.g), True)

    def testValidator(self):
        x = ValidatorException(["Blah", "Blah2"])
        self.assertEqual(len(x.messages), 2)
        self.assertTrue(str(x))
        self.assertTrue(repr(Grade(1, 2, 0)))
