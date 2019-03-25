'''
Created on 23 Nov 2018

@author: Daci
'''

class AssignmentGradeDTO:
    '''
    '''
    def __init__(self,assignment,grade):
        self._assig=assignment
        self._grade=grade
        
    @property
    def assignmentID(self):
        return self._assig.id
    @property
    def assignmentDesc(self):
        return self._assig.description
    @property
    def assignmentDeadline(self):
        return self._assig.deadline
    @property
    def grade(self):
        return self._grade
    
    def __str__(self):
        return "Grade: "+str(self.grade).ljust(10)+"Assignment: "+self.assignmentDesc.ljust(15)+"Deadline: "+self.assignmentDeadline