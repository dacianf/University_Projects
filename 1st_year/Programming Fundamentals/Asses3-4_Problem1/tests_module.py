'''
Created on 21 Oct 2018

@author: Daci
@note: test module for CLI AS_3-4
'''


from functionsAS34 import *


def startTesting():
    testAdd()
    testInsert()
    testRemove()
    testRemoveSq()
    testReplace()
    testListReal()
    testGetSum()
    testGetProduct()
    testFilterReal()
    testFilterModulo()
    
    
'''
try:
    fct()
    assert false
except ValueError:
    assert True
'''
    
'''
    Validation Functions
'''
    
def testComplexForm(strg):
    '''
        Checks if a given string is a correct complex number of form a+bi
        Input: - strg - string
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    strg=strg.replace(' ','') #remove all spaces
    err="The form of the number must be a+bi|a-bi|-a+bi|-a-bi where a and b are numbers"
    
    if((strg[0].isdigit() or (strg[0]=='-' and strg[1].isdigit()))and strg[-1]=='i'):
        i=1
        while strg[i].isdigit():
            i+=1
        if strg[i]=='-' or strg[i]=='+':
            i+=1
            while strg[i].isdigit():
                i+=1
            if strg[i]=='i' and i==len(strg)-1:
                return True
            else:
                raise ValueError(err)
        else:
            raise ValueError(err)
    else:
        raise ValueError(err)
    
def testAddCmd(cmd):
    '''
        Checks if add command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if len(cmd)==1:
        if testComplexForm(cmd[0])==True:
            return True
    else:
        raise ValueError("The add command must have just one parameter, which is a complex number of form a+bi")
    return False

def testInsertCmd(cmd):
    '''
        Checks if insert command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if(len(cmd)==3 and cmd[1]=='at'):
        if(testComplexForm(cmd[0]) and cmd[2].isnumeric()):
            return True
        else:
            raise ValueError("Given position must be an integer number")
    else:
        raise ValueError("Command must be of form: insert <number> at <position>")

def testRemoveCmd(cmd):
    '''
        Checks if remove command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if len(cmd)==1:
        if cmd[0].isnumeric():
            return True
        else:
            raise ValueError("Position must be a natural number!")
    elif len(cmd)==3:
        if(cmd[1]=='to'):
            if(cmd[0].isnumeric() and cmd[2].isnumeric()):
                return True
            else:
                raise ValueError("Positions must be natural numbers!")
        else:
            raise ValueError("Command must be: remove <start position> to <end position>")
    else:
            raise ValueError("Command must be: remove <start position> to <end position>")

def testReplaceCmd(cmd):
    '''
        Checks if replace command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if len(cmd)==3 and cmd[1]=='with':
        if(testComplexForm(cmd[0]) and testComplexForm(cmd[2])):
            return True
    else:
        raise ValueError("Incorect command!")
            
def testListCmd(cmd):
    '''
        Checks if list command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    n=len(cmd)
    if n==0:
        return True
    elif n==4 and cmd[0]=='real' and cmd[2]=='too':
        if cmd[1].isnumeric() and cmd[3].isnumeric():
            return True
        else:
            raise ValueError("Positions must be natural numbers!")
    elif n==3 and cmd[0]=='modulo':
        if(cmd[1]=='<' or cmd[1]=='=' or cmd[1]=='>'):
            if(cmd[2].isdigit()):
                return True
            else:
                raise ValueError("There must be a natural number")
        else:
            raise ValueError("Third parameter of command must be [<|=|>]")
    else:
        raise ValueError("Incorect command!")
    
def testHelpCmd(cmd):
    '''
        Checks if help command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if len(cmd)==0:
        return True
    else:
        raise ValueError("Incorect command")
    
def testSumCmd(cmd):
    '''
        Checks if sum command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if len(cmd)==3 and (cmd[1]=='to'):
        if(cmd[0].isnumeric() and cmd[2].isnumeric()):
            return True
        else:
            raise ValueError("Positions must be natural numbers!")
    else:
        raise ValueError("Command must be: sum <start position> to <end position>")

