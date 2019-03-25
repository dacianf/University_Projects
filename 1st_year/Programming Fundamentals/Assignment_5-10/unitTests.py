'''
Created on 27 Nov 2018

@author: Daci
'''
from domain.assignment import UnitTestAssignmnet
from domain.grade import UnitTestGrade
from domain.student import UnitTestStudent
from repository.repo import UnitTestRepo
from controller.studentController import UnitTestStudentController
from controller.assignmentController import UnitTestAssignmentController
from controller.gradeController import UnitTestGradeController
from statistics.statistics import UnitTestsStatistics


def startTests():
    UnitTestAssignmnet()
    UnitTestGrade()
    UnitTestRepo()
    UnitTestStudent()
    UnitTestStudentController()
    UnitTestAssignmentController()
    UnitTestGradeController()
    UnitTestsStatistics()
