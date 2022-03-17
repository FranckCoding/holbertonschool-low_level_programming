#!/usr/bin/python3


"""
Module to calculate the perimeter of an island.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island

    Parameters
    ----------
    grid: list int
        the representation of island in list int.

    Return
    ------
    Perimeter of island:
        width + width + height + height
    """
    tmp = 0
    width = 0
    height = 0

    for x in range(len(grid)):
        if 1 in grid[x]:
            height += 1
            for y in range(len(grid[1])):
                if grid[x][y] == 1:
                    tmp += 1
            if tmp > width:
                width = tmp
            tmp = 0

    return 2 * width + 2 * height
