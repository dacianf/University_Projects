'''
Created on 19 Nov 2018

@author: Daci
'''
from random import choice, randint, uniform
from domain.student import Student
from domain.assignment import Assignment
from domain.grade import Grade
import string


def populateStCtrSTATIC(studCtrl):
    studCtrl.add(Student(1, "Ion", "10"))
    studCtrl.add(Student(2, "Ioan", "15"))
    studCtrl.add(Student(3, "Ioana", "10"))
    studCtrl.add(Student(4, "John", "10"))
    studCtrl.add(Student(5, "Greg", "12"))
    studCtrl.add(Student(6, "Mircea", "10"))
    studCtrl.add(Student(7, "Ana", "10"))
    studCtrl.add(Student(8, "Maria", "20"))
    studCtrl.add(Student(9, "Crez", "12"))
    studCtrl.add(Student(10, "Hary", "10"))


def populateAsCtrSTATIC(assigCtrl):
    assigCtrl.add(Assignment(1, "ASC", "30/12/2014"))
    assigCtrl.add(Assignment(2, "Fp", "30/11/2014"))
    assigCtrl.add(Assignment(3, "ASC2", "20/10/2014"))
    assigCtrl.add(Assignment(4, "Calculus1", "30/12/2014"))
    assigCtrl.add(Assignment(5, "Algebra1", "30/12/2014"))
    assigCtrl.add(Assignment(6, "Cryptology", "15/08/2014"))
    assigCtrl.add(Assignment(7, "Calculus2", "13/10/2014"))
    assigCtrl.add(Assignment(8, "Algebra2", "20/01/2014"))
    assigCtrl.add(Assignment(9, "Self Development", "17/02/2014"))
    assigCtrl.add(Assignment(10, "Teaching", "19/05/2014"))


def populateGrCtrSTATIC(gradeCtr):
    gradeCtr.giveAssigToGroup(8, "10")
    gradeCtr.giveAssigToGroup(8, "15")
    gradeCtr.giveAssigToGroup(3, "10")
    gradeCtr.giveAssigToGroup(2, "20")
    gradeCtr.giveAssigToGroup(1, "12")
    gradeCtr.setAssigStud(1, 1)
    gradeCtr.setAssigStud(2, 1)
    gradeCtr.setAssigStud(3, 1)
    gradeCtr.setAssigStud(3, 5)
    gradeCtr.setGrade(1, 8, 6.0)
    gradeCtr.setGrade(3, 8, 8.0)
    gradeCtr.setGrade(5, 3, 5.5)


def populateStCtrDYN(studentCtrl, nb):
    lista = getStud(nb)
    for st in lista:
        studentCtrl.add(st)


def populateAsCtrDYN(assigCtrl, nb):
    lista = getAssignments(nb)
    for asig in lista:
        assigCtrl.add(asig)


def populateGrCtrDYN(gradeCtr, nb):
    lista = getGrades(nb)
    for gr in lista:
        gradeCtr.add(gr)


def getListOfNames(nb):
    lastNames = ["Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas"]
    lastNames += ["Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson"]
    firstNames = ["Mark", "Helena", "Eliz", "Terry", "Krysta", "Dara", "Anglea", "Elane", "Ellen", "Cleo", "Samira", "Reginald", "Stacia"]
    firstNames += ["Kylie", "Wm", "Lucretia", "Kirk", "Bradley", "Vernia", "Eldora", "Lonnie", "Denny", "Herman", "Dante", "Wilton"]
    names = []
    for i in range(nb + 1):
        names.append(str(choice(firstNames)) + " " + str(choice(lastNames)))
    return names


def getListOfIDs(nb):
    li = range(1, nb + 1)
    return li


def getGroups(nb):
    nbs = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]

    gr = []
    for i in range(nb + 1):
        num = ""
        for j in range(randint(1, 123123) % 4 + 1):
            num += choice(nbs)
        gr.append(num + choice(string.ascii_letters))
    return gr


def getStud(nb):
    ids = getListOfIDs(nb)
    names = getListOfNames(nb)
    groups = getGroups(nb)
    lista = []
    for i in range(nb):
        lista.append(Student(ids[i], names[i], groups[i]))
    return lista


def getListOfAssignName(nb):
    pref = ["Modern", "Modal", "Mechanical", "Biological", "Space", "Educational", "Military", "Applied", "Geodesy", "Arhitecture", "Systems", "Fundamentals"]
    suff = ["Proagramming", "Proteins", "Computers", "C++", "Java", "Spoon", "Logics", "Algebra", "Calculus", "MAP", "Geometry", "Statisctics"]
    assign = []
    for i in range(nb + 1):
        assign.append(choice(pref) + " " + choice(suff))
    return assign


def genListOfDates(nb):
    lista = []
    for i in range(nb + 1):
        dt = str(randint(1, 28)) + "/" + str(randint(1, 12)) + "/" + str(randint(2017, 2020))
        lista.append(dt)
    return lista


def getAssignments(nb):
    lista = []
    idLi = getListOfIDs(nb)
    descLi = getListOfAssignName(nb)
    dateLi = genListOfDates(nb)
    for i in range(nb):
        lista.append(Assignment(idLi[i], descLi[i], dateLi[i]))
    return lista


def getGrades(nb):
    lista = []
    frNameAr = [0] * (nb + 1)
    frAssigAr = [0] * (nb + 1)
    while nb > 0:
        n = randint(1, 100)
        if frNameAr[n] == 0:
            frNameAr[n] = 1
            for i in range(randint(1, 8)):
                a = randint(1, 100)
                if frAssigAr[a] == 0:
                    frAssigAr[a] = 1
                    lista.append(Grade(n, a, round(uniform(0, 10), 2)))
                    nb -= 1
        frAssigAr[i] = 0
    return lista
