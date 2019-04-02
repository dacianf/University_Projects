'''
Created on 20 Mar 2019
PROBLEMA 8
@author: Daci
'''
class Bag:

    # creates a new, empty Bag
    def __init__(self):
        #theta(1)
        self._elements = []
        self._frequency = []
        self._numberOfElements = 0
        self._numberOfUniqueElements = 0

    # adds a new element to the Bag
    def add(self, e):
        #O(n)
        if e not in self._elements:
            self._elements.append(e)
            self._frequency.append(1)
            self._numberOfUniqueElements += 1
        else:
            self._frequency[self._elements.index(e)] += 1
        self._numberOfElements += 1
        

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    def remove(self, e):
        #O(n)
        try:
            indexOfElem = self._elements.index(e)
        except ValueError as e:
            return False
        self._frequency[indexOfElem] -= 1
        if self._frequency[indexOfElem] == 0:
            del self._frequency[indexOfElem]
            del self._elements[indexOfElem]
            self._numberOfUniqueElements -= 1
        self._numberOfElements -= 1
        return True

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    def search(self, e):
        #O(n)
        return e in self._elements

    # counts and returns the number of times the element e appears in the bag
    def nrOccurrences(self, e):
        #O(n)
        try:
            indexOfElem = self._elements.index(e)
            return self._frequency[indexOfElem]
        except:
            return 0

    # returns the size of the Bag (the number of elements)
    def size(self):
        #Theta(1)
        return self._numberOfElements

    # returns True if the Bag is empty, False otherwise
    def isEmpty(self):
        #Theta(1)
        return self._numberOfElements == 0

    # returns a BagIterator for the Bag
    def iterator(self):
        #Theta(1)
        return BagIterator(self)


class BagIterator:
    #any operation bellow is Theta(1)
    #creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    def __init__(self, b):
        self._bag = b
        self._current = 0
        if self._bag.size():
            self._crtFreq = self._bag._frequency[self._current]
        else:
            self._crtFreq = 0
        self._index = 0

    # returns True if the iterator is valid
    def valid(self):
        return self._current < self._bag._numberOfUniqueElements

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    def getCurrent(self):
        if self._current == self._bag._numberOfUniqueElements:
            raise ValueError()
        return self._bag._elements[self._current]

    # moves the iterator to the next element
    #throws ValueError if the iterator is not valid
    def next(self):
        if self._index == self._bag.size():
            raise ValueError()
        if self._crtFreq > 1:
            self._crtFreq -= 1
            self._index += 1
        else:
            self._current += 1
            if self.valid():
                self._crtFreq = self._bag._frequency[self._current]
            self._index += 1
            

    # sets the iterator to the first element from the Bag
    def first(self):
        self._current = 0
        self._crtFreq = self._bag._frequency[self._current]
        self._index = 0