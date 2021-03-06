//
// Created by daci on 5/26/19.
//
#pragma once

#include "SortedIndexedList.h"
#include <stack>
//unidirectional iterator for a container

class SortedIndexedList;
class ListIterator {
    friend class SortedIndexedList;
private:
    //Constructor receives a reference of the container.
    //after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty
    //contains a reference of the container it iterates over
    const SortedIndexedList &sl;
    Node bka;
    Node* crtNode;
    std::stack<Node *> *s;

    explicit ListIterator(const SortedIndexedList &sl_);

    /* representation specific for the iterator*/
public:
    //sets the iterator to the first element of the container
    void first();

    //moves the iterator to the next element
    //throws exception if the iterator is not valid
    void next();

    //checks if the iterator is valid
    bool valid() const;

    //returns the value of the current element from the iterator
    // throws exception if the iterator is not valid
    TComp getCurrent() const;
};



