#pragma once
#include <utility>
#include <queue>
typedef int TElem;

class BagIterator;
class Bag_DLLA
{
	friend class BagIterator;
private:

	int sizeUniq;
	int capacity;
	int nbOfElements;
	std::pair < TElem, int > * perechi;
	int* next;
	int* prev;
	int start;
	int last;
	int firstEmpty;
public:

	//constructor
	
	//theta(1)
	Bag_DLLA();

	//adds an element to the bag

	//O(n)
	void add(TElem e);

	//removes one occurrence of an element from a bag

	//returns true if an element was removed, false otherwise (if e was not part of the bag)

	//O(n)
	bool remove(TElem e);

	//checks if an element appears in the bag
	
	//O(n)
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	
	//O(n)
	int nrOccurrences(TElem e) const;


	//returns the number of elements from the bag

	//theta(1)
	int size() const;

	//returns an iterator for this bag

	//theta(1)
	BagIterator iterator() const;

	//checks if the bag is empty

	//theta(1)
	bool isEmpty() const;

	//returns the number of unique elements that appear frequency times
	//throws an exception if frequency is negative or zero
	//O(n)
	int elementsWithThisFrequency(int frequency) const;

	//destructor

	//theta(1)
	~Bag_DLLA();

	//O(n)
	void printPairs();
private:
	//O(n)
	void resize();
};

