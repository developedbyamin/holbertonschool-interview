#!/usr/bin/python3
"""Reads stdin line by line and computes metrics
If count of lines is evenly divided by 10 and/or
keyboardinterrupt
all info will be printed"""

import sys

file_size = 0
count = 0
ids = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


def print_msg(ids, file_size):
    print("File size: {}".format(file_size))
    for key, val in sorted(ids.items()):
        if val != 0:
            print("{}: {}".format(key, val))


try:
    for line in sys.stdin:
        nums = line.rstrip().split(' ')
        try:
            if nums[-2] in ids:
                ids[nums[-2]] += 1
            file_size += int(nums[-1])
            count += 1
            if count % 10 == 0:
                print_msg(ids, file_size)
        except BaseException:
            pass


finally:
    print_msg(ids, file_size)