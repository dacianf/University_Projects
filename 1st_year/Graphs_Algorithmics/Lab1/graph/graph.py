'''
Created on 6 Mar 2019

@author: Daci
'''

class DirectedGraph:
    
    def __init__(self, vertexNb=0, edgeNb=0):
        self._vertexNb = vertexNb
        self._edgeNb = edgeNb
        self._dictIn = {}
        self._dictOut = {}
        self._dictOut.fromkeys([x for x in range(vertexNb)])
        self._dictIn.fromkeys([x for x in range(vertexNb)])
        self._cost = {}
    
    def isEdge(self, sourceNode, destinationNode):
        return sourceNode in self._dictIn[destinationNode] and destinationNode in self._dictOut[sourceNode]
    
    def addVertex(self, newVertex):
        if newVertex not in self._dictIn.keys() and newVertex not in self._dictOut.keys():
            self._dictIn[newVertex] = []
            self._dictOut[newVertex] = []
        else:
            raise ValueError("Vertex " + str(newVertex) + " already exist!")
    
    def removeVertex(self, vertex):
        if vertex in self._dictIn.keys() and vertex in self._dictOut.keys():
            for vx in self._dictIn[vertex]:
                self._dictOut[vx][0].remove(vertex)
            for vx in self._dictOut[vertex]:
                self._dictIn[vx][0].remove(vertex)
            del self._dictIn[vertex]
            del self._dictOut[vertex]
            for edge in self._cost.keys():
                if vertex in edge:
                    del self._cost[edge]
        else:
            raise ValueError("Vertex " + str(vertex) + " does not exist!")
    
    def addEdge(self, sourceNode, destinationNode, cost=0):
        if self.isEdge(sourceNode, destinationNode):
            raise ValueError("This edge already exist!")
        self._dictIn[destinationNode][0].append(sourceNode)
        self._dictOut[sourceNode][0].append(destinationNode)
        self._cost[(sourceNode, destinationNode)] = cost
    
    def removeEdge(self, sourceNode, destinationNode):
        if not self.isEdge(sourceNode, destinationNode):
            raise ValueError("This edge does not exist!")
        self._dictIn[destinationNode][0].remove(sourceNode)        
        self._dictOut[sourceNode][0].remove(destinationNode)
        del self._cost[(sourceNode, destinationNode)]        
        
x = DirectedGraph()
