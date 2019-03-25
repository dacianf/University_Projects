'''
Created on 21 Nov 2018

@author: Daci
'''
class StudentLateDTO:
    '''
    '''
    
    
    def __init__(self,student,assignmnetList):
        self._student=student
        self._assigList=assignmnetList
        
    @property
    def id(self):
        return self._student.id
    @property
    def name(self):
        return self._student.name
    
    @property
    def assignmentsList(self):
        return self._assigList
    
    def __str__(self):
        strg="Name: "+self.name
        for a in self.assignmentsList:
            strg+="\n\tAssignment: "+a.description.ljust(11)+"Deadline: "+a.deadline
        return strg
    
    def __eq__(self,stud2):
        return self._student.id==stud2.id