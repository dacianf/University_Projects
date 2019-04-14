#pragma once
#include <utility>
#include <queue>
typedef int TElem;
#include "BagIterator.h"

class BagIterator;
class Bag_DLLA
{
	friend class BagIterator;
private:

	int sizeI;
	int capacity;
	std::pair < TElem, int > * perechi;
	std::queue<int> freePos;
	int* next;
	int* prev;
	int start;
	int last;
public:

	//constructor

	Bag_DLLA();

	//adds an element to the bag

	void add(TElem e);

	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	bool remove(TElem e);

	//checks if an element appears in the bag

	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag

	int nrOccurrences(TElem e) const;


	//returns the number of elements from the bag

	int size() const;

	//returns an iterator for this bag

	BagIterator iterator() const;

	//checks if the bag is empty

	bool isEmpty() const;

	//destructor

	~Bag_DLLA();

	void printPairs();
private:
	void resize();
};

