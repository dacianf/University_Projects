'''
Created on 1 Feb 2019

@author: Daci
'''



def strgPatToTable(strg, patt):
    '''
        Returns an object with parameters from strg
        Input: - strg - string containing object's parameters
               - patt - pattern name string
        Output: - pattern - which is [] empty list if there is no pattern or the pattern as a matrix of strings
    '''
    strg = strg.strip().split("-")
    patternn = []
    if patt == 'block':
        patternn = [[' ' for x in range(2)] for y in range(2)]
    elif patt == 'tub':
        patternn = [[' ' for x in range(3)] for y in range(3)]
    elif patt == 'blinker':
        patternn = [[' ' for x in range(3)] for y in range(3)]
    elif patt == 'beacon':
        patternn = [[' ' for x in range(4)] for y in range(4)]
    elif patt == 'spaceship':
        patternn = [[' ' for x in range(4)] for y in range(4)]
    if strg[0] == patt:
        strg = strg[1].split('.')
        for sq in strg:
            patternn[int(sq[1])][int(sq[3])] = 'x'
        return patternn
    return []


def strgValToTable(strg):
    '''
        Returns an object with parameters from strg
        Input: - strg - string containing object's parameters
               - Object - object name
        Output: -  - new object with strg parameters
    '''
    patternn = [[' ' for x in range(8)] for y in range(8)]
    if len(strg) == 0:
        return patternn
    strg = strg.strip().split(".")
    x = len(strg)
    for sq in strg[:x-1]:
        patternn[int(sq[1])][int(sq[3])] = 'x'
    return patternn
        

def writeFile(fileName, sqList):
    '''
        Writes in a given file list of squares of form (y,x),
        Input: - fileName - string
               - sqList - list of Squares
    '''
    f = open(fileName, "w+")
    for sq in sqList:
        f.write('(' + str(sq.y) + ',' + str(sq.x) + ').')
    f.close()


def readPattern(fileName, patternn):
    '''
        Reads objects from a file and return that object
        Input: - fileName - string
               - Object - object that will be readed
        Output: - patt - pattern as a matrix
    '''
    patt = []
    try:
        f = open(fileName, "r")
        line = f.readline().strip()
        while len(line) > 0:
            patt.append(strgPatToTable(line, patternn))
            line = f.readline().strip()
        f.close()
    except IOError as er:
        raise "Error: " + str(er)
    for x in patt:
        if len(x):
            return x


def readState(fileName):
    objList = 0
    try:
        f = open(fileName, "r")
        line = f.readline().strip()
        objList = strgValToTable(line)
        f.close()
    except IOError as er:
        raise "Error: " + str(er)
    return objList
