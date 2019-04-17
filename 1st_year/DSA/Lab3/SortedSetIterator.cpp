#pragma once
#include <exception>
#include "SortedSet.h"
#include "SortedSetIterator.h"

void SortedSetIterator::first()
{
	this->crt = this->head;
}

void SortedSetIterator::next()
{
	if (!this->valid())
		throw std::exception("Invalid iterator!");
	this->crt = this->crt->nextNode;
}

bool SortedSetIterator::valid() const
{
	return this->crt!=nullptr;
}

TElem SortedSetIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception("Invalid!");
	return this->crt->valoare;
}

void SortedSetIterator::jumpBackward(int k)
{
	if(!this->valid())
		throw std::exception("Invalid!");
	while (k-- and this->valid())
		this->crt = this->crt->prevNode;
}
