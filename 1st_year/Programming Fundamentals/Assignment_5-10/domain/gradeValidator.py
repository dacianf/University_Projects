'''
Created on 19 Nov 2018

@author: Daci
'''
from domain.validatorException import ValidatorException


class GradeValidator:

    def validate(self, grade):
        messages = []
        if type(grade.id) != int or grade.id <= 0:
            messages.append("Id must be a positive integer!")
        if type(grade.studentID) != int or grade.studentID <= 0:
            messages.append("StudentID must be a positive integer!")
        if type(grade.assignID) != int or grade.assignID <= 0:
            messages.append("AssignmentID must be a positive integer!")
        if type(grade.grade) != float or not (0 <= grade.grade <= 10):
            messages.append("Grade must be real number between 0 and 10!")
        if len(messages) > 0:
            raise ValidatorException(messages)
        return True
