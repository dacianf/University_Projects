'''
Created on 14 Nov 2018

@author: Daci
'''
from copy import deepcopy
from operator import itemgetter
def createMusicFest(name,month,ticketCost,listOfArt):
    '''
        Creates a dictionary of form {Name, Month, TicketCost, ListOfArt}
        Input: -name- string
               -month- int between 1 and 12
               -ticketCost- int >0
               -listOfArt- list
        Output: dict of form {Name, Month, TicketCost, ListOfArt}
    '''
    if type(name)!=str:
        raise TypeError("Name must be a string!")
    if not (type(month)==int and 1<=month<=12):
        raise ValueError("Month must be a natural number betweent 1 and 12")
    if not (type(ticketCost)==int and ticketCost>0):
        raise ValueError("Ticket cost must be an integer >0")
    if not(type(listOfArt)==list and len(listOfArt)>0):
        raise ValueError("Artists list must be a list with at least one element!")
    return {"Name":name,"Month":month,"TicketCost":ticketCost,"ListOfArt":listOfArt}

def addMusicFestToList(listOfFestivals,festival):
    '''
        Adds in list of festivals a festival
        Input: -listOfFestivals- list
               -festival- dict
    '''
    checkNameInList(listOfFestivals, getName(festival))
    listOfFestivals.append(festival)
    
def getName(festival):
    return festival["Name"]
def getMonth(festival):
    return festival["Month"]
def getTicketCost(festival):
    return festival["TicketCost"]
def getListOfArt(festival):
    return festival["ListOfArt"]

def setName(festival,newName):
    if type(newName)!=str:
        raise TypeError("Name must be a string!")
    festival["Name"]=newName
def setMonth(festival,newMonth):
    if not (type(newMonth)==int and 1<=newMonth<=12):
        raise ValueError("Month must be a natural number betweent 1 and 12")
    festival["Month"]=newMonth
def setTicketCost(festival,newTicketCost):
    if not (type(newTicketCost)==int and newTicketCost>0):
        raise ValueError("Ticket cost must be an integer >0")
    festival["TicketCost"]=newTicketCost
def setListOfArt(festival,newArtList):
    if not(type(newArtList)==list and len(newArtList)>0):
        raise ValueError("Artists list must be a list with at least one element!")
    festival["ListOfArt"]=deepcopy(newArtList)
    
def checkNameInList(listOfFestivals,name):
    '''
        Checks if a name is already in list
        Input: -listOfFestivals- list of dict
               -name- str
        Output: raise err if name already in list
                False - if name is not in list
    '''
    if len(listOfFestivals)>0:
        for fest in listOfFestivals:
            if getName(fest)==name:
                raise ValueError("Name already exists in the list!")
    return False

def testAdd():
    listOfFestivals=[]
    assert len(listOfFestivals)==0
    addMusicFestToList(listOfFestivals, createMusicFest("Nevastuica", 2, 32, ["Johno","Mary"]))
    assert len(listOfFestivals)==1
    try:
        addMusicFestToList(listOfFestivals, createMusicFest(3, 2, 32, ["Johno","Mary"]))
        addMusicFestToList(listOfFestivals, createMusicFest("Nevastuica", 34, 32, ["Johno","Mary"]))
        addMusicFestToList(listOfFestivals, createMusicFest("Nevastuica", 2, -5, ["Johno","Mary"]))
        addMusicFestToList(listOfFestivals, createMusicFest("Nevastuica", 2, 32, 2))
        addMusicFestToList(listOfFestivals, createMusicFest("Nevastuica", 2, 32, "sd"))
        addMusicFestToList(listOfFestivals, createMusicFest("Nevastuica", 2, 32, []))
        assert False
    except:
        assert True
        
def addArtToList(listOfArt,art):
    if type(art)==str and len(art)!=0:
        listOfArt.append(art)
    else:
        raise ValueError("Artist must have a non-empty name")
    
def fillList(list):
    addMusicFestToList(list, createMusicFest("Nevastuica", 2, 32, ["Johno","Mary"]))
    addMusicFestToList(list, createMusicFest("Microsi", 1, 65, ["Gary","Tim","Mircke"]))
    addMusicFestToList(list, createMusicFest("Sticlosi", 8, 900, ["Crety","Donni","Burpss","Mary"]))
    addMusicFestToList(list, createMusicFest("Gretizziiz", 10, 5, ["Marlow","Mary"]))
    addMusicFestToList(list, createMusicFest("Untold", 12, 50, ["Joheew","Clowe"]))
testAdd()

def getFestByGivenArt(listOfFestivals,artistName):
    '''
        Returns a list of festivals where given artist will perform
        Input:-listOfFestivals- list of dict
              -artistName- string
        Output: -festArtList- list of dict
    '''
    festArtList=[]
    for fest in listOfFestivals:
        li=getListOfArt(fest)
        for art in li:
            if art==artistName:
                festArtList.append(fest)
    return festArtList
    
def getFestBySeason(listOfFestivals,season):
    #dictOfMonths={1:"January",2:"February",3:"March",4:"Aprill",5:"May",6:"June",7:"July",8:"August",9:"September",10:"October",11:"November",12:"December"}
    dictlistOfSeasons={"winter":[12,1,2],"spring":[3,4,5],"summer":[6,7,8],"autumn":[9,10,11]}
    lista=[]
    for fest in listOfFestivals:
        if getMonth(fest) in dictlistOfSeasons[season.lower()]:
            lista.append(fest)
    return lista
def sortFestList(listOfFestivals):
    lista=sorted(listOfFestivals,key=itemgetter("Month","Name"))
    return lista
def testGetFestByGivenArt():
    listOfFestivals=[]
    fillList(listOfFestivals)
    assert len(listOfFestivals)==5
    artList=getFestByGivenArt(listOfFestivals, "Mary")
    assert len(artList)==3
    artList=getFestByGivenArt(listOfFestivals, "132213")
    assert len(artList)==0
    artList=getFestByGivenArt(listOfFestivals, "Gary")
    assert len(artList)==1
def monthToStr(lista):
    dictOfMonths={1:"January",2:"February",3:"March",4:"Aprill",5:"May",6:"June",7:"July",8:"August",9:"September",10:"October",11:"November",12:"December"}
    for fest in lista:
        fest["Month"]=dictOfMonths[getMonth(fest)]
testGetFestByGivenArt()