"""
A Python implementation of an algorithm counting inversions in an array.
An inversion is a situation when a_i > a_(i+1) for i in range(0, N) where N is the length of the array.
"""



def countInversions(L):
    n = len(L)
    if n==1:
        return (L, 0)
    A = L[:n//2]
    B = L[n//2:]
    D = []
    x, y, z = 0, 0, 0
    (A, x) = countInversions(A)
    (B, y) = countInversions(B)
    (D, z) = mergeSplitInversions(A, B)
    return (D, x+y+z)
def mergeSort(A):
    n = len(A)
    if n == 1:
        return A
    else:
        return merge(mergeSort(A[:n//2]), mergeSort(A[n//2:]))

def merge(A, B):
    res = []
    j, k = 0, 0
    while j < len(A) and k < len(B):
        if A[j] < B[k]:
            res.append(A[j])
            j += 1
        else:
            res.append(B[k])
            k += 1
    if j < len(A):
        res = res + A[j:]
    else:
        res = res + B[k:]
    return res

def mergeSplitInversions(A, B):
    res = []
    z = 0
    j, k = 0, 0
    while j < len(A) and k < len(B):
        if B[k] < A[j]:
            res.append(B[k])
            k += 1
            z += len(A[j:])
        else:
            res.append(A[j])
            j += 1
    if j < len(A):
        res = res + A[j:]
    else:
        res = res + B[k:]
    return (res, z)
    
def parser(path):
    res = []
    f = open(path, 'r')
    for line in f:
        res.append(int(line.split()[0]))
    print(countInversions(res)[1])
