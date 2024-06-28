#!/usr/bin/python3
"""
Rainwater retention calculation module.
"""


def rain(walls):
    """
    Calculate the total amount of rainwater retained given wall heights.

    Args:
    walls (list): Non-negative integers representing the heights of walls.

    Returns:
    int: Total amount of rainwater retained.
    """
    if not walls:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n
    water_retained = 0

    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill right_max array
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate water retained
    for i in range(n):
        water_retained += max(0, min(left_max[i], right_max[i]) - walls[i])

    return water_retained
