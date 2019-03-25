'''
Created on 17 Oct 2018

@author: Daci
@note: Assignment3-4 Problem 1
'''
from math import sqrt
import re


def getReal(c):
    return c["real"]

def getImg(c):
    return c["imaginary"]

def setReal(c, newVal):
    c["real"]=newVal

def setImg(c, newVal):
    c["imaginary"]=newVal


def complexNbFromString(complexNbString):
    '''
        Function gets a string which consist of a complex number of form a+bi and returns a dictionary of form {"real":real,"imaginary":imaginary}
        Input: - complexNbString - string
        Output: dictionary of form {"real":real,"imaginary":imaginary}
        
    '''
    digits=re.split('i|\-|\+|\s', complexNbString)
    signs=[1,1]
    signIndex=0
    for i in range(len(complexNbString)):
        if(complexNbString[i]=='-'):
            signs[signIndex]=-1
            signIndex+=1
        elif(complexNbString[i]=='+'):
            signs[signIndex]=1
            signIndex+=1
    if signIndex==1:
        signs[1]=signs[0]
        signs[0]=1
    digits=list(filter(None,digits))
    if(len(digits)==1):
        digits.append(1)
    real=signs[0]*int(digits[0])
    imaginary=signs[1]*int(digits[1])
    return createComplexNb(real, imaginary)

  
def startWithElemts():
    '''
        Returns a list of 12 preDefined complex numbers
        Output: - lista - list of complex numbers of form {"real":real,"imaginary":imaginary}
    '''
    lista=[]
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    add(createComplexNb(4, 1), lista)
    add(createComplexNb(7, 3), lista)
    add(createComplexNb(6, 0), lista)
    add(createComplexNb(-9, -5), lista)
    add(createComplexNb(5, 7), lista)
    add(createComplexNb(1, -2), lista)
    add(createComplexNb(4, 21), lista)
    add(createComplexNb(32, -7), lista)
    add(createComplexNb(-9, -1), lista)
    return lista

def createComplexNb(real, imaginary):
    '''
        Funcion gets the value of real and imaginary and returns a dictionary of form {"real":real,"imaginary":imaginary}
        Input: - real - integer
               - imaginary - integer
        Output: dictionary of form {"real":real,"imaginary":imaginary}
    '''
    return {"real":real,"imaginary":imaginary}
    
def add(complexNb,listOfComplxNb):
    '''
        This function adds a complex number at the end of the list of complex numbers
        Input: - complexNb - a dictionary of form: {"real":real,"imaginary":imaginary}
               - listOfComplexNb - list of dictionaries of above form
    '''
    listOfComplxNb.append(complexNb)

def insert(complexNb,listOfComplxNb,position):
    '''
        This function insert a complex number at a given position in the list of complex numbers
        Input: - complexNb - a dictionary of form: {"real":real,"imaginary":imaginary}
               - listOfComplexNb - list of dictionaries of above form
               - position - integer
    '''
    if position>=0 and position<=len(listOfComplxNb):
        listOfComplxNb.insert(position,complexNb)
    else:
        raise ValueError("Position must be between 0 and "+str(len(listOfComplxNb)-1))
    
def remove(position,lista):
    '''
        This function removes a complex number at a given position in the list of complex numbers
        Input: - position - integer
               - lista - list of dictionaries of above form
    '''
    if position>=0 and position<len(lista):
        del lista[position]
    else:
        raise ValueError("Position must be between 0 and "+str(len(lista)-1))
def removeSq(startPosition,endPosition,lista):
    '''
        This function removes a sequence of complex numbers between 2 positions in the list
        Input: - startPosition - integer
               - endPosition - integer
               - lista - list of dictionaries of above form
    '''
    if(startPosition>=0 and endPosition<len(lista)):
        del lista[startPosition:endPosition+1]
    else:
        raise ValueError("Position must be between 0 and "+str(len(lista)-1))

def replace(oldNumber, newNumber, lista):
    '''
        This function replace an old complex number with a newone in the list
        Input: - oldNumber - a dictionary of form: {"real":real,"imaginary":imaginary}
               - newNumber - a dictionary of form: {"real":real,"imaginary":imaginary}
               - lista - list of dictionaries of above form
    '''
    if oldNumber in lista:
        for i in range(len(lista)):
            if lista[i]==oldNumber:
                lista[i]=newNumber    
    else:
        complexNb=getComplexNbForm(getReal(oldNumber), getImg(oldNumber))
        raise ValueError(complexNb+" does not exist in current list.")

