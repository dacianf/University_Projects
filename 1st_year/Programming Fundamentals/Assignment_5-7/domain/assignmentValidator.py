'''
Created on 19 Nov 2018

@author: Daci
'''
from domain.validatorException import ValidatorException
import datetime


class AssignmentValidator:

    def validate(self, assignment):
        messages = []
        if type(assignment.id) != int or assignment.id <= 0:
            messages.append("Id must be a positive integer!")
        if type(assignment.description) != str or len(assignment.description) == 0:
            messages.append("Description must be a non-empty string!")
        if type(assignment.deadline) != str:
            messages.append("Deadline must be a non-empty string of form DD/MM/YYYY!")
        elif not self.__isDateOK(assignment.deadline):
            messages.append("Deadline must be a valid date of form DD/MM/YYYY!")
        if len(messages) > 0:
            raise ValidatorException(messages)
        return True

    def __isDateOK(self, date):
            '''
                Checks if an input string is a correct date of form DD/MM/YYYY
                Input: - string -
                Output: - True - if input date is a correct one
                        - False - otherwise
            '''
            try:
                day, month, year = date.split('/')
                datetime.datetime(int(year), int(month), int(day))
                return True
            except Exception:
                return False
