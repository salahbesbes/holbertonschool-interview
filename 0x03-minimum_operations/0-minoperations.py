#!/usr/bin/python3
""" this code wont work for big numbers because of the limitation
of recursive depth deep in PYTHON
i have tested with C# and it worked for all cases that didnt with python"""
import math


def copy_all(value, count, n):
    """ multiply the value by 2 and update the count number by 2
    every time we copy_all we have to paste after """

    if (value != n):
        count += 2
        value *= 2

    return {"count": count, "value": value}


def _recursive(value, n, count, copied_val):
    """ check if the pgcd of n and value is equal to value
    if its equal we paste if its not we copy_all and paste  """

    if value == n:
        return count
    elif value == 1:
        res = copy_all(value, count, n)
        val_after_copy = res["value"]
        new_count = res["count"]
        return _recursive(val_after_copy, n, new_count, value)
    else:
        res = copy_all(value, count, n)
        val_after_copy = res["value"]
        new_count = res["count"]

        if math.gcd(value, n) == value:
            return _recursive(val_after_copy, n, new_count, value)
        else:
            return _recursive(value + copied_val, n, count + 1, copied_val)


def minOperations(n):
    """  fewest number of operations needed to result in exactly n * "H" """
    default_value = 1
    if type(n) is not int or n <= 0:
        return 0

    return _recursive(default_value, n, 0, 0)

# second methode also recursive same issue


# """ this code wont work for big numbers because of the limitation
# of recursive depth deep in PYTHON
# i have tested with C# and it worked for all cases that didnt with python
# """


# def greatest_divider(n, div):
#     # """ search for greateest devider of 'n'  """
#     if n == div:
#         return n
#     elif n % div == 0:
#         return int(n / div)
#     else:
#         return greatest_divider(n, div + 1)


# def search_for_min_operation(n):
#     """ if we get the greatest devider of 'n' we are sure to do (n/devider)
#     opearion if we n is equal to greatest divider (no more devider) we return
#     'n' and do all the sum of others iterations
#     as exemple  n = 20 => GD = 10 => GD = 5 => GD = n we return 5 + all other
#     operations in each iteration """

#     greatest_div = greatest_divider(n, 2)
#     if greatest_div == n:
#         return n
#     else:
#         return int(n/greatest_div) + search_for_min_operation(greatest_div)


# def minOperations(n):
#     """  fewest number of operations needed to result in exactly n * "H" """
#     if type(n) is not int or n <= 0:
#         return 0

#     return search_for_min_operation(n)
