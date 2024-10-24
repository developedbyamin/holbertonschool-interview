#!/usr/bin/python3
"""
Defines function to calculate the perimeter of an island
represented by a list of list of ints
"""

def island_perimeter(grid):
    """
    Calculates the perimeter of an island represented by a list of list of ints.

    Parameters:
        grid (list of list of ints): represents the island and water.
            * 0s represent water & 1s represent land.
            * Cells are connected horizontally/vertically (not diagonally).
            * Grid is rectangular, with width and height <= 100.
            * The grid is completely surrounded by water.
            * Islands do not have "lakes" (water completely inside the island).
            * There is only one island or no island.

    Returns:
        int: the perimeter of the island.
    """
    perimeter = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                # Check the surrounding cells.
                perimeter += 4  # Start with 4 sides
                if row > 0 and grid[row - 1][col] == 1:  # Top neighbor
                    perimeter -= 1
                if row < len(grid) - 1 and grid[row + 1][col] == 1:  # Bottom neighbor
                    perimeter -= 1
                if col > 0 and grid[row][col - 1] == 1:  # Left neighbor
                    perimeter -= 1
                if col < len(grid[row]) - 1 and grid[row][col + 1] == 1:  # Right neighbor
                    perimeter -= 1
    return perimeter
