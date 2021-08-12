#!/usr/bin/python3
""" no module """


def pgcd(a, b):
    """pgcd(a,b): calcul du 'Plus Grand Commun Diviseur'
    entre les 2 nombres entiers a et b"""
    if b == 0:
        return a
    else:
        r = a % b
        return pgcd(b, r)


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

        if pgcd(value, n) == value:
            return _recursive(val_after_copy, n, new_count, value)
        else:
            return _recursive(value + copied_val, n, count + 1, copied_val)


def minOperations(n):
    """  fewest number of operations needed to result in exactly n * "H" """
    default_value = 1
    if type(n) is not int or n <= 0:
        return 0

    return _recursive(default_value, n, 0, 0)
