import time

timer = time.time()
sols = 0

def can_extend(perm):
    i = len(perm) - 1
    for j in range(i):
        if i-j == abs(perm[i] - perm[j]):
            return False
    return True

def n_queens(perm, n):
    global sols
    if len(perm) == n:
        sols += 1
        return
    for k in range(n):
        if k not in perm:
            perm.append(k)
            if can_extend(perm):
                n_queens(perm, n)
            perm.pop()

for n in range(2, 13):
    sols = 0
    n_queens([], n)
    print("Found all %s solutions for n = %s in %s" %(sols, n, time.time() - timer))
    timer = time.time()
