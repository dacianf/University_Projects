'''
Created on 20 Mar 2019

@author: Daci
'''
from graph.graph import DirectedGraph
def readGraphFromFile(fileName):
    '''
        Reads objects from a file and return that object
        Input: - fileName - string
               - Object - object that will be returned
        Output: - objList - list of new objects
    '''
    objList = []
    try:
        f = open(fileName, "r")
        line = f.readline().strip().split()
        graph = DirectedGraph(vertexNb=int(line[0]), edgeNb=int(line[1]))
        while len(line) > 0:
            line = f.readline().strip().split()
            if len(line) == 3:
                graph.addEdge(int(line[0]), int(line[1]), int(line[2]))
            else:
                graph.addEdge(int(line[0]), int(line[1]))
        f.close()
    except IOError as er:
        raise "Error: " + str(er)
    return objList