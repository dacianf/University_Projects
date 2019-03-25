'''
Created on 19 Nov 2018

@author: Daci
'''
from domain.student import Student
from controller.operation import Operation
from controller.functionCall import FunctionCall
import unittest
from domain.studentValidator import StudentValidator
from controller.undoController import UndoController
from repository.repo import Repository
from copy import deepcopy
from controller.operationsCascade import OperationsCascade
from controller.controllerException import ControllerException


class StudentController:
    '''
        StudentController operates a repo of students
    '''

    def __init__(self, repo, studentValidator, undoController):
        self._repo = repo
        self._sVal = studentValidator
        self._undo = undoController

    def add(self, student):
        '''
            Adds a student if it's valid in repo
            Input: student - Student obj
        '''
        if not isinstance(student, Student):
            raise TypeError("Student must be an instace of Student class!")
        self._sVal.validate(student)

        undo = FunctionCall(self.remove, student.id)
        redo = FunctionCall(self.add, student)
        op = Operation(redo, undo)
        self._undo.addOperation(op)

        self._repo.add(student)

    def remove(self, studentID, cascadeOpe=None):
        '''
            Removes a student from repo
            Input: studentID - positive integer
        '''
        st = self.findByID(studentID)
        self._repo.remove(studentID)

        undo = FunctionCall(self.add, st)
        redo = FunctionCall(self.remove, studentID)
        op = Operation(redo, undo)
        if cascadeOpe is None:
            self._undo.addOperation(op)
        else:
            op = Operation(redo, undo)
            cascadeOpe.addOp(op)

    def update(self, studentNew):
        '''
            Updates a student's info by its id if studentNew is valid
            Input: studentNew - Student obj
        '''
        if not isinstance(studentNew, Student):
            raise TypeError("Student must be an instace of Student class!")
        self._sVal.validate(studentNew)

        st = self.findByID(studentNew.id)

        undo = FunctionCall(self.update, studentNew)
        redo = FunctionCall(self.update, st)
        op = Operation(redo, undo)
        self._undo.addOperation(op)

        self._repo.update(studentNew)

    def findByID(self, studentID):
        '''
            Find a student from repo
            Input: studentID - positive integer
            Output: student - Student obj with given id
                    - -1 - if there is no such a student
        '''
        x = self._repo.find(studentID)
        if x != -1:
            return self._repo.getAll()[x]
        return -1

    def getAll(self):
        '''
            Returns all students
        '''
        return self._repo.getAll()

    def getStudByGroup(self, group):
        '''
            Returns a list of students who are in the given group
            Input: group - string
            Output: x - list of students
        '''
        x = []
        for stud in self.getAll():
            if stud.group == group:
                x.append(stud)
        return x

    def sortByName(self, lista):
        '''
            Returns a list of students sorted by name
        '''
        return sorted(deepcopy(lista), key=lambda x: x.name)

    def sortByGroup(self, lista):
        '''
            Returns a list of students sorted by group
        '''
        return sorted(deepcopy(lista), key=lambda x: x.group)

    def __str__(self):
        return str(self._repo)


class UnitTestStudentController(unittest.TestCase):
    '''
        Provides Unittests for Student Controller
    '''
    def setUp(self):
        self.s = Student(1, "John", "913")
        self.undo = UndoController()
        self.sCtr = StudentController(Repository(), StudentValidator(), self.undo)

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testAdd(self):
        self.sCtr.add(deepcopy(self.s))
        self.assertEqual(self.sCtr.getAll()[0], self.s)
        self.assertRaises(TypeError, self.sCtr.add, 4)

    def testRmv(self):
        self.sCtr.add(deepcopy(self.s))
        self.s.id = 2
        self.s.name = "Mary"
        self.sCtr.add(deepcopy(self.s))
        self.assertEqual(len(self.sCtr.getAll()), 2)
        self.sCtr.remove(1)
        self.assertEqual(len(self.sCtr.getAll()), 1)
        self.sCtr.remove(2, OperationsCascade())
        self.assertEqual(len(self.sCtr.getAll()), 0)

    def testUpdate(self):
        self.sCtr.add(deepcopy(self.s))
        self.s.id = 2
        self.s.name = "Mary"
        self.sCtr.add(deepcopy(self.s))
        self.sCtr.update(Student(2, "Jane", '321'))
        self.assertEqual(self.sCtr.getAll()[1].name, "Jane")
        self.assertRaises(TypeError, self.sCtr.update, 3)

    def testFind(self):
        self.sCtr.add(deepcopy(self.s))
        self.s.id = 2
        self.s.name = "Mary"
        self.sCtr.add(deepcopy(self.s))
        x = self.sCtr.findByID(2)
        self.assertEqual(x, self.sCtr.getAll()[1])
        x = self.sCtr.findByID(6)
        self.assertEqual(x, -1)

    def testGetByGr(self):
        self.sCtr.add(deepcopy(self.s))
        self.s.id = 2
        self.s.name = "Mary"
        self.sCtr.add(deepcopy(self.s))
        self.sCtr.add(Student(3, "Daci", "912"))
        lg = self.sCtr.getStudByGroup("913")
        self.assertEqual(len(lg), 2)

    def testUndo(self):
        self.sCtr.add(deepcopy(self.s))
        self.assertEqual(len(self.sCtr.getAll()), 1)
        self.sCtr.add(Student(2, "Mary", "913"))
        self.assertEqual(len(self.sCtr.getAll()), 2)
        self.undo.undo()
        self.assertEqual(len(self.sCtr.getAll()), 1)
        self.undo.redo()
        self.assertEqual(len(self.sCtr.getAll()), 2)
        self.assertRaises(ControllerException, self.undo.redo)

    def testRests(self):
        self.sCtr.add(deepcopy(self.s))
        self.s.id = 2
        self.s.name = "Mary"
        self.sCtr.add(deepcopy(self.s))
        self.sCtr.add(Student(3, "Zaci", "912"))
        x = self.sCtr.sortByGroup(self.sCtr.getAll())
        self.assertEqual(x[0], Student(3, "Zaci", "912"))
        x = self.sCtr.sortByName(self.sCtr.getAll())
        self.assertEqual(x[0], Student(1, "John", "913"))
        self.assertIsInstance(str(self.sCtr), str)
