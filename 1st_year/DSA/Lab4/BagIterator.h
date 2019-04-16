#pragma once
#include <exception>
#include"Bag_DLLA.h"

//unidirectional iterator for a container
class Bag_DLLA;
class BagIterator {
	friend class Bag_DLLA;
private:

	//Constructor receives a reference of the container.

	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

	const Bag_DLLA& bag;
	int crt;
	int crtFreq;

	//theta(1)
	explicit BagIterator(const Bag_DLLA& c) : bag(c), crt(c.start), crtFreq(c.perechi[crt].second) {};
	//contains a reference of the container it iterates over

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
