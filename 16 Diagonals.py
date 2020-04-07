# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import time

timer = time.time()

n = 5
diag = 16
grid = [[0 for i in range(n)] for j in range(n)]

def isValid(i, j, n):
    if i >= 0 and i < n and j >= 0 and j < n:
        return True
    return False

def isGood(i, j, n):
    if grid[i][j] == 0:
        return True
    if grid[i][j] == 1:
        if isValid(i-1, j-1, n) and grid[i-1][j-1] == 1:
            return False
        if isValid(i-1, j, n) and grid[i-1][j] == 2:
            return False
        if isValid(i, j-1, n) and grid[i][j-1] == 2:
            return False
        return True
    if grid[i][j] == 2:
        if isValid(i-1, j, n) and grid[i-1][j] == 1:
            return False
        if isValid(i-1, j+1, n) and grid[i-1][j+1] == 2:
            return False
        if isValid(i, j-1, n) and grid[i][j-1] == 1:
            return False
        return True

def find_sol(x, y, n, d, diag):
    global grid
    global timer
    if d == diag:
        print("Found solution in", (time.time() - timer))
        timer = time.time()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    print('_', end = ' ')
                elif grid[i][j] == 1:
                    print('\\', end = ' ')
                else:
                    print('/', end = ' ')
            print()
        return
    if x == n or ((n-x-1)*n + (n-y)) < diag-d:
        return
    p, q = 0, 0
    if y == n-1:
        p = x+1
    else:
        p = x
    if y == n-1:
        q = 0
    else:
        q = y+1
    d += 1
    for i in [2, 1, 0]:
        grid[x][y] = i
        if i == 0:
            d -= 1
        if isGood(x, y, n):
            find_sol(p, q, n, d, diag)

find_sol(0, 0, n, 0, diag)
