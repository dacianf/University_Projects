'''
Created on 15 Dec 2018

@author: Daci
'''
from domain.plane_exception import PlaneException
from domain.square import Square


class PlaneValidator:
    def __init__(self, plane):
        self._plane = plane
        self._errors = []

    def validate(self):
        try:
            if type(self._plane.cabinPos) != Square:
                self._errors.append("Cabin position must be of Square type!")
            if self._plane.orientation not in ["up", "down", "left", "right"]:
                self._errors.append("Planes orientation must be one of [up, down, left, right]!")
            if self._plane.upperWings < self._plane.lowerWings:
                self._errors.append("Upper wings must be larger or equal than lower wings!")
            if not self._plane.upperWings % 2 or not self._plane.lowerWings:
                self._errors.append("Wings lenght must be an odd number!")
            if self._plane.upperWings < 3 or self._plane.upperWings < 3:
                self._errors.append("Wings lenght must be grater or equal than 3!")
            if self._plane.body < 3:
                self._errors.append("Body lenght must be at least 3!")
        except TypeError:
            self._errors.append("Orientation must be a str\n\tplanes wings and body must be int!")
        if len(self._errors):
            raise PlaneException(self._errors)
