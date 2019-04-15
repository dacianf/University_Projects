#pragma once
#include "Bag_DLLA.h"
#include "BagIterator.h"
#include <iostream>


Bag_DLLA::Bag_DLLA()
{
	this->capacity = 10;
	this->sizeUniq = 0;
	this->nbOfElements = 0;
	this->perechi = new std::pair<TElem, int>[10];
	this->next = new int[10];
	this->prev= new int[10];
	this->start = 0;
	this->last = 0;
	for (int i = 0; i < this->capacity; i++)
		this->freePos.push(i);
}

Bag_DLLA::Bag_DLLA(const Bag_DLLA & cBag)
{
	this->sizeUniq = cBag.sizeUniq;
	this->capacity = cBag.capacity;
	this->start = cBag.start;
	this->last = cBag.last;
	this->next = new int[this->capacity];
	this->prev = new int[this->capacity];
	this->perechi = new std::pair< TElem, int>[this->capacity];
	this->freePos = cBag.freePos;
	for (int i = 0; i < this->capacity; i++)
		this->prev[i] = cBag.prev[i],
		this->next[i] = cBag.next[i],
		this->perechi[i] = cBag.perechi[i];
}

void Bag_DLLA::add(TElem e)
{
	if (this->sizeUniq == this->capacity)
		this->resize();
	int currentIndex = this->start;
	if (this->sizeUniq == 0) {
		this->start = this->last = this->freePos.front();
		this->freePos.pop();
		this->perechi[this->start].first = e;
		this->perechi[this->start].second = 1;
		this->next[this->start] = -1;
		this->prev[this->start] = -1;
		this->sizeUniq++;
		this->nbOfElements++;
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
		this->sizeUniq++;
		this->nbOfElements++;
	}
	else if (this->perechi[currentIndex].first == e)
		this->perechi[currentIndex].second++,
		this->nbOfElements++;
}


bool Bag_DLLA::remove(TElem e)
{
	if (this->isEmpty())return false;
	int crt = this->start;
	if (crt == this->last and this->perechi[crt].first != e)return false;
	if (crt == this->last and this->perechi[crt].first == e and this->perechi[crt].second == 1) {
		this->perechi[crt].second = 0;
		this->nbOfElements--;
		this->sizeUniq--;
		this->freePos.push(crt);
		return true;
	}
	else if (crt == this->last and this->perechi[crt].second > 1){
		this->perechi[crt].second--;
		this->nbOfElements--;
		return true;
	}
	while (this->perechi[crt].first != e and crt != -1)
		crt = this->next[crt];
	if (crt == -1) return false;
	if (this->perechi[crt].second == 1) {
		if (crt != this->start)
			this->next[this->prev[crt]] = this->next[crt];
		else {
			this->start = this->next[crt];
		}
		if (crt != this->last)
			this->prev[this->next[crt]] = this->prev[crt];
		else this->last = this->prev[crt];
		this->nbOfElements--;
		this->sizeUniq--;
		this->freePos.push(crt);
	}
	else this->nbOfElements--, this->perechi[crt].second--;
	return true;
}

bool Bag_DLLA::search(TElem e) const
{
	if (this->sizeUniq) {
		int crt = this->start;
		while (this->next[crt] != -1 and this->perechi[crt].first != e)
			crt = this->next[crt];
		return this->perechi[crt].first == e;
	}
	return false;
}

int Bag_DLLA::nrOccurrences(TElem e) const
{
	if (!this->sizeUniq)return false;
	if (!this->search(e))return false;
	int crt = this->start;
	while (this->next[crt] != -1 and this->perechi[crt].first != e)
		crt = this->next[crt];
	return (this->perechi[crt].first == e) ? this->perechi[crt].second : 0;
}

int Bag_DLLA::size() const
{
	return this->nbOfElements;
}

BagIterator Bag_DLLA::iterator() const
{
	return BagIterator(*this);
}

bool Bag_DLLA::isEmpty() const
{
	return !this->sizeUniq;
}

Bag_DLLA::~Bag_DLLA()
{
	this->capacity = 0;
	this->sizeUniq = 0;
	this->nbOfElements = 0;
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
	for (int i = 0; i < this->sizeUniq; i++)
		auxEL[i] = this->perechi[i],
		auxN[i] = this->next[i],
		auxP[i] = this->prev[i];
	delete[] this->perechi;
	delete[] this->next;
	delete[] this->prev;
	this->perechi = auxEL;
	this->next = auxN;
	this->prev = auxP;
	for (int i = this->sizeUniq; i < this->capacity; i++)
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
