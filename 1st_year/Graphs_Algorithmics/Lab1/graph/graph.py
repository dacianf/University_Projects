'''
Created on 6 Mar 2019

@author: Daci
'''
from copy import copy, deepcopy


class Graph:

    def __init__(self, nodes=0, edges=0):
        self._nodes = {i for i in range(nodes)}
        self._edges = edges
        self._in = dict()
        self._out = dict()

    def __str__(self):
        res = ''
        for lst in self._out.keys():
            for v in self._out[lst]:
                res += str(lst) + ' to ' + str(v[0]) + ' costs ' + str(v[1]) + '\n'
        return res

    def add_edge(self, _from, _to, _cost=0):

        if _from not in self._nodes:
            return
        if _to not in self._nodes:
            return

        if _from not in self._out:
            self._out[_from] = []
        self._out[_from].append((_to, _cost))

        if _to not in self._in:
            self._in[_to] = []
        self._in[_to].append((_from, _cost))

        self._edges += 1

    def remove_edge(self, _from, _to):

        if _from not in self._nodes:
            return
        if _to not in self._nodes:
            return

        if _from in self._out.keys():
            for dest in self._out[_from]:
                if dest[0] == _to:
                    self._out[_from].remove(dest)

    def add_node(self, node):

        if node in self._nodes:
            return

        if node not in self._nodes:
            self._nodes.add(node)

    def remove_node(self, node):

        if node not in self._nodes:
            return

        for out in self._out[node].keys():
            for _in in self._in[out]:
                if _in == node:
                    self._in[out].remove(_in)
            self._out[node].remove(out)

    def number_of_vertices(self):
        return len(self._nodes)

    def iterate_vertices(self):
        for node in self._nodes:
            yield node

    def isEdge(self, first, second):

        if first not in self._nodes:
            return False
        if second not in self._nodes:
            return False
        #check for duplicate edge
        return self._out[second] and self._in[first]

    def in_degree(self, node):

        if node not in self._nodes:
            return

        return len(self._in[node])

    def out_degree(self, node):

        if node not in self._nodes:
            return

        return len(self._out[node])

    def parse_outbound(self, node):

        if node not in self._nodes:
            return

        if node in self._out:
            for target in self._out[node]:
                yield target

    def parse_inbound(self, node):

        if node not in self._nodes:
            return

        if node in self._in:
            for target in self._in[node]:
                yield target

    def get_cost(self, _from, _to):

        if _from not in self._nodes:
            return

        if _to not in self._nodes:
            return

        for x in self._out[_from]:
            if x[0] == _to:
                return x[1]

    def clone(self):
        graph = Graph(0, 0)
        graph._edges = self._edges
        graph._nodes = copy(self._nodes)
        graph._in = deepcopy(self._in)
        graph._out = deepcopy(self._out)
        return graph