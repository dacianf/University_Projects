'''
Created on 20 Nov 2018

@author: Daci
'''
from datetime import date
from UI.studentGradeDTO import StudentGradeDTO
from UI.studentLateDTO import StudentLateDTO
from UI.assignmentGradeDTO import AssignmentGradeDTO
import unittest
from controller.gradeController import GradeController
from repository.repo import Repository
from domain.gradeValidator import GradeValidator
from controller.assignmentController import AssignmnetController
from controller.studentController import StudentController
from controller.undoController import UndoController
from UI.populateRepo import populateStCtrSTATIC, populateAsCtrSTATIC
from domain.assignmentValidator import AssignmentValidator
from domain.studentValidator import StudentValidator
from domain.grade import Grade
from auxiliary.filter_sort import sortF


class Statistics:
    '''
    All students who received a given assignment, ordered alphabetically or by average grade for that assignment.
    All students who are late in handing in at least one assignment. These are all the students who have an ungraded assignment for which the deadline has passed.
    Students with the best school situation, sorted in descending order of the average grade received for all assignments
    All assignments for which there is at least one grade, sorted in descending order of the average grade received by all students who received that assignment.
    '''

    def __init__(self, gradeController):
        self._control = gradeController

    def getStudGivenAssig(self, assignID):
        '''
            Gets a list of all students who received a given assignment sorted alph
            Input: assignID - positive int
            Output: stud - list of students
        '''
        x = self._control.my_filterGradesBy(None, assignID)
        stud = []
        for g in x:
            sg = StudentGradeDTO(self._control.student.findByID(g.studentID).name, g.grade)
            stud.append(sg)
        return sortF(stud, lambda student: student.name)

    def getLateStuds(self):
        '''
            Gets a list of all students who didnt't submit the assignment in time
            Output: stud - list of students
        '''
        lates = []
        stAS = []
        for st in self._control.student.getAll():
            grAS = self._control.my_filterGradesBy(st.id)
            for gr in grAS:
                if gr.grade == 0.0:
                    a = self._control.assignment.findByID(gr.assignID)
                    d, m, y = a.deadline.split("/")
                    if date.today() > date(int(y), int(m), int(d)):
                        stAS.append(self._control.assignment.findByID(gr.assignID))
            if len(stAS) > 0:
                lates.append(StudentLateDTO(st, stAS))
            stAS = []
        return lates

    def getStudBestGrSchool(self):
        '''
            Gets a list of all students id and average grade who received a given assignment sorted descending
            Output: bg - list of lists of studID and average grade
        '''
        bg = []
        students = self._control.student.getAll()
        for st in students:
            stGra = self._control.my_filterGradesBy(st.id)
            kGr = 0
            avg = 0
            for gr in stGra:
                if gr.grade != 0.0:
                    kGr += 1
                    avg += gr.grade
            if kGr != 0:
                avg /= kGr
                bg.append(StudentGradeDTO(st.name, round(avg, 2)))
            else:
                bg.append(StudentGradeDTO(st.name, 0.0))
        return sortF(bg, lambda x: x.grade, reverse=True)

    def getAssigByGrade(self):
        '''
            Gets a list of all assignments id and average grade sorted descending where is at least one grade
            Output: r - list of lists of assignmentIDs and average grades
        '''
        r = []
        assign = self._control.assignment.getAll()
        for a in assign:
            assGra = self._control.my_filterGradesBy(None, a.id)
            kGr = 0
            avg = 0
            for gr in assGra:
                if gr.grade != 0.0:
                    kGr += 1
                avg += gr.grade
            if kGr != 0:
                avg /= kGr
                r.append(AssignmentGradeDTO(a, round(avg, 2)))
        return sortF(r, lambda x: x.grade, reverse=True)


class UnitTestsStatistics(unittest.TestCase):
    '''
        Provides Unittests for Statistic class
    '''

    def setUp(self):
        self._undo = UndoController()
        self._stCtr = StudentController(Repository(), StudentValidator(), self._undo)
        self._asCtr = AssignmnetController(Repository(), AssignmentValidator(), self._undo)
        self._grCtr = GradeController(Repository(), GradeValidator(), self._stCtr, self._asCtr, self._undo)
        self._stat = Statistics(self._grCtr)
        populateAsCtrSTATIC(self._asCtr)
        populateStCtrSTATIC(self._stCtr)

    def tearDown(self):
        unittest.TestCase.tearDown(self)

    def testSta1(self):
        self._grCtr.giveAssigToGroup(3, "12")
        x = self._stat.getStudGivenAssig(3)
        self.assertEqual(len(x), 2)

    def testStat2(self):
        self._grCtr.giveAssigToGroup(3, "12")
        self._grCtr.giveAssigToGroup(3, "10")
        self._grCtr.add(Grade(3, 8, 8.0))
        self._grCtr.add(Grade(5, 3, 5.5))
        x = self._stat.getLateStuds()
        self.assertEqual(len(x), 8)

    def testStat3(self):
        self._grCtr.giveAssigToGroup(3, "10")
        self._grCtr.add(Grade(1, 8, 6.0))
        self._grCtr.add(Grade(3, 8, 8.0))
        self._grCtr.add(Grade(5, 3, 5.5))
        self._grCtr.add(Grade(2, 8, 10.0))
        self._grCtr.add(Grade(4, 2, 7.0))
        self._grCtr.add(Grade(6, 3, 5.5))
        x = self._stat.getStudBestGrSchool()
        self.assertEqual(len(x), 10)
        self.assertEqual(x[0].grade, 8.0)
        self.assertEqual(x[1].grade, 7.0)
        self.assertEqual(x[2].grade, 5.5)
        self.assertEqual(x[3].grade, 0.0)

    def testStat4(self):
        self._grCtr.giveAssigToGroup(3, "10")
        self._grCtr.add(Grade(1, 8, 6.0))
        self._grCtr.add(Grade(3, 8, 8.0))
        x = self._stat.getAssigByGrade()
        self.assertEqual(len(x), 2)
        self.assertEqual(x[0].grade, 8.0)
        self.assertEqual(x[1].grade, 6.0)
