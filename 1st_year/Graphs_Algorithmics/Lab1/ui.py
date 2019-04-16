'''
Created on 20 Mar 2019

@author: Daci
'''
from auxiliary.fileOperations import readGraphFromFile,getRandomGraph ,saveGraphInFile
from graph.graph import Graph


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
    print(strg)


def start():
    gr = Graph()
    #gr = readGraphFromFile("graph1k.txt", Graph)
    while True:
        cmd = input(">")
        if(cmd=="0"):
            exit(0)
        elif(cmd == "A"):
            node = (input("\t>"))
            gr.add_node(node)
        elif(cmd == "B"):
            node = int(input("\t>"))
            gr.remove_edge(node)
        elif(cmd == "C"):
            _from = int(input("\tFrom edge: "))
            _to = int(input("\tTo edge: "))
            _cost = int("\tWith cost: ")
            gr.add_edge(_from, _to, _cost)
        elif(cmd == "D"):
            _from = int(input("\tFrom edge: "))
            _to = int(input("\tTo edge: "))
            gr.remove_edge(_from, _to)
        elif(cmd == "E"):
            nNode = int(input("\tNumber of nodes: "))
            nEdge = int(input("\tNumber of edges: "))
            grAux = getRandomGraph(Graph, nNode, nEdge)
            print(str(grAux))
            _print = input("Do you want to save this new graph into a file or to load this version or nothing?(file or load or n)\t")
            if(_print=="file"):
                fl = input("Name of destination file for random graph:\n\t>")
                saveGraphInFile(fl, grAux)
            elif(_print=="load"):
                gr = grAux
        elif(cmd == "F"):
            fl = input("\tName of the file to load from:\n\t\t>")
            gr = readGraphFromFile(fl, Graph)
        elif(cmd == "G"):
            fl = input("\tName of destination file:\n\t\t>")
            saveGraphInFile(fl, gr)
        elif(cmd == "1"):
            print(gr.number_of_vertices())
        elif(cmd == "2"):
            _from = int(input("\tFrom edge: "))
            _to = int(input("\tTo edge: "))
            print(gr.check_edge(_from, _to))
        elif(cmd == "3"):
            vr = int(input("\tGive the vertex: "))
            print("in degree: " + str(gr.in_degree(vr)) + " \nout degree: " + str(gr.out_degree(vr)))
        elif(cmd == "4"):
            vr = int(input("\tGive the vertex: "))
            for i in gr.parse_outbound(vr):
                print(i)
        elif(cmd == "5"):
            vr = int(input("\tGive the vertex: "))
            for i in gr.parse_inbound(vr):
                print(i)
        elif(cmd == "6"):
            pass

printMenu()
start()
