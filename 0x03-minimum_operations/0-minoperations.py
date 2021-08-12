#!/usr/bin/python3
""" this code wont work for big numbers because of the limitation
of recursive depth deep in PYTHON
i have tested with C# and it worked for all cases that didnt with python"""


def greatest_divider(n, div):
    """ search for greateest devider of 'n'  """
    if n == div:
        return n
    elif n % div == 0:
        return int(n / div)
    else:
        return greatest_divider(n, div + 1)


def search_for_min_operation(n):
    """ if we get the greatest devider of 'n' we are sure to do (n/devider)
    opearion if we n is equal to greatest divider (no more devider) we return
    'n' and do all the sum of others iterations
    as exemple  n = 20 => GD = 10 => GD  = 5 => GD = n we return 5 + all other
    operations in each iteration """

    greatest_div = greatest_divider(n, 2)
    if greatest_div == n:
        return n
    else:
        return int(n/greatest_div) + search_for_min_operation(greatest_div)


def minOperations(n):
    """  fewest number of operations needed to result in exactly n * "H" """
    if type(n) is not int or n <= 0:
        return 0

    return search_for_min_operation(n)
