'''
Created on 27 Nov 2018

@author: Daci
'''


class ControllerException(Exception):
    '''
    '''

    def __init__(self, messageList=["Validation error!"]):
        self._messageList = messageList
        messageList = []

    @property
    def messages(self):
        return self._messageList

    def __str__(self):
        result = ""
        for message in self._messageList:
            result += message
            result += "\n"
        return result
