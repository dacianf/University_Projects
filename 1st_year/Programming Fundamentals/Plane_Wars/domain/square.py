'''
Created on 15 Dec 2018

@author: Daci
'''
from domain.square_exception import SquareException


class Square:
    def __init__(self, longitude=0, latitude=0):
        if type(longitude) != int or type(latitude) != int:
            raise SquareException("Longitude and latitude must be integers!")
        self._lat = latitude
        self._long = longitude

    @property
    def latitude(self):
        return self._lat

    @property
    def longitude(self):
        return self._long

    def reverse(self):
        self._lat, self._long = self._long, self._lat

    def __str__(self):
        return "Longitude: " + str(self.longitude).ljust(4) + "Latitude: " + str(self.latitude)

    def __add__(self, sq):
        return Square(self.longitude + sq.longitude, self.latitude + sq.latitude)

    def __sub__(self, sq):
        return Square(self.longitude - sq.longitude, self.latitude - sq.latitude)

    def __eq__(self, sq):
        if isinstance(sq, Square):
            return self.longitude == sq.longitude and self.latitude == sq.latitude
        raise ValueError("You must compare to squares!")
