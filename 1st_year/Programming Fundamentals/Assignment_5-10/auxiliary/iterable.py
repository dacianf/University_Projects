'''
Created on 10 Dec 2018

@author: Daci
'''


class Iterable:

    def __init__(self):
        self._objects = []

    def __setitem__(self, key, value):
        if key >= 0 and key <= len(self._objects):
            self._objects[key] = value
        else:
            raise ValueError("Key must be an int between 0 and " + str(len(self._objects)))

    def __delitem__(self, key):
        if key > 0 and key <= len(self._objects):
            del self._objects[key]
        else:
            raise ValueError("Key must be an int between 0 and " + str(len(self._objects)))

    def __iter__(self):
        self._index = 0
        return self

    def __next__(self):
        if self._index < len(self._objects):
            self._index += 1
            return self._objects[self._index - 1]
        else:
            raise StopIteration

    def __add__(self, obj):
        self._objects.append(obj)
        return self

    def __len__(self):
        return len(self._objects)

    def __getitem__(self, index):
        if index >= 0 and index <= len(self._objects):
            return self._objects[index]
        else:
            raise ValueError("Key must be an int between 0 and " + str(len(self._objects)))
