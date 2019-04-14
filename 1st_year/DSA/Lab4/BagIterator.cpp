#include "BagIterator.h"

void BagIterator::first()
{
	this->crt = this->bag.start;
}

void BagIterator::next()
{
	if (!this->valid())
		throw std::exception("Invalid iterator!");
	this->crt = bag.next[this->crt];
}

bool BagIterator::valid() const
{
	return (this->crt != -1) ? true : false;
}

TElem BagIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception("Invalid iterator!");
	return bag.perechi[this->crt].first;
}
