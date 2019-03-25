'''
Created on 21 Nov 2018

@author: Daci
'''


class StudentGradeDTO:
    '''
    '''

    def __init__(self, studName, grade):
        self._studName = studName
        self._grade = grade

    @property
    def name(self):
        return self._studName

    @name.setter
    def name(self, name):
        self._studName = name

    @property
    def grade(self):
        return self._grade

    @grade.setter
    def grade(self, grade):
        self._grade = grade

    def __str__(self):
        return "Name: " + self.name.ljust(20) + "Grade:" + str(self.grade)
