'''
Created on 27 Oct 2018

@author: Daci
'''
import functionsAS34 as fs
import tests_module as ts
from ui_module import uiPrintList
from copy import deepcopy


def main():
    printMenu()
    listOfComplexNb=fs.startWithElemts()
    cmdList={"1":add_ui,"2":insert_ui,"3":removePos_ui,"4":removeSeq_ui,"5":replace_ui,"6":list_ui,"7":listReal_ui,"8":listModulo_ui,"9":sum_ui,"10":product_ui,"11":filterReal_ui,"12":filterMod_ui,"14":help_ui}
    undoList=[]
    while True:
        try:
            option=input("Enter the command: ")
            if option in cmdList:
                if '8'<option or option<'6':
                    undoList.append(deepcopy(listOfComplexNb))
                cmdList[option](listOfComplexNb)
            elif option=='13':
                listOfComplexNb=undo_ui(listOfComplexNb, undoList)
            elif option=='0':
                print("Thank you for using this application! Have a great day!")
                return 0
            else:
                print("Incorect option!")
        except ValueError as er:
            print(er)

def printMenu():
    menu=("Complex numbers operations: \n")
    menu+=("  (indexing starts from 0 and a complex number has a+bi form)\n")
    menu+=("    1  -add <number>                                 :add <number> at the end of the list\n")
    menu+=("    2  -insert <number> at <position>                :insert number in list at position\n")
    menu+=("    3  -remove <position>                            :remove number from position\n")
    menu+=("    4  -remove <start position> to <end position>    :remove numbers between positions\n")
    menu+=("    5  -replace <old number> with <new number>       :replace old_number with new_number\n")
    menu+=("    6  -list                                         :writes the list of numbers\n")
    menu+=("    7  -list real <start position> to <end position> :writes the real numbers between positions\n")
    menu+=("    8  -list modulo [<|=|>] <number>                 :writes all numbers having modulo [<|=|>] than <number>\n")
    menu+=("    9  -sum <start position> to <end position>       :writes the sum of numbers between positions\n")
    menu+=("    10 -product <start position> to <end position>   :writes the product of numbers between positions\n")
    menu+=("    11 -filter real                                  :keep only real numbers\n")
    menu+=("    12 -filter modulo [<|=|>] <number>               :keep only those numbers having modulo [<|=|>] than <number>\n")
    menu+=("    13 -undo                                         :restore from last change\n")
    menu+=("    14 -help                                         :prints menu\n")
    menu+=("    0  -exit")
    print(menu)
    
    
def add_ui(listOfComplexNb):
    complexNbStrg=input("Give me the complex number of form a+bi: ")
    ts.testComplexForm(complexNbStrg)
    complexNb=fs.complexNbFromString(complexNbStrg)
    fs.add(complexNb, listOfComplexNb)
    print(complexNbStrg+" was successfuly added!")
    
def insert_ui(listOfComplexNb):
    complexNbStrg=input("Give me the complex number of form a+bi: ")
    ts.testComplexForm(complexNbStrg)
    complexNb=fs.complexNbFromString(complexNbStrg)
    position=ts.checkNbIsNat(input("Enter the position where you want to put the new number: "))
    fs.insert(complexNb, listOfComplexNb, position)
    print(complexNbStrg+" was successfuly inserted!")
    
def removePos_ui(listOfComplexNb):
    position=ts.checkNbIsNat(input("Enter the position where you want to put the new number: "))
    fs.remove(position, listOfComplexNb)
    print("Complex number of position "+str(position)+" was successfuly removed!")
    
    
def removeSeq_ui(listOfComplexNb):
    startPosition=ts.checkNbIsNat(input("Enter the position from where you want to start deleting: "))
    endPosition=ts.checkNbIsNat(input("Enter the position where you want to end deleting: "))
    fs.removeSq(startPosition, endPosition, listOfComplexNb)
    print("The sequence was removed!")
    
def replace_ui(listOfComplexNb):
    oldNbS="Enter the old number: "
    ts.testComplexForm(oldNbS)
    newNbS="Enter the new number: "
    ts.testComplexForm(newNbS)
    oldNb=fs.complexNbFromString(oldNbS)
    newNb=fs.complexNbFromString(newNbS)
    fs.replace(oldNb, newNb, listOfComplexNb)
    print(oldNbS+" was replaced with "+newNbS)
    
def list_ui(listOfComplexNb):
    uiPrintList(listOfComplexNb)
    
def listReal_ui(listOfComplexNb):
    startPosition=ts.checkNbIsNat(input("Enter the position from where you want to start deleting: "))
    endPosition=ts.checkNbIsNat(input("Enter the position where you want to end deleting: "))
    uiPrintList(fs.listReal(startPosition, endPosition, listOfComplexNb))
    
def listModulo_ui(listOfComplexNb):
    prop=ts.checkProIsOk(input("Write one of the properties [<|=|>]:"))
    nb=ts.checkNbIsNat(input("Write the number you want to comapre with the modulo: "))
    fs.listModulo(prop, nb, listOfComplexNb)
    
def sum_ui(listOfComplexNb):
    startPosition=ts.checkNbIsNat(input("Enter the position from where you want to start deleting: "))
    endPosition=ts.checkNbIsNat(input("Enter the position where you want to end deleting: "))
    complexNb=fs.getSum(startPosition, endPosition, listOfComplexNb)
    print(complexNb)
    
def product_ui(listOfComplexNb):
    startPosition=ts.checkNbIsNat(input("Enter the position from where you want to start deleting: "))
    endPosition=ts.checkNbIsNat(input("Enter the position where you want to end deleting: "))
    complexNb=fs.getProduct(startPosition, endPosition, listOfComplexNb)
    print(complexNb)

def filterReal_ui(listOfComplexNb):
    if(len(listOfComplexNb)>0):
        listOfComplexNb=fs.filterReal(listOfComplexNb)
        print("Real Numbers filter applied!")
    else:
        print("Filter failed. List is empty!")

def filterMod_ui(listOfComplexNb):
    if(len(listOfComplexNb)>0):
        prop=ts.checkProIsOk(input("Write one of the properties [<|=|>]:"))
        nb=ts.checkNbIsNat(input("Write the number you want to comapre with the modulo: "))
        listOfComplexNb=fs.filterModulo(prop, nb, listOfComplexNb)
        print("Modulo filter applied!")
    else:
        print("List is empty, filter can not be applied.")

def undo_ui(listOfComplexNb, undoList):
    if len(undoList)>0:
        listOfComplexNb=undoList.pop()
        return listOfComplexNb
    else:
        raise ValueError("No more undos are available!")

def help_ui(listOfComplexNb):
    printMenu()

    
    
    
