'''
Created on 17 Oct 2018

@author: Daci
@note: Assignment3-4 Problem 1
'''
from cmath import sqrt

def createComplexNb(real, imaginary):
    return {"real":real,"imaginary":imaginary}

def testCreateComplexNb():
    assert createComplexNb(5, 6) == {"real":5,"imaginary":6}
    assert createComplexNb(0, -1) == {"real":0,"imaginary":-1}
    
def add(complexNb,listaOfComplxNb):
    listaOfComplxNb.append(complexNb)
    
def testAdd():
    lista=[]
    assert len(lista)==0
    add(createComplexNb(5, 6), lista)
    assert len(lista)==1
    add(createComplexNb(7, 6), lista)
    assert len(lista)==2
    
def getReal(c):
    return c["real"]

def getImg(c):
    return c["imaginary"]

def setReal(c, newVal):
    c["real"]=newVal

def setImg(c, newVal):
    c["imaginary"]=newVal

def insert(complexNb,listOfComplxNb,position):
    if position>=0 and position<=len(listOfComplxNb):
        listOfComplxNb.insert(position,complexNb)
    
def testInsert():
    lista=[]
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    assert len(lista)==3
    insert(createComplexNb(5, 1), lista, 2)
    assert lista[2]=={"real":5,"imaginary":1}
    assert len(lista)==4
    insert(createComplexNb(23, -1), lista, 1)
    assert lista[1]=={"real":23,"imaginary":-1}
    assert len(lista)==5
    
def remove(position,lista):
    if position>=0 and position<=len(lista):
        del lista[position]
    
def testRemove():
    lista=[]
    assert len(lista)==0
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    assert len(lista)==3
    remove(2,lista)
    assert len(lista)==2
    
def removeSq(startPosition,endPosition,lista):
    if(startPosition>=0 and endPosition<=len(lista)):
        del lista[startPosition:endPosition+1]
    
def testRemoveSq():
    lista=[]
    assert len(lista)==0
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    add(createComplexNb(-3, 2), lista)
    add(createComplexNb(8, -9), lista)
    assert len(lista)==5
    removeSq(2,4,lista)
    assert len(lista)==2

def replace(oldNumber, newNumber, lista):
    #for complexNb in lista:
        #if(complexNb==oldNumber):
            #complexNb=newNumber
    for i in range(len(lista)):
        if lista[i]==oldNumber:
            lista[i]=newNumber
    
def testReplace():
    lista=[]
    assert len(lista)==0
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    replace(createComplexNb(3, 2), createComplexNb(5, 3), lista)
    assert lista[1]=={"real":5,"imaginary":3}
    
def listElem(lista):
    n=len(lista)
    if(n==0):
        print("There is no complex number introduced!")
        return []
    complexNb=""
    for i in range(0,n):
        complexNb=getComplexNbForm(getReal(lista[i]), getImg(lista[i]))
        print("("+complexNb+")", end="; ")

def getComplexNbForm(real,imaginary):
    '''
        This funcion gets a real and an imaginary part of a complex number and returns a strig of form a + bi
        Input: - real - integer
               - imaginary - integer
        Output: - complexNb - string
    '''
    complexNb=str(real)
    if imaginary>=0:
        complexNb+=" + "+str(imaginary)+"i"
    elif imaginary==-1:
        complexNb+=" - i"
    else:
        complexNb+=" - "+str(-1*imaginary)+"i"
    return complexNb
def listReal(start,end,lista):
    realList=[]
    for i in range(start,end+1):
        add(getReal(lista[i]),realList)
    return realList

def testListReal():
    lista=[]
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    assert listReal(0, 2, lista)==[0,3,6]

def getModule(complexNb):
    a=getReal(complexNb)
    b=getImg(complexNb)
    return int(sqrt(a*a+b*b))
    
def listModulo(prop,number,lista):
    finalList=[]
    for complexNb in lista:
        if prop == '<':
            if(getModule(complexNb)<number):
                add(complexNb, finalList)
        elif prop == '=':
            if(getModule(complexNb)==number):
                add(complexNb, finalList)
        elif prop == '>':
            if(getModule(complexNb)>number):
                add(complexNb, finalList)
    return finalList

testAdd()
testInsert()
testRemove()
testRemoveSq()
testReplace()
testListReal()