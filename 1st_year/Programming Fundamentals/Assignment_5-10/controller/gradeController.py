'''
Created on 19 Nov 2018

@author: Daci
'''
from domain.grade import Grade
from domain.gradeValidator import GradeValidator
from controller.operation import Operation
from controller.functionCall import FunctionCall
from controller.controllerException import ControllerException
from controller.operationsCascade import OperationsCascade
import unittest
from controller.undoController import UndoController
from controller.studentController import StudentController
from controller.assignmentController import AssignmnetController
from repository.repo import Repository
from domain.studentValidator import StudentValidator
from domain.assignmentValidator import AssignmentValidator
from domain.assignment import Assignment
from domain.student import Student
from auxiliary.filter_sort import filterF


class GradeController:
    '''
         Operates grades repo, studentController and assignmentController
    '''

    def __init__(self, repo, gradeValidator, studentController, assignmentController, undoCtr):
        '''
            Creats a repo, gradeValidator, studentController, assignmentController, undoCtr
        '''
        self._repo = repo
        self._gradeValid = gradeValidator
        self._stud = studentController
        self._assig = assignmentController
        self._undo = undoCtr

    @property
    def student(self):
        return self._stud

    @property
    def assignment(self):
        return self._assig

    def add(self, grade, cascade=None):
        '''
            Adds in repo a grade if it's valid
            Input: grade - Grade obj
        '''
        if not isinstance(grade, Grade):
            raise TypeError("Grade must be an instace of Grade class!")
        self._gradeValid.validate(grade)

        if not cascade:
            undo = FunctionCall(self.remove, grade.studentID, grade.assignID)
            redo = FunctionCall(self.add, grade)
            op = Operation(redo, undo)
            self._undo.addOperation(op)

        self._repo.add(grade)

    def remove(self, studID, assigID, cascade=None):
        '''
            Removes a grade
            Input: studID - positive int
                   assigID - positive int
            Output: True - if removing succeded
                    False - otherwise
        '''
        fd = self.findByID(studID, assigID)
        if type(fd) != Grade:
            raise ValueError("This grade does not exist!")
        self._repo.removeGrade(fd)

        undo = FunctionCall(self.add, fd)
        redo = FunctionCall(self.remove, fd.studentID, fd.assignID)
        op = Operation(redo, undo)
        if not cascade:
            self._undo.addOperation(op)

    def removeStud(self, studID):
        '''
            Removes a student from repo and its grades
            Input: studentID - positive integer
            Output: True - if removing succeded
                    False - otherwise
        '''
        cmds = OperationsCascade()
        x = self._stud.findByID(studID)
        if type(x) == Student:
            gr = self.getAll()
            for i in range(len(gr) - 1, -1, -1):
                if gr[i].studentID == studID:
                    redo = FunctionCall(self.remove, gr[i]. studentID, gr[i].assignID)
                    undo = FunctionCall(self.add, gr[i])
                    op = Operation(redo, undo)
                    cmds.addOp(op)
                    self._repo.removeGrade(gr[i])
            self._stud.remove(studID, cmds)
            cmds.reverseOper()
            self._undo.addOperation(cmds)
            return True
        return False

    def removeAssign(self, assignID):
        '''
            Removes an assignmnet from repo and also its grades
            Input: assignmnetID - positive integer
            Output: True - if removing succeded
                    False - otherwise
        '''
        cmds = OperationsCascade()
        x = self._assig.findByID(assignID)
        if type(x) == Assignment:
            gr = self.getAll()
            for i in range(len(gr) - 1, -1, -1):
                if gr[i].assignID == assignID:
                    redo = FunctionCall(self.remove, gr[i].studentID, gr[i].assignID)
                    undo = FunctionCall(self.add, gr[i])
                    op = Operation(redo, undo)
                    cmds.addOp(op)
                    self._repo.removeGrade(gr[i])
            self._assig.remove(assignID, cmds)
            cmds.reverseOper()
            self._undo.addOperation(cmds)
            return True
        return False

    def update(self, newGrade):
        '''
            Updates a grade's info by its id if newGrade is valid
            Input: newGrade - Grade obj
        '''
        if not isinstance(newGrade, Grade):
            raise TypeError("Grade must be an instace of Grade class!")
        self._gradeValid.validate(newGrade)

        oldGrade = self.findByID(newGrade.studentID, newGrade.assignID)
        undo = FunctionCall(self.update, oldGrade)
        redo = FunctionCall(self.update, newGrade)
        op = Operation(redo, undo)
        self._undo.addOperation(op)

        self._repo.update(newGrade)

    def findByID(self, studID, assigID):
        '''
            Find an assignmnet from repo
            Input: studID - positive integer
                   assigID - positive integer
            Output: grade - Grade obj
                    - -1 - if no grade found
        '''
        grades = self.getAll()
        for i in range(len(grades)):
            if grades[i].studentID == studID and grades[i].assignID == assigID:
                return grades[i]
        return -1

    def giveAssigToGroup(self, assigID, group):
        '''
            Sets an assignment to a group
            Input: assignmnetID - positive integer
                   group - string
        '''
        self._assig.findByID(assigID)
        studs = self._stud.getStudByGroup(group)
        if len(studs) == 0:
            raise ValueError("There is no such a group!")
        cascade = OperationsCascade()
        for st in studs:
            self.setAssigStud(assigID, st.id, cascade)
        cascade.reverseOper()
        self._undo.addOperation(cascade)

    def setAssigStud(self, assignmentID, studentID, cascade=None):
        '''
            Assign an assignment to a student by adding in grades list a grade
            assignmenID, studentID and a mark of 0
            Input: - assignmentID - int >=0
                   - studentID - int >=0
            Output: - True - if setting succeded
                    - Fale - otherwise
        '''
        if self.filterGradesBy(studentID, assignmentID) == []:
            redo = FunctionCall(self.setAssigStud, assignmentID, studentID, 0.0)
            undo = FunctionCall(self.remove, studentID, assignmentID, True)
            if not isinstance(cascade, OperationsCascade):
                self._undo.addOperation(Operation(redo, undo))
            else:
                cascade.addOp(Operation(redo, undo))
            self.add(Grade(assignmentID, studentID, 0.0), True)
            return True
        return False

    def setGrade(self, studID, assigID, grade):
        '''
            Sets grade at a given assignment of a given student
            Input: studID - positive integer
                   assigID - positive int
                   grade - float in [0,10]
            Output: True - if setting succeded
                    False - otherwise
        '''
        newGrade = Grade(assigID, studID, grade)
        GradeValidator().validate(newGrade)
        oldGrade = self.findByID(studID, assigID)
        if type(oldGrade) != Grade:
            raise ValueError("There does not exist such a grade!")
        if oldGrade.grade != 0.0:
            raise ControllerException("This grade was already assigned!")
        self.update(newGrade)
        return True

    def getAll(self):
        '''
            Returns all grades
        '''
        return self._repo

    def filterGradesBy(self, studentID=None, assignmentID=None):
        '''
            Returns a list of grades which:
                if studentID != None => all grades of a student
                if assignmentID != None => all grades bound to an assignment
                if both exists will return that element if it exists in list
                if both are None => list of all grades
                otherwise => empty list
            Input: studID - positive int, none by default
                   assignmentID - positive int, none by default
            Output: x - list of grades
        '''
        x = []
        for gr in self.getAll():
            if assignmentID and not studentID:
                if gr.assignID == assignmentID:
                    x.append(gr)
            elif studentID and not assignmentID:
                if gr.studentID == studentID:
                    x.append(gr)
            elif studentID and assignmentID:
                if gr.studentID == studentID and gr.assignID == assignmentID:
                    x.append(gr)
            else:
                return self.getAll()
        return x

    def my_filterGradesBy(self, studentID=None, assignmentID=None):
        if assignmentID and not studentID:
            return filterF(self._repo, key=lambda x: x.assignID == assignmentID)
        elif studentID and not assignmentID:
            return filterF(self._repo, key=lambda x: x.studentID == studentID)
        else:
            return filterF(self._repo)

    def getStudUngrade(self, studID):
        '''
            Returns a list of ungraded grades of a student
            Input: studID - positive int
            Output: r - list of grades
        '''
        gr = self.filterGradesBy(studID)
        r = []
        for g in gr:
            if g.grade == 0.0:
                r.append(g)
        return r

    def __str__(self):
        return str(self._repo)


