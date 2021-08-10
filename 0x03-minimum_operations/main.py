#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

if __name__ == '__main__':

    n = 9
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

    n = 12
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
    n = 13
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
    n = 4
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
    n = 15
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
