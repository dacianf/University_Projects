'''
Created on 20 Mar 2019

@author: Daci
'''

def printMenu():
    strg = "\nGraph algorithms - practical work no. 1\n"
    strg += "\t1 - get number of vertices;\n"
    strg += "\t2 - check if there is an edge between 2 given vertices;\n"
    strg += "\t3 - print in and out degree of a given vertex;\n"
    strg += "\t4 - parse outbound edges of a given vertex;\n"
    strg += "\t5 - parse inbound edges of a given vertex;\n"
    strg += "\t6 - get the endpoints of a specified edge;\n"
    strg += "\t7 - modify the cost of an edge;\n"
    strg += "\t8 - print cost of an edge;\n"
    strg += "\t9 - copy the graph;\n"
    strg += " -commands to modify graph:\n"
    strg += "\tA - add vertex;\n"
    strg += "\tB - remove vertex;\n"
    strg += "\tC - add edge;\n"
    strg += "\tD - remove edge;\n"
    strg += " -commands to load/save graph:\n"
    strg += "\tE - generate random graph;\n"
    strg += "\tF - load graph from file;\n"
    strg += "\tG - save graph in file;\n"
    strg += "\t0 - exit.\n"
    strg += "LAB2 -- 3. Write a program that finds the connected components of an undirected \ngraph using a depth-first traversal of the graph.\n"
    strg += "To select any of above option type the specific value. \n\n"
    return strg

print(printMenu())