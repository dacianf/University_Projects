class RootTree:
    def __init(self, root):
        '''
            Creates a tree with only a root
        '''
        self.__root = root
        self.__parent = {root: None}
        self.__children = {}

    def addChild(self, parent, child):
        '''

        Add a child for the given parent
        Pre: Parent is an existing vertex
            Child doesn't exist in the tree
        '''
        self.__parent[child] = parent
        self.__children[parent].append(child)
        self.__children[child] = []

    def getRoot(self):
        '''
            Returns the root of the tree
        '''
        return self.__root

    def getParent(self, child):
        '''
            Return the parent of the given child
        '''
        return self.__parent[child]

    def getChildren(self, parent):
        '''
            Returns the list of children of a given child
        '''
        return self.__children[parent]

    def isVertex(self, theVertex):
        '''
            Boolean function.
            post: TRUE - the Vertex is a vertex of the tree
                  False - otherwise
        '''
        return theVertex in self.__parent.keys()

    def recursiveToString(self, subRoot, depth):
        s = "%s%s\n" % ("\t" * depth, subRoot)
        for child in self.getChildren(subRoot):
            s += self.recursiveToString(child, depth)

    def __str__(self):
        self.recursiveToString(self.__root, 0)
