#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([50, 1, 25], 37))
print(makeChange([1, 25], 37))
# print(makeChange([5, 28], 36))
print(makeChange([2], 36))
