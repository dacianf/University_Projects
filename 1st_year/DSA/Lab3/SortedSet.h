#pragma once
#include "Node.h"
typedef int TElem;

typedef TElem TComp;

typedef bool(*Relation)(TComp, TComp);
class SortedSetIterator;
class SortedSet {
	friend class SortedSetIterator;
private:
	/*Representation of the SortedSet*/
	Node<TElem>* head;
	Node<TElem>* tail;
	Relation rel;
	int nbOfElements;

public:

	//constructor

	//theta(1)
	SortedSet(Relation r);

	//adds an element to the sorted set

	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 

	//it returns false

	//O(n)
	bool add(TComp e);

	//removes an element from the sorted set

	//if the element was removed, it returns true, otherwise false

	//O(n)
	bool remove(TComp e);
	//checks if an element is in the sorted set

	//O(n)
	bool search(TElem elem) const;

	//returns the number of elements from the sorted set

	//theta(1)
	int size() const;

	//checks if the sorted set is empty

	//theta(1)
	bool isEmpty() const;

	//returns an iterator for the sorted set

	//theta(1)
	SortedSetIterator iterator() const;
	// destructor

	//theta(1)
	~SortedSet();

	//O(n)
	void printNodes();
};

