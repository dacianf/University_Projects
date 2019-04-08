#include "SortedSetIterator.h"


void SortedSetIterator::first()
{
	this->index = 0;
	this->currentElement = this->c.listOfElements.headNode;
}

void SortedSetIterator::next()
{
	if(this->valid)
}

bool SortedSetIterator::valid(Node<TElem>& x) const
{
	return this->currentElement;
}

TElem SortedSetIterator::getCurrent() const
{

	return TElem();
}
