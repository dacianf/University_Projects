'''
Created on 14 Nov 2018

@author: Daci
'''
from functions import *
def main():
    listOfFestivals=[]
    printMenu()
    fillList(listOfFestivals)
    while True:
        try:
            cmd=int(input("Write the command:"))
            if cmd==1:
                uiAddFest(listOfFestivals)
            elif cmd==2:
                uiShwFestSeas(listOfFestivals)
            elif cmd==3:
                uiSwListOfFestArt(listOfFestivals)
            elif cmd==4:
                printList(listOfFestivals)
            elif cmd==5:
                printMenu()
            elif cmd==0:
                return 0
            else:
                print("wrong cmd")
        except ValueError as er:
            print(er)
        except TypeError as er:
            print(er)
            
            
def uiAddFest(listOfFestivals):
    listArt=[]
    name=input("Name: ")
    month=input("Month: ")
    if month.isnumeric():
        month=int(month)
    else:
        raise ValueError("Month must be int")
    cost=input("Ticket Cost: ")
    if cost.isnumeric():
        cost=int(month)
    else:
        raise ValueError("cost must be int")
    n=int(input("Number of art:"))
    for i in range(n):
        art=input("Art name:")
        listArt.append(art)
    addMusicFestToList(listOfFestivals, createMusicFest(name, month, cost, listArt))
def uiShwFestSeas(listOfFestivals):
    se=input("Give season:")
    li=sortFestList(getFestBySeason(listOfFestivals, se))
    monthToStr(li)
    printList(li)
def uiSwListOfFestArt(listOfFestivals):
    name=input("Artist Name:")
    lista=getFestByGivenArt(listOfFestivals, name)
    printList(lista)
def printList(listOfFestivals):
    strg=""
    for fest in listOfFestivals:
        strg+=str(fest)+"\n"
    print(strg)
def printMenu():
    strg="Commands: \n"
    strg+="\t 1 - add a festival\n"
    strg+="\t 2 - show a fest by a given season\n"
    strg+="\t 3 - show a fest where a given art will perform\n"
    strg+="\t 4 - show list of fest\n"
    strg+="\t 5 - show cmds\n"
    strg+="\t 0 - exit"
    print(strg)
    
main()