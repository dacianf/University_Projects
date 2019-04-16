#pragma once
#include "SortedSet.h"

//unidirectional iterator for a container
class SortedSet;
class SortedSetIterator {
	friend class SortedSet;
private:

	//Constructor receives a reference of the container.

	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

	//theta(1)
	explicit SortedSetIterator(const SortedSet& c) : c(c), head(c.head), crt(c.head) {};

	//contains a reference of the container it iterates over

	const SortedSet& c;
	Node<TElem>* head;
	Node<TElem>* crt;

	/* representation specific for the iterator*/

public:

	//sets the iterator to the first element of the container
	//theta(1)
	void first();

	//moves the iterator to the next element

	//throws exception if the iterator is not valid

	//theta(1)
	void next();

	//checks if the iterator is valid

	//theta(1)
	bool valid() const;

	//returns the value of the current element from the iterator

	// throws exception if the iterator is not valid

	//theta(1)
	TElem getCurrent() const;

};