def testProductCmd(cmd):
    '''
        Checks if product command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    return testSumCmd(cmd)

def testFilterCmd(cmd):
    '''
        Checks if filter command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if len(cmd)==1 and cmd[0]=="real":
        return True
    elif len(cmd)==3 and cmd[0]=="modulo" and (cmd[1]=='<' or cmd[1]=='=' or cmd[1]=='>') and cmd[2].isnumeric():
        return True
    else:
        raise ValueError("Incorect command")

def testUndoCmd(cmd):
    '''
        Checks if undo command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    if len(cmd)==0:
        return True
    else:
        raise ValueError("Incorect command")

def testExitCmd(cmd):
    '''
        Checks if exit command has a correct form
        Input: - cmd - list of strings
        Output: - True - if the form is ok
                - Raise Value Error otherwise
    '''
    return testUndoCmd(cmd)

def checkNbIsNat(number):
    '''
        Checks if a number given as string is number'
        Input: - number - string
        Output: - number - integer if the form is ok
                - Raise Value Error otherwise
    '''
    if number.isnumeric():
        number=int(number)
        return number
    else:
        raise ValueError("Positio must be a natural number.")
    
def checkProIsOk(prop):
    '''
        Checks if a string given is one of this properties [<|=|>]
        Input: - prop - string
        Output: - prop - string if the form is ok
                - Raise Value Error otherwise
    '''
    if(prop=='<' or prop=='=' or prop=='>'):
        return prop
    else:
        raise ValueError("The property must be one of the following [<|=|>]!")
    
    
'''
Test Functions
'''

def testCreateComplexNb():
    assert createComplexNb(5, 6) == {"real":5,"imaginary":6}
    assert createComplexNb(0, -1) == {"real":0,"imaginary":-1}
    
def testAdd():
    lista=[]
    assert len(lista)==0
    add(createComplexNb(5, 6), lista)
    assert len(lista)==1
    add(createComplexNb(7, 6), lista)
    assert len(lista)==2
    
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

def testRemove():
    lista=[]
    assert len(lista)==0
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    assert len(lista)==3
    remove(2,lista)
    assert len(lista)==2

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
    
def testReplace():
    lista=[]
    assert len(lista)==0
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    replace(createComplexNb(3, 2), createComplexNb(5, 3), lista)
    assert lista[1]=={"real":5,"imaginary":3}

def testListReal():
    lista=[]
    add(createComplexNb(0, 1), lista)
    add(createComplexNb(3, 2), lista)
    add(createComplexNb(6, -1), lista)
    assert listReal(0, 2, lista)==[]
    add(createComplexNb(32, 0),lista)
    assert listReal(0, 3, lista)==[createComplexNb(32, 0)]

def testGetSum():
    lista=startWithElemts()
    assert getSum(1, 3, lista) == createComplexNb(13, 2)
    assert getSum(0, 6, lista) == createComplexNb(17, 1)
    try:
        assert getSum(3, 15, lista) == False
        assert getSum(5, 2, lista) == False
        assert False
    except ValueError:
        assert True
def testGetProduct():
    lista=startWithElemts()
    try:
        assert getProduct(3, 15, lista) == -1
        assert getProduct(5, 2, lista) == -2
        assert False
    except ValueError:
        assert True
    assert getProduct(3, 8, lista) == createComplexNb(-20148, -31404)
    assert getProduct(9, 11, lista) == createComplexNb(-1831, -6071)
    
def testFilterReal():
    lista=startWithElemts()
    filterReal(lista)
    assert lista==[createComplexNb(6,0)]
    add(createComplexNb(5, 0),lista)
    add(createComplexNb(5, 3),lista)
    assert len(lista)==3
    filterReal(lista)
    assert len(lista)==2
    
def testFilterModulo():
    lista=[]
    add(createComplexNb(-1, 4), lista)
    add(createComplexNb(-1, 1), lista)
    add(createComplexNb(2, 1), lista)
    add(createComplexNb(-1, -1), lista)
    add(createComplexNb(3, 1), lista)
    assert len(lista)==5
    filterModulo("=", getModule(createComplexNb(-1, 1)), lista)
    assert len(lista)==2