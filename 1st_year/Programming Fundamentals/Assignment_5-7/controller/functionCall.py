'''
Created on 27 Nov 2018

@author: Daci
'''


class FunctionCall:
    '''
    '''

    def __init__(self, functionName, *parameters):
        self._functionRef = functionName
        self._params = parameters

    def call(self):
        self._functionRef(*self._params)
