'''
Created on 15 Dec 2018

@author: Daci
'''
from builtins import property


class BoardException(Exception):

    def __init__(self, error):
        self._msg = error

    @property
    def message(self):
        return self._msg

    def __str__(self):
        if type(self.message) == list:
            err = ""
            for i in self.message:
                err += i + "\n"
            return err
        return self.message