def getComplexNbForm(real,imaginary):
    '''
        This funcion gets a real and an imaginary part of a complex number and returns a strig of form a + bi
        Input: - real - integer
               - imaginary - integer
        Output: - complexNb - string of form a+bi
    '''
    complexNb=str(real)
    if imaginary>=0 and imaginary!=1:
        complexNb+=" + "+str(imaginary)+"i"
    elif imaginary==-1:
        complexNb+=" - i"
    elif imaginary==1:
        complexNb+=" + i"
    else:
        complexNb+=" - "+str(-1*imaginary)+"i"
    return complexNb

def listReal(start,end,lista):
    '''
        This funcion returns a list of real numbers (imaginary part = 0) from the complex list between 2 positions
        Input: - start - integer
               - end - integer
               - lista - list of dictionaries of form :{"real":real,"imaginary":imaginary} 
        Output: - realList - list of dictionaries of form :{"real":real,"imaginary":imaginary} containing just real numbers from the input list
    '''
    realList=[]
    for i in range(start,end+1):
        if getImg(lista[i])==0:
            add(lista[i],realList)
    return realList

def getModule(complexNb):
    '''
        Function returns a float number which is the module of a given complex number
        Input: - complexNb - dictionary of form :{"real":real,"imaginary":imaginary} 
        Output: - float number representing complex number module
    '''
    a=getReal(complexNb)
    b=getImg(complexNb)
    return float(sqrt(a*a+b*b))
    
def listModulo(prop,number,lista):
    '''
        This funcion returns a list of complex numbers from the complex list which has modulo [<|=|>] than a given number
        Input: - prop - char which contains a property [<|=|>]
               - number - integer
               - lista - list of dictionaries of form :{"real":real,"imaginary":imaginary} 
        Output: - finalList - list of dictionaries of form :{"real":real,"imaginary":imaginary} containing just real numbers from the input list
    '''
    
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

def getSum(start,end,lista):
    '''
        Function goes from a start to an end point in list and caluclate the sum of the numbers between those points
        Input: - start - integer
               - end - integer
               - lista - list of dictionaries of form :{"real":real,"imaginary":imaginary}
        Output: - False - if operation is unsuccessful
                - dictionary of form :{"real":real,"imaginary":imaginary}
    '''
    if start>=0 and end<len(lista):
        sumReal=0
        sumImg=0
        for i in range(start,end+1):
            sumReal+=getReal(lista[i])
            sumImg+=getImg(lista[i])
        return createComplexNb(sumReal, sumImg)  
    else:
        raise ValueError("Position must be between 0 and "+str(len(lista)-1))
        return False
    
def getProduct(start,end,lista):
    '''
        Function goes from a start to an end point in list and caluclate the product of the numbers between those points
        Input: - start - integer
               - end - integer
               - lista - list of dictionaries of form :{"real":real,"imaginary":imaginary}
        Output: - False - if operation is unsuccessful
                - dictionary of form :{"real":real,"imaginary":imaginary}
    '''
    if start>=0 and end<len(lista):
        prodReal=0
        prodImg=0
        a=getReal(lista[start])
        b=getImg(lista[start])
        for i in range(start+1,end+1):
            realPart=getReal(lista[i])
            imgPart=getImg(lista[i])
            prodReal=a*realPart-b*imgPart
            prodImg=a*imgPart+b*realPart
            a=prodReal
            b=prodImg
        return createComplexNb(prodReal, prodImg)
    else:
        raise ValueError("Position must be between 0 and "+str(len(lista)-1))

def filterReal(lista):
    '''
        This function gets a list of dictionaries of form :{"real":real,"imaginary":imaginary} and remove thoes elements which has imaginary part distinct of 0
        Input: - lista - list of dictionaries of form :{"real":real,"imaginary":imaginary}
        Output: - lista - list of remained elements
    '''
    for i in range(len(lista)-1,-1,-1):
        if(getImg(lista[i])!=0):
            remove(i, lista)
    return lista

def filterModulo(prop, number, lista):
    '''
        This function removes from lista all elements which has not the module [<|=|>] than number
        Input: - prop - char [<|=|>]
               - number - integer
               - lista - list of dictionaries of form :{"real":real,"imaginary":imaginary}
        Output: - lista - list of remained elements
    '''
    for i in range(len(lista)-1,-1,-1):
        mod=getModule(lista[i])
        if(prop=="=" and number!=mod):
            remove(i, lista)
        elif(prop==">" and number<mod):
            remove(i, lista)
        elif(prop=="<" and number>mod):
            remove(i, lista)
    return lista

