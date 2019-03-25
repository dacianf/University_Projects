'''
Created on 28 Nov 2018

@author: Daci
'''
from UI.menu import CliMenu
from unitTests import startTests
from settings.settings import Settings
from settings.fileOperations import readSettings
from controller.studentController import StudentController
from controller.undoController import UndoController
from repository.repo import Repository
from domain.studentValidator import StudentValidator
from controller.assignmentController import AssignmnetController
from domain.assignmentValidator import AssignmentValidator
from controller.gradeController import GradeController
from domain.gradeValidator import GradeValidator
from statistics.statistics import Statistics
from repository.txtRepository import TextFileRepo
from repository.binFileRepo import BinRepository
from repository.jsonRepository import JsonRepository
from domain.student import Student
from domain.assignment import Assignment
from domain.grade import Grade
from UI.gui.gui import Ui_StudentsManagement
from PyQt5 import QtWidgets
from repository.mongoRepository import MongoRepository

startTests()

sets = readSettings("settings\settings.properties", Settings)

undoCtr = UndoController()
if sets.repo == "memory":
    stRepo = Repository()
    asRepo = Repository()
    grRepo = Repository()
elif sets.repo == "text_file":
    stRepo = TextFileRepo("data\\" + sets.repoSt, Student)
    asRepo = TextFileRepo("data\\" + sets.repoAs, Assignment)
    grRepo = TextFileRepo("data\\" + sets.repoGr, Grade)
elif sets.repo == "binary_file":
    stRepo = BinRepository("data\\" + sets.repoSt, Student)
    asRepo = BinRepository("data\\" + sets.repoAs, Assignment)
    grRepo = BinRepository("data\\" + sets.repoGr, Grade)
elif sets.repo == "json_file":
    stRepo = JsonRepository("data\\" + sets.repoSt, Student)
    asRepo = JsonRepository("data\\" + sets.repoAs, Assignment)
    grRepo = JsonRepository("data\\" + sets.repoGr, Grade)
elif sets.repo == "mongoDB":
    stRepo = MongoRepository(Student)
    asRepo = MongoRepository(Assignment)
    grRepo = MongoRepository(Grade)
else:
    raise ValueError("Repo must be from memory/text_file/binary_file/json_file/mongoDB")

stCtr = StudentController(stRepo, StudentValidator(), undoCtr)
asCtr = AssignmnetController(asRepo, AssignmentValidator(), undoCtr)
grCtr = GradeController(grRepo, GradeValidator(), stCtr, asCtr, undoCtr)
stat = Statistics(grCtr)
if sets.ui == "cli":
    menu = CliMenu(undoCtr, stCtr, asCtr, grCtr, stat)
    menu.mainMenu()
elif sets.ui == "gui":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    StudentsManagement = QtWidgets.QMainWindow()
    ui = Ui_StudentsManagement(undoCtr, stCtr, asCtr, grCtr, stat)
    ui.setupUi(StudentsManagement)
    StudentsManagement.show()
    sys.exit(app.exec_())

else:
    raise ValueError("UI must be cli/gui!")
