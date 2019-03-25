"""
Created on 6 Nov 2018

@author: Daci
"""
from controller.assignmentController import AssignmnetController
from controller.studentController import StudentController
from controller.gradeController import GradeController
from controller.undoController import UndoController
from repository.repo import Repository
from domain.assignmentValidator import AssignmentValidator
from domain.gradeValidator import GradeValidator
from domain.studentValidator import StudentValidator
from statistics.statistics import Statistics
from UI.populateRepo import *


class Menu:

    def __init__(self):
        self._undo = UndoController()
        self._stud = StudentController(Repository(), StudentValidator(), self._undo)
        self._assign = AssignmnetController(Repository(), AssignmentValidator(), self._undo)
        self._grade = GradeController(Repository(), GradeValidator(), self._stud, self._assign, self._undo)
        self._stat = Statistics(self._grade)

    @staticmethod
    def printMenu():
        men = "\nAvailable commands:\n"
        men += "\t 1 - Add student\n"
        men += "\t 2 - Remove student\n"
        men += "\t 3 - Update student infos\n"
        men += "\t 4 - List students\n"
        men += "\t 5 - Add assignment\n"
        men += "\t 6 - Remove assignment\n"
        men += "\t 7 - Update assignment infos\n"
        men += "\t 8 - List assignments\n"
        men += "\t 9 - Add assignment to student/group\n"
        men += "\t10 - List grades\n"
        men += "\t11 - Set grade\n"
        men += "\t12 - All students who received a given assignment, ordered alphabetically or by average grade for that assignment\n"
        men += "\t13 - All students who are late in handing in at least one assignment. These are all the students who have an ungraded assignment for which the deadline has passed\n"
        men += "\t14 - Students with the best school situation, sorted in descending order of the average grade received for all assignments\n"
        men += "\t15 - All assignments for which there is at least one grade, sorted in descending order of the average grade received by all students who received that assignment\n"
        men += "\t16 - Undo\n"
        men += "\t17 - Redo\n"
        men += "\t18 - Help\n"
        men += "\t 0 - Exit\n"
        print(men)

    def mainMenu(self):
        Menu.printMenu()
        populateStCtrDYN(self._stud, 100)
        populateAsCtrDYN(self._assign, 100)
        populateGrCtrDYN(self._grade, 100)
        #populateStCtrSTATIC(self._stud)
        #populateAsCtrSTATIC(self._assign)
        #populateGrCtrSTATIC(self._grade)
        while True:
            try:
                cmd = input("Enter command: ").strip()
                if cmd == '0':
                    print("Thank you for using grading system! Have a great day! :)")
                    return 0
                elif cmd == '1':
                    self.uiAddStud()
                elif cmd == '2':
                    self.uiRmvStud()
                elif cmd == '3':
                    self.uiUpdateStud()
                elif cmd == '4':
                    self.uiListStud()
                elif cmd == '5':
                    self.uiAddAssig()
                elif cmd == '6':
                    self.uiRmvAssig()
                elif cmd == '7':
                    self.uiUpdateAssig()
                elif cmd == '8':
                    self.uiListAssig()
                elif cmd == '9':
                    self.uiAddAssigToStGr()
                elif cmd == '10':
                    self.uiListGrades()
                elif cmd == '11':
                    self.uiGradeStud()
                elif cmd == '12':
                    self.uiStat1()
                elif cmd == '13':
                    self.uiStat2()
                elif cmd == '14':
                    self.uiStat3()
                elif cmd == '15':
                    self.uiStat4()
                elif cmd == '16':
                    self._undo.undo()
                elif cmd == '17':
                    self._undo.redo()
                elif cmd == '18':
                    Menu.printMenu()
                else:
                    print("Invalid CMD!")
            except Exception as er:
                print("Error: " + str(er))

    def uiAddStud(self):
        sID = (input("Student ID: "))
        if sID.isnumeric():
            sID = int(sID)
        else:
            raise TypeError("ID must be an int!")
        sName = input("Student name: ")
        sGroup = input("Student group: ")
        stu = Student(sID, sName, sGroup)
        self._stud.add(stu)
        return True

    def uiRmvStud(self):
        sID = input("ID of student you want to delete: ")
        if sID.isnumeric():
            sID = int(sID)
        else:
            raise TypeError("ID must be an int!")
        self._grade.removeStud(sID)

    def uiUpdateStud(self):
        cmd = input("To update a student specific info type 1\n or 0 for complete infos:").strip()
        s = Student(-1, -1, -1)
        if cmd == '1':
            info = input("To modify: Name type 1, Group type 2: ").strip()
            if info == '1':
                s.id = int(input("Students ID you want to update: "))
                s.name = input("Enter new name: ")
                s.group = self._stud.findByID(s.id).group
                StudentValidator().validate(s)
                self._stud.update(s)
                return True
            elif info == '2':
                s.id = int(input("Students ID you want to update: "))
                s.group = input("Enter new grop: ")
                s.name = self._stud.findByID(s.id).name
                StudentValidator().validate(s)
                self._stud.update(s)
                return True
            else:
                print("Invalid command!")
        elif cmd == '0':
            s.id = int(input("Students ID you want to update: "))
            s.name = input("Enter new name: ")
            s.group = input("Enter new grop: ")
            StudentValidator().validate(s)
            self._stud.update(s)
            return True
        else:
            print("Invalid command!")

    def uiListStud(self):
        print(self._stud)

    def uiAddAssig(self):
        aID = input("Assignment ID: ")
        if aID.isnumeric():
            aID = int(aID)
        else:
            raise TypeError("ID must be an int!")
        aDesc = input("Assignment description: ")
        aDeadline = input("Assignment deadline: ")
        assig = Assignment(aID, aDesc, aDeadline)
        self._assign.add(assig)
        return True

    def uiRmvAssig(self):
        aID = input("ID of assignment you want to delete: ")
        if aID.isnumeric():
            aID = int(aID)
        else:
            raise TypeError("ID must be an int!")
        self._grade.removeAssign(aID)

    def uiUpdateAssig(self):
        cmd = input("To update an assignment specific info type 1\nor 2 for complete infos:").strip()
        assign = Assignment(-1, -1, -1)
        if cmd == '1':
            info = input("To modify: Description type 1, Deadline type 2: ").strip()
            if info == '1':
                assign.id = int(input("Assignments ID you want to update: "))
                newDesc = input("Enter new description: ")
                assign.description = newDesc
                assign.deadline = self._assign.findByID(assign.id).deadline
                AssignmentValidator().validate(assign)
                self._assign.update(assign)
                return True
            elif info == '2':
                assign.id = int(input("Assignments ID you want to update: "))
                newDeadline = input("Enter new deadline: ")
                assign.deadline = newDeadline
                assign.description = self._assign.findByID(assign.id).description
                AssignmentValidator().validate(assign)
                self._assign.update(assign)
                return True
            else:
                print("Invalid command!")
        elif cmd == '2':
            assign.id = int(input("Assignment ID you are looking to update: "))
            assign.description = input("Enter new description: ")
            assign.deadline = input("Enter new deadline: ")
            AssignmentValidator().validate(assign)
            self._assign.update(assign)
            return True
        else:
            print("Invalid command!")

    def uiListAssig(self):
        print(self._assign)

    def uiListGrades(self):
        print(self._grade)

    def uiAddAssigToStGr(self):
        cmd = input("Type 1 for setting an assignment to a student or 2 to set it to a group: ").strip()
        if(cmd == '1'):
            aID = input("Assignment ID: ")
            sID = input("Student ID: ")
            if aID.isnumeric() and sID.isnumeric():
                aID = int(aID)
                sID = int(sID)
            else:
                raise TypeError("ID must be an int!")
            self._grade.setAssigStud(aID, sID)
        elif(cmd == '2'):
            gr = input("Group: ")
            aID = input("Assignment ID: ")
            if aID.isnumeric():
                aID = int(aID)
            else:
                raise TypeError("ID must be an int!")
            self._grade.giveAssigToGroup(aID, gr)
        else:
            print("Invalid command!")

    def uiGradeStud(self):
        sID = input("Write the id of student you want to grade: ")
        if not sID.isnumeric():
            raise Exception("Student id must be a positive int")
        sID = int(sID)
        if type(self._stud.findByID(sID)) != Student:
            raise ValueError("No student with such an id!")
        x = self._grade.getStudUngrade(sID)
        if len(x) == 0:
            raise Exception("No assignments to grade!")
        assigIDs = []
        for i in x:
            assigIDs.append(i.assignID)
            print("\t" + str(i))
        aID = input("Write the assignment id from the above list: ")
        if not aID.isnumeric():
            raise Exception("Assignment id must be a positive int")
        aID = int(aID)
        if aID not in assigIDs:
            raise ValueError("Assignment id must be from the above list!")
        grade = float(input("Write the grade:"))
        x = self._grade.setGrade(sID, aID, grade)
        print(x)

    def uiStat1(self):
        aID = input("Write the assignment id for the statistic: ")
        if not aID.isnumeric():
            raise Exception("Assignment id must be a positive int")
        aID = int(aID)
        x = self._stat.getStudGivenAssig(aID)
        if len(x) > 0:
            print("All students who received a given assignment, ordered alphabetically or by average grade for that assignment")
            for i in x:
                print(str(i))
        else:
            print("No student satisffies this condition!")

    def uiStat2(self):
        x = self._stat.getLateStuds()
        if len(x) > 0:
            print("All students who are late in handing in at least one assignment.\nThese are all the students who have an ungraded assignment for which the deadline has passed")
            for i in x:
                print(str(i))
        else:
            print("No student satisffies this condition!")

    def uiStat3(self):
        x = self._stat.getStudBestGrSchool()
        if len(x) > 0:
            print("Students with the best school situation, sorted in descending order of the average grade received for all assignments")
            for i in x:
                print(i)
        else:
            print("No student satisffies this condition!")

    def uiStat4(self):
        x = self._stat.getAssigByGrade()
        if len(x) > 0:
            print("All assignments for which there is at least one grade, sorted in descending order of the average grade received by all students who received that assignment")
            for i in x:
                print(i)
        else:
            print("No assignmnet satisffies this condition!")
