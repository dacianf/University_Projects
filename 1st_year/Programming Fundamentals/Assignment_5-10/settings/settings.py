'''
Created on 3 Dec 2018

@author: Daci
'''


class Settings:
    '''
        Application settings
    '''

    def __init__(self, ui, repo, repoSt=None, repoAs=None, repoGr=None):
        self._ui = ui
        self._repo = repo
        self._repoSt = repoSt
        self._repoAs = repoAs
        self._repoGr = repoGr

    @property
    def ui(self):
        return self._ui

    @ui.setter
    def ui(self, ui):
        self._ui = ui

    @property
    def repo(self):
        return self._repo

    @repo.setter
    def repo(self, repo):
        self._repo = repo

    @property
    def repoSt(self):
        return self._repoSt

    @repoSt.setter
    def repoSt(self, repoSt):
        self._repoSt = repoSt

    @property
    def repoAs(self):
        return self._repoAs

    @repoAs.setter
    def repoAs(self, repoAs):
        self._repoAs = repoAs

    @property
    def repoGr(self):
        return self._repoGr

    @repoGr.setter
    def repoGr(self, repoGr):
        self._repoGr = repoGr

    def __str__(self):
        strg = "UI: " + self.ui + "\nRepository: " + self.repo
        if self.repo == "memory":
            return strg
        return strg + "\nStudent Repository: " + self.repoSt + "\nAssignment Repository: " + self.repoAs + "\nGrade Repository: " + self.repoGr