class UnitTestGradeController(unittest.TestCase):
    '''
    '''

    def setUp(self):
        self.undo = UndoController()
        self.stCtr = StudentController(Repository(), StudentValidator(), self.undo)
        self.asCtr = AssignmnetController(Repository(), AssignmentValidator(), self.undo)
        self.grade = Grade(1, 1, 5.0)
        self._grCtr = GradeController(Repository(), GradeValidator(), self.stCtr, self.asCtr, self.undo)

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testAdd(self):
        self.assertEqual(len(self._grCtr.getAll()), 0)
        self._grCtr.add(self.grade)
        self.assertEqual(len(self._grCtr.getAll()), 1)
        print(self._grCtr.getAll())
        self._grCtr.add(Grade(3, 2, 2.2))
        self.assertEqual(len(self._grCtr.getAll()), 2)
        self.undo.undo()
        self.undo.undo()
        self.assertEqual(len(self._grCtr.getAll()), 0)
        self.assertRaises(ControllerException, self.undo.undo)
        self.assertRaises(TypeError, self._grCtr.add, 1)

    def testRemoveGr(self):
        self._grCtr.add(self.grade)
        self._grCtr.add(Grade(3, 2, 2.2))
        self.assertEqual(len(self._grCtr.getAll()), 2)
        self._grCtr.remove(1, 1)
        self.assertEqual(len(self._grCtr.getAll()), 1)
        self.assertEqual(self._grCtr.getAll()[0], Grade(3, 2, 2.2))
        self.assertRaises(ValueError, self._grCtr.remove, 1, 1)

    def testRmvStGr(self):
        self._grCtr.student.add(Student(1, "John", "913"))
        self.stCtr.add(Student(2, "Mary", "913"))
        self.assertEqual(len(self.stCtr.getAll()), 2)
        self._grCtr.add(Grade(3, 1, 2.0))
        self._grCtr.add(Grade(4, 1, 7.0))
        self._grCtr.add(Grade(2, 1, 5.0))
        self._grCtr.add(Grade(2, 2, 3.0))
        self.assertEqual(len(self._grCtr.getAll()), 4)
        self._grCtr.removeStud(1)
        self.assertEqual(len(self.stCtr.getAll()), 1)
        self.assertEqual(len(self._grCtr.getAll()), 1)
        self.undo.undo()
        self.assertEqual(len(self.stCtr.getAll()), 2)
        self.assertEqual(len(self._grCtr.getAll()), 4)
        self.undo.redo()
        self.assertEqual(self.stCtr.getAll()[0], Student(2, "Mary", "913"))
        self.assertEqual(self._grCtr.getAll()[0], Grade(2, 2, 3.0))
        self.assertFalse(self._grCtr.removeStud(1))

    def testRmvAsGr(self):
        self._grCtr.assignment.add(Assignment(1, "ASC", "8/10/2018"))
        self.asCtr.add(Assignment(2, "FP", "10/10/2018"))
        self.assertEqual(len(self.asCtr.getAll()), 2)
        self._grCtr.add(Grade(1, 1, 2.0))
        self._grCtr.add(Grade(1, 2, 7.0))
        self._grCtr.add(Grade(2, 1, 5.0))
        self._grCtr.add(Grade(2, 2, 3.0))
        self.undo.undo()
        self.undo.undo()
        self._grCtr.add(Grade(2, 1, 8.0))
        self._grCtr.add(Grade(2, 2, 9.0))
        self.assertEqual(len(self._grCtr.getAll()), 4)
        self._grCtr.removeAssign(2)
        self.assertEqual(len(self.asCtr.getAll()), 1)
        self.assertEqual(len(self._grCtr.getAll()), 2)
        self.undo.undo()
        self.assertEqual(len(self.asCtr.getAll()), 2)
        self.assertEqual(len(self._grCtr.getAll()), 4)
        self.undo.redo()
        self.assertEqual(self._grCtr.getAll()[1], Grade(1, 2, 7.0))
        self.assertFalse(self._grCtr.removeAssign(2))

    def testUpdate(self):
        self._grCtr.add(Grade(2, 1, 0.0))
        self._grCtr.add(Grade(1, 1, 2.0))
        self._grCtr.update(Grade(1, 1, 3.25))
        self.assertEqual(self._grCtr.getAll()[1], Grade(1, 1, 3.25))
        self.assertRaises(TypeError, self._grCtr.update, 1)

    def testFindByID(self):
        self._grCtr.add(Grade(2, 1, 0.0))
        self._grCtr.add(Grade(1, 1, 2.0))
        x = self._grCtr.findByID(1, 1)
        self.assertEqual(x, Grade(1, 1, 2.0))
        x = self._grCtr.findByID(3, 1)
        self.assertEqual(x, -1)
        x = self._grCtr.filterGradesBy(1, 1)
        self.assertEqual(x[0], Grade(1, 1, 2.0))
        x = self._grCtr.filterGradesBy(3, 1)
        self.assertEqual(x, [])

    def testGiveAssign(self):
        self.stCtr.add(Student(1, "John", "913"))
        self.stCtr.add(Student(2, "Mary", "913"))
        self.stCtr.add(Student(3, "Oliver", "914"))
        self.stCtr.add(Student(4, "Greg", "913"))
        self.stCtr.add(Student(5, "Silvia", "914"))
        self.assertEqual(len(self.stCtr.getAll()), 5)
        self.asCtr.add(Assignment(1, "ASC", "08/12/2018"))
        self.asCtr.add(Assignment(2, "FP", "29/11/2018"))
        self.assertEqual(len(self.asCtr.getAll()), 2)
        self._grCtr.giveAssigToGroup(2, "913")
        self.assertEqual(len(self._grCtr.getAll()), 3)
        self._grCtr.giveAssigToGroup(1, "914")
        self.assertEqual(len(self._grCtr.getAll()), 5)
        self.undo.undo()
        self.undo.undo()
        self._grCtr.setAssigStud(2, 3)
        self.assertEqual(len(self._grCtr.getAll()), 1)
        self.assertEqual(self._grCtr.getAll()[0], Grade(2, 3, 0.0))
        self.assertRaises(ValueError, self._grCtr.giveAssigToGroup, 5, "dsadas2")
        self.assertFalse(self._grCtr.setAssigStud(2, 3))

    def testSetGrade(self):
        self._grCtr.add(Grade(2, 1, 0.0))
        self._grCtr.add(Grade(1, 1, 2.0))
        self.assertTrue(self._grCtr.setGrade(1, 2, 9.0))
        self.assertEqual(self._grCtr.getAll()[0], Grade(2, 1, 9.0))
        self.undo.undo()
        self.assertRaises(ControllerException, self._grCtr.setGrade, 1, 1, 2.3)
        self.assertRaises(ValueError, self._grCtr.setGrade, 3, 1, 2.3)

    def testFilter(self):
        self._grCtr.add(Grade(2, 1, 0.0))
        self._grCtr.add(Grade(1, 1, 2.0))
        self._grCtr.add(Grade(2, 2, 3.0))
        self._grCtr.add(Grade(4, 2, 0.0))
        self._grCtr.add(Grade(5, 1, 5.0))
        x = self._grCtr.filterGradesBy(1, 1)
        self.assertEqual(x[0], Grade(1, 1, 2.0))
        x = self._grCtr.filterGradesBy(3, 1)
        self.assertEqual(x, [])
        x = self._grCtr.filterGradesBy(2)
        self.assertEqual(len(x), 2)
        x = self._grCtr.filterGradesBy(1)
        self.assertEqual(len(x), 3)
        x = self._grCtr.filterGradesBy(None, 3)
        self.assertEqual(len(x), 0)
        x = self._grCtr.filterGradesBy(None, 2)
        self.assertEqual(len(x), 2)
        x = self._grCtr.filterGradesBy()
        self.assertEqual(len(x), 5)

    def testUngradeStud(self):
        self._grCtr.add(Grade(2, 1, 0.0))
        self._grCtr.add(Grade(1, 1, 2.0))
        self._grCtr.add(Grade(2, 3, 3.0))
        self._grCtr.add(Grade(4, 2, 0.0))
        self._grCtr.add(Grade(3, 2, 0.0))
        x = self._grCtr.getStudUngrade(1)
        self.assertEqual(len(x), 1)
        x = self._grCtr.getStudUngrade(2)
        self.assertEqual(len(x), 2)
        x = self._grCtr.getStudUngrade(3)
        self.assertEqual(len(x), 0)
        self.assertIsInstance(str(self._grCtr), str)

    def testException(self):
        x = ControllerException("TEst")
        self.assertTrue(x.messages)
        self.assertTrue(str(x))
