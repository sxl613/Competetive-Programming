"""
A basic quicksort implementation in Python.
Szczepan Lukowski
"""




import statistics
import math
counter = 0 
def parser(path):
    res = []
    f = open(path, 'r')
    for line in f:
        res.append(int(line.split()[0]))
    return res    
def P(A, l, r):
    if r - l < 2:
        return
    A[l], A[r-1] = A[r-1], A[l]
    pivot = A[l]
    i = l + 1
    for j in range(l+1, r):
        if A[j] < pivot:
            A[j], A[i] = A[i], A[j]
            i += 1
    A[l], A[i-1] = A[i-1], A[l]
    return i-1    

def Pmedian(A, l, r):
    if r - l < 2:
        return
    candidates = []
    candidates.append(A[l])
    candidates.append(A[mid(A,l,r)])
    candidates.append(A[r-1])
    k = l
    if A[mid(A,l,r)] == statistics.median(candidates):
        k = mid(A, l, r)
    elif A[r-1] == statistics.median(candidates):
        k = r-1
    A[l], A[k] = A[k], A[l]
    pivot = A[l]
    i = l + 1
    for j in range(l+1, r):
        if A[j] < pivot:
            A[j], A[i] = A[i], A[j]
            i += 1
    A[l], A[i-1] = A[i-1], A[l]
    return i-1
def qsm(A, l, r):
    global counter
    if r - l < 2:
        return
    m = Pmedian(A, l, r)
    counter += m-l - 1
    qsm(A, l, m)
    counter += r - m
    qsm(A, m+1, r)

def mid(A, l, r):
    if (r-l) % 2 == 0:
        return int(l + (((r-l) / 2) - 1))
    return l + int(math.floor(((r-l))/2))


