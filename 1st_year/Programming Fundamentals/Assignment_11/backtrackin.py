'''
Created on 9 Jan 2019

@author: Daci
'''
from copy import deepcopy


def prntRec(left, right, strg):
    if(left == 0 and right == 0):
        print(strg)
    if(left > right):
        return
    if (left > 0):
        prntRec(left - 1, right, strg + "(")
    if (right > 0):
        prntRec(left, right - 1, strg + ")")


def paranteze(n):
    prntRec(n / 2, n / 2, "")


#paranteze(22)
elem = [-1, 1]
sol = [0 for x in range(100)]
i = 1


def valid(sol):
    s = 0
    for val in sol:
        s += val
        if s < 0:
            return False
    return s == 0


def printSol(sol, n):
    strg = ""
    for i in range(n):
        if sol[i] == 1:
            strg += '('
        else:
            strg += ')'
    print(strg)


def bktRec(n, sol, x=0):
    if n < 2 or n % 2:
        return 0
    for i in range(-1, 1):
        if i == 0:
            sol[x] = 1
        else:
            sol[x] = i
        if x == n - 1:
            if valid(sol):
                printSol(sol, n)
        else:
            bktRec(n, sol, x + 1)


def bktIter(n):
    if n < 2 or n % 2:
        return 0
    sol = [0 for x in range(1000)]
    st = []
    st.append(0)
    st.append(sol)
    while len(st):
        sol = st.pop()
        x = st.pop()
        for i in range(-1, 1):
            if i == 0:
                sol[x] = 1
            else:
                sol[x] = i
            if x == (n - 1):
                if valid(sol):
                    printSol(sol, n)
            else:
                st.append(x + 1)
                st.append(deepcopy(sol))


def binSe(arr, n):
    lenA = len(arr)
    mid = lenA // 2
    left = 0
    right = lenA
    while(1 < mid < lenA and n != arr[mid]):
        if n > arr[mid]:
            left = mid + 1
        else:
            right = mid - 1
        mid = (left + right) // 2
    if mid < lenA and arr[mid] == n:
        return mid
    return -1


def binSeRec(arr, n):
    mid = len(arr) // 2
    if len(arr) == 1:
        if arr[0] == n:
            return True
        return False
    if n >= arr[mid]:
        return binSeRec(arr[mid:], n)
    else:
        return binSeRec(arr[:mid], n)



arr = [1,2,5,6,7,8,9,10,11,12]

print(binSeRec(arr, 123)) 