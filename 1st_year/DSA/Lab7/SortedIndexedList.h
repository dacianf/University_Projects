//
// Created by daci on 5/26/19.
//
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);

#define NULL_TELEM -1;

#pragma once
typedef struct Node {
    TComp info = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    int nbOfNodesInL = 0;
} Node;
#include <iostream>
#include <exception>
#include "ListIterator.h"

class ListIterator;

class SortedIndexedList {
    friend class ListIterator;
private:
    //representation of SortedIndexedList
    Node* root;
    int nbOfElems;
    Relation rel;

    Node *removeRec(Node *treeRoot, TComp e, bool &removed);
public:
    // constructor
    SortedIndexedList(Relation r);

    // returns the number of elements from the list
    int size() const;

    // verifies if the list is empty
    bool isEmpty() const;

    // returns an element from a position
    //throws exception if the position is not valid
    TComp getElement(int pos) const;

    // adds a new element to the list
    void add(TComp e);

    // removes an element from a given position
    //returns the removed element
    //throws an exception if the position is not valid
    TComp remove(int pos);

    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    int search(TComp e) const;

    // returns an iterator set to the first element of the list or invalid if the list is empty
    ListIterator iterator();

    //destructor
    ~SortedIndexedList();

    void print();
};






