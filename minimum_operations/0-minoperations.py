#!/usr/bin/python3

"""
Minimum number of operations to obtain the desired count of elements.
"""


def minOperations(n):
    if n <= 1:
        return 0    
    def factors(num):
        res = []
        for i in range(1, int(num**0.5) + 1):
            if num % i == 0:
                res.append(i)
                if i != num // i:
                    res.append(num // i)
        return res
        
    for i in factors(n)[1:]:
        if i < n:
            return i + minOperations(n // i)
    
    return n
 
