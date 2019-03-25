'''
Created on 19 Nov 2018

@author: Daci
'''
from domain.validatorException import ValidatorException


class StudentValidator:
    '''
    '''
    def validate(self, student):
        messages = []
        if type(student.id) != int or student.id <= 0:
            messages.append("Id must be a positive integer!")
        if type(student.name) != str or len(student.name) == 0:
            messages.append("Name must be a non-empty string!")
        if type(student.group) != str or len(student.group) == 0:
            messages.append("Group must be a non-empty string!")
        if len(messages) > 0:
            raise ValidatorException(messages)
        return True
