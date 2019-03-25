'''
Created on 21 Oct 2018

@author: Daci
@note: UI module for CLI AS_3-4
'''
import functionsAS34 as fs
import tests_module as tm
from copy import deepcopy

def main():
    complexNbList=fs.startWithElemts()
    undoList=[]
    commandsList={"add":ui_Add,"insert":ui_Insert,"remove":ui_Remove,"replace":ui_Replace,"list":ui_List,"sum":ui_Sum,"product":ui_Product,"filter":ui_Filter,"help":ui_Help}
    printMenu()
    while True:
        try:
            cmd=input("Write down the command:\n")
            cmdList=cmd.split(" ")
            if cmdList[0] in commandsList:
                if cmdList[0]!='list':
                    undoList.append(deepcopy(complexNbList))
                commandsList[cmdList[0]](cmdList[1:],complexNbList)
            elif(cmdList[0]=="undo"):
                complexNbList=ui_undo(cmdList[1:],undoList,complexNbList)
            elif(cmdList[0]=="exit" and tm.testExitCmd(cmdList[1:])):
                print("Thank you for using this application! Have a great day!")
                return 0
            else:
                print("Command is not correct, please try again!")
        except ValueError as er:
            print(er)
        

def uiPrintList(lista):
    n=len(lista)
    if(n==0):
        print("There is no complex number introduced!")
    complexNb=""
    for i in range(0,n):
        if i % 5 ==0:
            complexNb+="\n"
        complexNb+="("+fs.getComplexNbForm(fs.getReal(lista[i]), fs.getImg(lista[i]))+"); "
    print(complexNb[:len(complexNb)-2])

def printMenu():
    menu=("Complex numbers operations: \n")
    menu+=("  (indexing starts from 0 and a complex number has a+bi form)\n")
    menu+=("    add <number>                                 :add <number> at the end of the list\n")
    menu+=("    insert <number> at <position>                :insert number in list at position\n")
    menu+=("    remove <position>                            :remove number from position\n")
    menu+=("    remove <start position> to <end position>    :remove numbers between positions\n")
    menu+=("    replace <old number> with <new number>       :replace old_number with new_number\n")
    menu+=("    list                                         :writes the list of numbers\n")
    menu+=("    list real <start position> to <end position> :writes the real numbers between positions\n")
    menu+=("    list modulo [<|=|>] <number>                 :writes all numbers having modulo [<|=|>] than <number>\n")
    menu+=("    sum <start position> to <end position>       :writes the sum of numbers between positions\n")
    menu+=("    product <start position> to <end position>   :writes the product of numbers between positions\n")
    menu+=("    filter real                                  :keep only real numbers\n")
    menu+=("    filter modulo [<|=|>] <number>               :keep only those numbers having modulo [<|=|>] than <number>\n")
    menu+=("    undo                                         :restore from last change\n")
    menu+=("    help                                         :prints menu\n")
    menu+=("    exit")
    print(menu)


def ui_Add(cmd,listOfComplxNb):
    tm.testAddCmd(cmd)
    fs.add(fs.complexNbFromString(cmd[0]), listOfComplxNb)
    print(cmd[0]+" was successfuly added!")

def ui_Insert(cmd,listOfComplexNb):
    tm.testInsertCmd(cmd)
    fs.insert(fs.complexNbFromString(cmd[0]), listOfComplexNb, int(cmd[2]))
    print(cmd[0]+" was successfuly added!")
    
def ui_Remove(cmd,listOfComplexNb):
    tm.testRemoveCmd(cmd)
    if len(cmd)==3 and cmd[1]=='to':
        fs.removeSq(int(cmd[0]), int(cmd[2]), listOfComplexNb)
        print("The sequence was removed!")
    else:
        fs.remove(int(cmd[0]), listOfComplexNb)
        print("The elemen was successfuly removed!")

def ui_Replace(cmd,listOfComplexNb):
    tm.testReplaceCmd(cmd)
    fs.replace(fs.complexNbFromString(cmd[0]), fs.complexNbFromString(cmd[2]), listOfComplexNb)
    print(cmd[0]+" was successfuly replaced!")
    
def ui_List(cmd,listOfComplexNb):
    tm.testListCmd(cmd)
    if len(cmd)==0:
        lista=listOfComplexNb
    elif cmd[0]=="real":
        lista=fs.listReal(int(cmd[1]), int(cmd[3]), listOfComplexNb)
    else:
        lista=fs.listModulo(cmd[1], float(cmd[2]), listOfComplexNb)
    if len(lista)==0:
        print("There is no complex number in list!")
    else:
        uiPrintList(lista)

def ui_Help(cmd,listOfComplexNb):
    tm.testHelpCmd(cmd)
    printMenu()

def ui_Sum(cmd,listOfComplexNb):
    tm.testSumCmd(cmd)
    x=[fs.getSum(int(cmd[0]), int(cmd[2]), listOfComplexNb)]
    uiPrintList(x)
    
def ui_Product(cmd,listOfComplexNb):
    tm.testProductCmd(cmd)
    x=[fs.getProduct(int(cmd[0]), int(cmd[2]), listOfComplexNb)]
    uiPrintList(x)

def ui_Filter(cmd,listOfComplexNb):
    tm.testFilterCmd(cmd)
    if(len(listOfComplexNb)>0):
        if cmd[0]=="real":
            listOfComplexNb = fs.filterReal(listOfComplexNb)
        else:
            listOfComplexNb = fs.filterModulo(cmd[1], int(cmd[2]), listOfComplexNb)
        print("Operantion is successful!")
    else:
        print("Operation failed, list is empty!")

def ui_undo(cmd, undoList, complexNbList):
    tm.testUndoCmd(cmd)
    if len(undoList)>0:
        complexNbList=undoList.pop()
        return complexNbList
    else:
        raise ValueError("No more undos are available!")
   
        
        
        
        
        
        
        
        
        
        
        
        
        
        