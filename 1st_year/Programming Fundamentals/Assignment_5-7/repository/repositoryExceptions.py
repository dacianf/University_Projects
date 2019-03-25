'''
Created on 19 Nov 2018

@author: Daci
'''


class RepoException(Exception):

    def __init__(self, msg):
        self._message = msg

    @property
    def messages(self):
        return self._message

    def __str__(self):
        return self._message
