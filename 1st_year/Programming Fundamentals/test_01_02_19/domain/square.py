'''
Created on 1 Feb 2019

@author: Daci
'''


class Square():
    
    def __init__(self, y, x):
        self._x = x
        self._y = y
        
    @property
    def x(self):
        return self._x
    
    @property
    def y(self):
        return self._y