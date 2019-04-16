from seminarForBFS.roottree import RootTree
from graph.graph import Graph
import heapq

def bfs(graph, startVertex):
    '''
        Returns the BFS tree rooted in the start vertex
    '''
    queue = list()
    distance = dict()
    queue.append(startVertex)
    tree = RootTree(startVertex)
    while (queue):
        x = queue.pop(0)
        for y in graph.parsenOut(x):
            if not tree.isVertex(y):
                queue.append(y)
                tree.addChild(x, y)
                distance[y] = distance[x] + 1
    return tree


def getPath(tree, targetVertex):
    '''
        Returns the branch of the tree from the root to targetVertex.
        Returns None if targetVertex is not in the tree
    '''
    if not tree.isVertex(targetVertex):
        return  None
    currentVertex = targetVertex
    path = []
    while currentVertex is not None:
        path.append(currentVertex)
        currentVertex = tree.getParent(currentVertex)
        path.reverse()
        return  path


def dfs(graph, startVertex):
    '''
        Returns the DFS tree rooted in the start vertex
    '''
    stack = []
    visited = set()
    visited.add(startVertex)
    stack.append((None, startVertex))
    tree = RootTree(startVertex)
    while (stack):
        parent, currentVertex = stack.pop()
        if currentVertex not in visited:
            if parent is not None:
                tree.addChild(parent, currentVertex)
            visited.add(currentVertex)
            for i in graph.parse_outbound(currentVertex):
                stack.append((currentVertex, i))
    return tree

def dfs_rec(graph, currentVertex, tree, visited):
    '''
    
    '''
    visited.add(currentVertex)
    for neighbour in graph.parse_outbound(currentVertex):
        if neighbour not in visited:
            dfs_rec(graph, currentVertex, tree, visited)

def createSmallGrapg():
    g = Graph(5)


def dijkstra(graph, cost, startVertex):
    '''
        Returns the tree of minimum cost path
    '''
    queue = list()
    distance = dict()
    distance[startVertex] = 0
    heapq.heappush(queue, (0, startVertex))
    tree = RootTree(startVertex)
    while (len(queue)):
        dx, x=heapq.heappop(queue)
        for y in graph.parsenOut(x):
            if y in distance.keys() or distance[y] > distance[x] + cost[(x, y)]:
                distance[y] = distance[x] + cost[(x, y)]
                queue.append(y)
                tree.addChild(x, y)
                distance[y] = distance[x] + 1
    return tree