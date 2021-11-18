#!/usr/bin/python3
""" Rain based on walls """


def getIndexFarestAdjacentRightWall(wallIndex, walls):
    """ walls = [0, 3, 2, 2, 0, 0, 2, 2, 3] this case is not handled yet  """
    adjacent = wallIndex
    while (adjacent + 1 != len(walls)):
        if walls[adjacent + 1] != 0 and walls[adjacent] != 0:
            adjacent += 1
        else:
            break

    return adjacent - wallIndex


def getVolumeBetweenTowWals(firstWall, walls):
    """ calculate the water between the first wall and the first next wall """
    firstWallHeight = walls[firstWall]
    widthContainer = 0
    heightContainer = 0
    for index, wall in enumerate(walls[firstWall + 1:]):
        if wall != 0:

            widthContainer = index
            heightContainer = min(firstWallHeight, wall)
            return {"containerVolume": widthContainer * heightContainer,
                    "nextWallIndex": index}


def rain(walls):
    """ calculate the tetained water """

    if type(walls) is not list or walls is []:
        return 0

    waterRetained = 0
    for index in range(0, len(walls)):

        res = getVolumeBetweenTowWals(index, walls)
        if (res is None):
            break
        waterRetained += res["containerVolume"]
        index = res["nextWallIndex"] - 1

    return waterRetained
