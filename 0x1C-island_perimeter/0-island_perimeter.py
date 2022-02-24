#!/usr/bin/python3
""" modules """


class Node:
    """
        Node is a struct that encapsulate some data specific to the node
    """

    def __init__(self, isLand, x, y):
        """ init class """
        self.isLand = isLand
        self.neighbours = []
        self.isVisited = False
        self.x = x
        self.y = y
        self.inCorner = False
        self.inEdge = False
        self.perim = 4


def createNodesForTheGraph(grid):
    """
        convert a grid from [[0,1,0][0,1,0]] to a grid of Node
    """
    columns = len(grid[0])
    rows = len(grid)

    for i in range(rows):
        for j in range(columns):
            grid[i][j] = Node(grid[i][j] == 1, i, j)

    return grid


def createGraphGrid(grid):
    """
        each node have some other left, right, top, buttom neighbour node
        if it exist based on the Graph Data type
    """
    columns = len(grid[0])
    rows = len(grid)
    counter = 0
    for x in range(rows):
        for y in range(columns):
            currentNode = grid[x][y]
            if x == 0 or x == rows-1 or y == 0 or y == columns-1:
                currentNode.inEdge = True
            if x > 0:
                currentNode.neighbours.append(grid[x - 1][y])
                counter += 1
            if x < rows - 1:
                currentNode.neighbours.append(grid[x + 1][y])
            if y > 0:
                currentNode.neighbours.append(grid[x][y - 1])
            if y < columns - 1:
                currentNode.neighbours.append(grid[x][y + 1])

    grid[0][0].inCorner = True
    grid[0][columns-1].inCorner = True
    grid[rows-1][0].inCorner = True
    grid[rows-1][columns-1].inCorner = True

    return grid


def calculatePerimetre(node, perimetre):
    """ each neighbour in node that is a land we subtruct
        1 from the node max perimetre wich is 4, if all neighbour
        are lands the node perimetre is 0
    """
    if node.isLand is False:
        return perimetre

    node.isVisited = True

    for neighbour in node.neighbours:
        if neighbour.isLand is True:
            node.perim -= 1

    for neighbour in node.neighbours:
        if neighbour.isVisited is False and neighbour.isLand is True:
            return calculatePerimetre(neighbour, node.perim + perimetre)

    return node.perim + perimetre


def island_perimeter(grid):
    """ search for iselands and calculate their parametre
        return the sum of all iseland in the map
    """
    graphGrid = createNodesForTheGraph(grid)
    graphGrid = createGraphGrid(graphGrid)

    rows = len(graphGrid)
    columns = len(graphGrid[0])

    iselandPerimetre = 0
    allIselandPerimetre = 0
    for x in range(rows):
        for y in range(columns):
            node = graphGrid[x][y]
            if node.isVisited is False and node.isLand is True:
                allIselandPerimetre += calculatePerimetre(
                    node, iselandPerimetre)
                iselandPerimetre = 0
    return allIselandPerimetre
