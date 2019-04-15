#pragma once
#include "Bag_DLLA.h"
#include "BagIterator.h"

void BagIterator::first()
{
	this->crt = this->bag.start;
	this->crtFreq = bag.perechi[this->crt].second;
}

void BagIterator::next()
{
	if (!this->valid())
		throw std::exception("Invalid iterator!");
	this->crtFreq--;
	if (this->crtFreq == 0) {
		this->crt = bag.next[this->crt];
		this->crtFreq = bag.perechi[this->crt].second; 
	}
}

bool BagIterator::valid() const
{
	if (this->bag.isEmpty())return false;
	return (this->crt != -1) ? true : false;
}

TElem BagIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception("Invalid iterator!");
	return bag.perechi[this->crt].first;
}