#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(arr, val):
    """
        determine the fewest number of coins needed to meet
                a given amount total
    """

    if (val <= 0):
        return 0
    arr.sort(reverse=True)

    res = 0
    count = 0
    for i in range(0, len(arr)):
        biggest = arr[i]
        res += biggest
        count += 1
        if res == val:
            return count
        if res > val:
            count -= 1
            res = 0
            continue
        while (res <= val-biggest):
            res += biggest
            count += 1
            if (res == val):
                return count
        # i += 1

    return -1
