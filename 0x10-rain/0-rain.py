#!/usr/bin/python3
""" Rain based on walls """


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
                    "nexWallIndex": index}


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
        index = res["nexWallIndex"] - 1
    return waterRetained
