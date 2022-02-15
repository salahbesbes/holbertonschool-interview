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
        # print("=>", res, "count", count, "biggest ", biggest)
        if res + biggest == val:
            count += 1
            return count
        if res + biggest > val:
            continue
        else:

            res += biggest
            count += 1
        while (res <= val-biggest):
            res += biggest
            count += 1
            if (res == val):
                return count
        # i += 1

    return -1
