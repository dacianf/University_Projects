'''
Created on 3 Dec 2018

@author: Daci
'''
from domain.grade import Grade
import pickle
import json


def fileStrToRepr(strg, Object):
    '''
        Returns an object with parameters from strg
        Input: - strg - string containing object's parameters
               - Object - object name
        Output: -  - new object with strg parameters
    '''
    strg = strg.strip().split(",")
    if strg[0].isnumeric():
        strg[0] = int(strg[0])
    if Object == Grade:
        if strg[1].isnumeric():
            strg[1] = int(strg[1])
        strg[2] = float(strg[2])
    return Object(*strg)


def reprToFileStr(objRepr):
    '''
        Returns a string with object's parameters
        Input: - objRepr - string with object representation
        Output: - fileObj - string
    '''
    objRepr = objRepr.strip().split("(")
    objRepr = objRepr[1]
    objRepr = objRepr[:len(objRepr) - 1]
    objRepr = objRepr.split(",")
    fileObj = ""
    for st in objRepr:
        fileObj += st + ","
    fileObj = fileObj[:len(fileObj) - 1] + "\n"
    return fileObj


def writeStInFile(fileName, objects):
    '''
        Writes in a given file a given object's parameters
        for example for Student(1,"John","913") will write in file:
                1,John,913
        using object representation("repr(object)")
        Input: - fileName - string
               - objects - list of objects
    '''
    f = open(fileName, "w+")
    for obj in objects:
        f.write(reprToFileStr(repr(obj)))
    f.close()


def readStFromFile(fileName, Object):
    '''
        Reads objects from a file and return that object
        Input: - fileName - string
               - Object - object that will be returned
        Output: - objList - list of new objects
    '''
    objList = []
    try:
        f = open(fileName, "r")
        line = f.readline().strip()
        while len(line) > 0:
            objList.append(fileStrToRepr(line, Object))
            line = f.readline().strip()
        f.close()
    except IOError as er:
        raise "Error: " + str(er)
    return objList


def readSettings(fileName, Settings):
    '''
        Reads settings from fileName and returns a Settings object
        Input: - filename - string
               - Settings - reference to settings class
        Output: - Settings - obj of settings type with parameters from settings file
    '''
    settings = {"ui": 0, "repository": 0, "studentsRepo": 0, "assignmentsRepo": 0, "gradesRepo": 0}
    try:
        f = open(fileName, "r")
        line = f.readline().strip()
        while len(line) > 0:
            line = line.split("=")
            settings[line[0].strip()] = line[1].strip()
            line = f.readline().strip()
        f.close()
    except IOError as e:
        print("Error: " + str(e))
    return Settings(settings["ui"], settings["repository"], settings["studentsRepo"], settings["assignmentsRepo"], settings["gradesRepo"])


def readFromBin(fileName):
    '''
        Reads from a binary file the objects and returns a list of them
        Input: - fileName - string
        Output: - objects - list of objects from file
    '''
    objects = []
    try:
        f = open(fileName, "rb")
        x = pickle.load(f)
        f.close()
        for obj in x:
            objects.append(obj)
        return objects
    except Exception as e:
        print("Error: " + str(e))
    return objects


def writeIntoBin(fileName, objects):
    '''
        Writes into a binary file a list of objects
        Input: - fileName - string
               - objects - list of objects
    '''
    f = open(fileName, "wb+")
    pickle.dump(objects, f)
    f.close()


def readFromJson(fileName, Obj):
    '''
        Reads from a json file the objects and returns a list of them
        Input: - fileName - string
        Output: - objects - list of objects from file
    '''
    objects = []
    try:
        f = open(fileName, "rb")
        obje = json.load(f)
        for obj in obje:
            objects.append(Obj(*obj.values()))
        return objects
    except Exception as e:
        print("Error: " + str(e))
    return objects


def writeIntoJson(fileName, objects):
    '''
        Writes into a binary file a list of objects
        Input: - fileName - string
               - objects - list of objects
    '''
    f = open(fileName, "w+")
    json.dump(objsToDict(objects), f, indent=4)
    f.close()


def objsToDict(listObjs):
    li = []
    for obj in listObjs:
        li.append(obj.toDict())
    return li
