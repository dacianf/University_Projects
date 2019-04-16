from seminarForBFS.roottree import RootTree
from seminarForBFS.path import getPath, bfs
from  graph.graph import Graph

def main():
    g = Graph()
    tree = bfs(g, 4)
    print(tree)


main()