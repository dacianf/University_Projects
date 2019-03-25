'''
Created on 10 Dec 2018

@author: Daci
'''
import operator
from types import LambdaType


def filterF(lista, key=lambda x: True):
    '''
        Filters a list by a key function
        Input: - lista - Iterable
               - key - function for filter
        Output: - x - list
    '''
    x = []
    for obj in lista:
        if key(obj):
            x.append(obj)
    return x


def sortF(arr, cmp=lambda x: x, reverse=False):
    '''
        Shell sort which can sort a list of objects
        Input: - arr - Iterable
               [cmp] a function for comparation or a lambda key
               [reverse] T|F (by default is False)
        output: - arr - sorted iterable
    '''
    lt = operator.gt if reverse else operator.lt
    n = len(arr)
    gap = n // 2

    def oper(x, y):
        if isinstance(cmp, LambdaType):
            return lt(cmp(x), cmp(y))
        elif not isinstance(cmp, LambdaType):
            try:
                return cmp(x, y)
            except Exception:
                pass

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and oper(temp, arr[j - gap]):
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr
