#include "Bag_DLLA.h"
#include <iostream>


Bag_DLLA::Bag_DLLA()
{
	this->capacity = 10;
	this->sizeI = 0;
	this->perechi = new std::pair<TElem, int>[10];
	this->next = new int[10];
	this->prev= new int[10];
	this->start = 0;
	this->last = 0;
	for (int i = 0; i < this->capacity; i++)
		this->freePos.push(i);
}

void Bag_DLLA::add(TElem e)
{
	if (this->sizeI == this->capacity)
		this->resize();
	int currentIndex = this->start;
	if (this->sizeI == 0) {
		this->freePos.pop();
		this->perechi[0].first = e;
		this->perechi[0].second = 1;
		this->next[0] = -1;
		this->prev[0] = -1;
		this->sizeI++;
		return;
	}
	while (this->next[currentIndex] != -1 and this->perechi[currentIndex].first != e)
		currentIndex = this->next[currentIndex];
	if (this->perechi[currentIndex].first != e) {
		int nextFree = this->freePos.front();
		this->freePos.pop();
		this->perechi[nextFree].first = e;
		this->perechi[nextFree].second = 1;
		this->next[nextFree] = -1;
		if (currentIndex == 0)
			this->prev[nextFree] = -1;
		this->prev[nextFree] = currentIndex;
		this->next[currentIndex] = nextFree;
		this->last = nextFree;
		this->sizeI++;
	}
	else if (this->perechi[currentIndex].first == e)
		this->perechi[currentIndex].second++;
}


bool Bag_DLLA::remove(TElem e)
{
	int crt = this->start;
	while (this->next[crt] != -1 and this->perechi[crt].first != e)
		crt = this->next[crt];
	if (this->perechi[crt].first != e)
		return false;
	this->perechi[crt].second--;
	if (this->perechi[crt].second == 0) {
		if(crt != this->start)
			this->next[this->prev[crt]] = this->next[crt];
		if (crt != this->last)
			this->prev[this->next[crt]] = this->prev[crt];
		if (crt == this->last) this->last = this->prev[crt];
		else if (crt == this->start) this->start = this->next[crt];
		this->perechi[crt] = std::pair<TElem, int>{ -1, -1 };
		this->freePos.push(crt);
		this->sizeI--;
	}
	return true;
}

bool Bag_DLLA::search(TElem e) const
{
	int crt = this->start;
	while (this->next[crt] != -1 and this->perechi[crt].first != e)
		crt = this->next[crt];
	return this->perechi[crt].first == e;
}

int Bag_DLLA::nrOccurrences(TElem e) const
{
	int crt = this->start;
	while (this->next[crt] != -1 and this->perechi[crt].first != e)
		crt = this->next[crt];
	return (this->perechi[crt].first == e) ? this->perechi[crt].second : 0;
}

int Bag_DLLA::size() const
{
	return this->sizeI;
}

BagIterator Bag_DLLA::iterator() const
{
	return BagIterator(*this);
}

bool Bag_DLLA::isEmpty() const
{
	return this->sizeI;
}

Bag_DLLA::~Bag_DLLA()
{
	this->capacity = 0;
	this->sizeI = 0;
	delete[] this->perechi;
	delete[] this->next;
	delete[] this->prev;
	this->start = 0;
	this->last = 0;
}

void Bag_DLLA::resize()
{
	this->capacity *= 2;
	auto auxEL = new std::pair<TElem, int>[this->capacity];
	auto auxN = new int[this->capacity];
	auto auxP = new int[this->capacity];
	for (int i = 0; i < this->sizeI; i++)
		auxEL[i] = this->perechi[i],
		auxN[i] = this->next[i],
		auxP[i] = this->prev[i];
	delete[] this->perechi;
	delete[] this->next;
	delete[] this->prev;
	this->perechi = auxEL;
	this->next = auxN;
	this->prev = auxP;
	for (int i = this->sizeI; i < this->capacity; i++)
		this->freePos.push(i);
}

void Bag_DLLA::printPairs() {
	int crt = this->start;
	while (crt != this->last)
	{
		std::cout << this->perechi[crt].first << " -- " << this->perechi[crt].second << "\n";
		crt = this->next[crt];
	}
	std::cout << this->perechi[crt].first << " -- " << this->perechi[crt].second << "\n";
}