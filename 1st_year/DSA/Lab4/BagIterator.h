#pragma once
#include <exception>
#include "Bag_DLLA.h"


//unidirectional iterator for a container
class Bag_DLLA;
class BagIterator {
	friend class Bag_DLLA;
private:

	//Constructor receives a reference of the container.

	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

	explicit BagIterator(const Bag_DLLA& c) : bag(c), crt(c.start) {};

	//contains a reference of the container it iterates over

	const Bag_DLLA& bag;
	int crt;
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

	TElem getCurrent() const;
};
