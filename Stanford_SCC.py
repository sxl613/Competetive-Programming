import sys

class Graph(object):
    def __init__(self, name):
        self.name = name
        self.vertices = []
        self.V = 0
        self.t = 0
        self.s = 0
    def addVertex(self, v):
        self.vertices.append(v)
        self.V += 1
    def addEdge(self, u, v):
        u.out.append(v)
        v.inc.append(u)
    def addEdgeByNum(self, u, v):
        self.vertices[u-1].out.append(self.vertices[v-1])
        self.vertices[v - 1].inc.append(self.vertices[u - 1])

class Vertex(object):
    def __init__(self, number):
        self.number = 0
        self.f = None
        self.leader = 0
        self.inc = []
        self.out = []
        self.explored = False
        self.visited = False
    def __cmp__(self, other):
        return self.f < other.f



def DFS(G, v, r=False):
    """
    :type G: Graph
    :type v: Vertex

    Recursive Depth-First Search that calculates finishing times. If r is true, DFS searches the inverse of G.

    """
    v.explored = True
    v.leader = G.s

    if not r:
        for u in v.out:
            if not (u.explored):
                DFS(G, u)
        G.t += 1
        v.f = G.t
    else:
        for u in v.inc:
            if not (u.explored):
                DFS(G, u, True)
        G.t += 1
        v.f = G.t

def DFSLoop(G, r = False):
    """

    :type G: Graph
    """
    G.t = 0
    G.s = 0
    if not r:
        for i in range(G.V-1, -1, -1):
            if not G.vertices[i].explored:
                G.s = i+1
                DFS(G, G.vertices[i])
    else:
        for i in range(G.V-1, -1, -1):
            if not G.vertices[i].explored:
                G.s = i+1
                DFS(G, G.vertices[i], True)

def xxx(u):
    return u.f

def xx(u, v):
    if u.f < v.f:
        return 1
    elif u.f > v.f:
        return -1
    else:
        return 0

def SCC(G):
    DFSLoop(G, True)
    copy = sorted(G.vertices, key=lambda x: x.f)
    G.vertices = copy
    for v in G.vertices:
        v.explored = False
    DFSLoop(G)
    print("Done.")

def scc(G):
    dfsloop(G, True)
    copy = sorted(G.vertices, key=lambda x: x.f)
    G.vertices = copy
    for v in G.vertices:
        v.explored = False
        v.visited = False
    dfsloop(G)
    print("Done.")

def constructGraph(path, n):
    f = open(path, 'r')
    G = Graph("Stanford Design and Analysis Assignment 4")
    for i in range(1, n):
        v = Vertex(i)
        v.number = i
        G.addVertex(v)
    for line in f:
        data = line.split()
        G.addEdgeByNum(int(data[0]), int(data[1]))
    return G


def depth_first_search(G, s):
    stack = [s]
    visited = [s]
    s.visited = True
    s.unexplored = False
    while len(stack) > 0:
        node = stack.pop()
        node.visited = True
        node.leader = G.s
        for v in node.out:
            if not v.visited:
                stack.append(v)
                visited.append(v)
            else:
                G.t += 1
                node.f = G.t
                v.explored = True
                if v.explored:
                    continue
    for v in range(len(visited) - 1, -1, -1):
        if visited[v].f == None:
            G.t += 1
            visited[v].f = G.t

def dfs_rev(G, s):
    stack = [s]
    visited = [s]
    s.visited = True
    s.unexplored = False
    while len(stack) > 0:
        node = stack.pop()
        node.visited = True
        node.leader = G.s
        for v in node.inc:
            if not v.visited:
                stack.append(v)
                visited.append(v)
            else:
                G.t += 1
                node.f = G.t
                v.explored = True
                if v.explored:
                    continue
    for v in range(len(visited)-1, -1, -1):
        if visited[v].f == None:
            G.t += 1
            visited[v].f = G.t


def dfsloop(G, r = False):
    """

    :type G: Graph
    """
    G.t = 0
    G.s = 0
    if not r:
        for i in range(G.V-1, -1, -1):
            if not G.vertices[i].visited:
                G.s = i+1
                depth_first_search(G, G.vertices[i])
    else:
        for i in range(G.V-1, -1, -1):
            if not G.vertices[i].visited:
                G.s = i+1
                dfs_rev(G, G.vertices[i])
