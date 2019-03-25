'''
Created on 19 Nov 2018

@author: Daci
'''
from domain.assignment import Assignment
from controller.operation import Operation
from controller.functionCall import FunctionCall
import unittest
from repository.repo import Repository
from domain.assignmentValidator import AssignmentValidator
from controller.undoController import UndoController
from copy import deepcopy
from controller.operationsCascade import OperationsCascade


class AssignmnetController:
    '''
        AssignmnetController operates a repo of assignments
    '''

    def __init__(self, repo, assignmnetValidator, undoController):
        self._repo = repo
        self._aVal = assignmnetValidator
        self._undo = undoController

    def add(self, assignmnet):
        '''
            Adds in repo an assignmnets if it's valid
            Input: assignmnet - Assignmnet obj
        '''
        if not isinstance(assignmnet, Assignment):
            raise TypeError("Assignment must be an instace of Assignment class!")
        self._aVal.validate(assignmnet)

        undo = FunctionCall(self.remove, assignmnet.id)
        redo = FunctionCall(self.add, assignmnet)
        op = Operation(redo, undo)
        self._undo.addOperation(op)

        self._repo.add(assignmnet)

    def remove(self, assignmnetID, cascadeOP=None):
        '''
            Removes an assignmnet from repo
            Input: assignmnetID - positive integer
        '''
        assignment = self.findByID(assignmnetID)
        self._repo.remove(assignmnetID)

        undo = FunctionCall(self.add, assignment)
        redo = FunctionCall(self.remove, assignmnetID)
        op = Operation(redo, undo)
        if cascadeOP:
            cascadeOP.addOp(op)
        else:
            self._undo.addOperation(op)

    def update(self, assignmnetNew):
        '''
            Updates an assignmnet info by its id if assignmnetNew is valid
            Input: assignmnetNew - Assignmnet obj
        '''
        if not isinstance(assignmnetNew, Assignment):
            raise TypeError("Assignment must be an instace of Assignment class!")
        self._aVal.validate(assignmnetNew)
        assignmentOld = self.findByID(assignmnetNew.id)

        undo = FunctionCall(self.update, assignmentOld)
        redo = FunctionCall(self.update, assignmnetNew)
        op = Operation(redo, undo)
        self._undo.addOperation(op)

        self._repo.update(assignmnetNew)

    def findByID(self, assignmnetID):
        '''
            Find an assignmnet from repo
            Input: assignmnetID - positive integer
            Output: assignmnet - Assignmnet obj with given id
                    - -1 - if there is no such an assignmnet
        '''
        x = self._repo.find(assignmnetID)
        if x != -1:
            return self._repo.getAll()[self._repo.find(assignmnetID)]
        return -1

    def getAll(self):
        '''
            Returns all assignments
        '''
        return self._repo.getAll()

    def __str__(self):
        return str(self._repo)


class UnitTestAssignmentController(unittest.TestCase):
    '''
        Blah
    '''
    def setUp(self):
        self.a = Assignment(1, "ASC", "08/12/2018")
        self.aCtr = AssignmnetController(Repository(), AssignmentValidator(), UndoController())

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testAdd(self):
        self.aCtr.add(deepcopy(self.a))
        self.assertEqual(self.aCtr.getAll()[0], self.a)
        self.assertRaises(TypeError, self.aCtr.add, 4)

    def testRmv(self):
        self.aCtr.add(deepcopy(self.a))
        self.aCtr.add(Assignment(2, "Algebra", "24/01/2019"))
        self.assertEqual(len(self.aCtr.getAll()), 2)
        self.aCtr.remove(1)
        self.assertEqual(len(self.aCtr.getAll()), 1)
        self.assertEqual(self.aCtr.getAll()[0], Assignment(2, "Algebra", "24/01/2019"))
        self.aCtr.remove(2, OperationsCascade())

    def testUpdate(self):
        self.aCtr.add(deepcopy(self.a))
        self.aCtr.add(Assignment(2, "Algebra", "24/01/2019"))
        self.aCtr.update(Assignment(1, "Bra", "14/01/2019"))
        self.assertEqual(self.aCtr.getAll()[0].description, "Bra")
        self.assertRaises(TypeError, self.aCtr.update, 4)

    def testFind(self):
        self.aCtr.add(deepcopy(self.a))
        self.aCtr.add(Assignment(2, "Algebra", "24/01/2019"))
        x = self.aCtr.findByID(1)
        self.assertEqual(x, self.a)
        x = self.aCtr.findByID(5)
        self.assertEqual(x, -1)
        self.assertIsInstance(str(self.aCtr), str)
