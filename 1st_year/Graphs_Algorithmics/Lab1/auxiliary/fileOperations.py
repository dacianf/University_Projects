'''
Created on 20 Mar 2019

@author: Daci
'''
import random


def readGraphFromFile(fileName, Graph):
    '''
        Reads objects from a file and return that object
        Input: - fileName - string
               - Graph - Graph reference that will be returned
        Output: graph
    '''
    with open(fileName, 'r') as f:
        graph = Graph([int(number) for number in f.readline().split(' ')][0], 0)

        line = f.readline()
        while line:
            graph.add_edge(*[int(v) for v in line.split(' ')])
            line = f.readline()
    return graph


def saveGraphInFile(fileName, graph):
    strg = ""
    strg += str(len(graph._nodes)) + " " + str(graph._edges) + "\n"
    for lst in graph._out.keys():
        for v in graph._out[lst]:
            strg += str(lst) + ' ' + str(v[0]) + ' ' + str(v[1]) + '\n'
    with open(fileName, 'w') as f:
        f.write(strg)
    return True


def getRandomGraph(GraphConstructor, nVertex, nEdges):
    """Constructs and returns a randomly generated graph
    with n vertices and m edges.
    ctor must be a callable that gets the number of vertices and
    creates a graph with the given number of vertces and with no edges"""
    g = GraphConstructor(nVertex, 0)
    addedEdges = 0
    while addedEdges < nEdges:
        x = random.randrange(0, nVertex)
        y = random.randrange(0, nVertex)
        c = random.randrange(0, 41323132123) % 200
        if not g.isEdge(x, y):
            g.add_edge(x, y, c)
            addedEdges += 1
    return g
