from seminarForBFS.roottree import RootTree
def bfs(graph, startVertex):
    '''
        Returns the BFS tree rooted in the start vertex
    '''
    queue = list()
    distance = dict()
    queue.append(startVertex)
    tree = RootTree(startVertex)
    while(queue):
        x = queue.pop()
        for y in graph.parsenOut(x):
            if not tree.isVertex(y):
                queue.append(y)
                tree.addChild(x,y)
                distance[y]=distance[x]+1
    return tree
