#!/usr/bin/python3

"""
Minimum number of operations to obtain the desired count of elements.
"""


def biggest_divisor(n):
    for i in range(int(n / 2), 0, -1):
        if n % i == 0:
            return i


def minOperations(n):
    if n == 2:
        return 2
    elif n == 1 or n == 0 or n < 0:
        return 0
    elif n % 2 == 0:
        return minOperations(n / 2) + 2
    else:
        bd = biggest_divisor(n)
        if bd == 1:
            return n
        else:
            return minOperations(bd) + int(n / bd)