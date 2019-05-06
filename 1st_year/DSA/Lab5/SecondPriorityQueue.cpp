#include "SecondPriorityQueue.h"
#include <exception>
#include <iostream>

SecondPriorityQueue::SecondPriorityQueue(Relation r)
{
	this->cap = 3;
	this->len = 0;
	this->elems = new Element[3];
	this->R = r;
}

void SecondPriorityQueue::push(TElem e, TPriority p)
{
	if (this->len == this->cap - 1)this->resize();
	this->elems[++this->len] = Element(e, p);
	this->bubbleUp(this->len);
}

Element SecondPriorityQueue::top() const
{
	if (this->len < 2)throw exception("len is < 2!");
	if (this->len == 2) return this->elems[2];
	if (this->R(this->elems[2].second, this->elems[3].second)) return this->elems[2];
	return this->elems[3];
}

Element SecondPriorityQueue::pop()
{
	if (this->len < 2)throw exception("len is < 2!");
	if (this->len == 2) { return this->elems[this->len--]; }
	Element delElem;
	int pos = 0;
	if (this->R(this->elems[2].second, this->elems[3].second))
		delElem = this->elems[2], pos = 2;
	else delElem = this->elems[3], pos = 3;
	this->elems[pos] = this->elems[this->len--];
	this->bubbleDown(pos);
	return delElem;
}

bool SecondPriorityQueue::atMostOne() const
{
	if (this->len <= 1) return true;
	return false;
}

SecondPriorityQueue::~SecondPriorityQueue()
{
	this->len = 0;
	this->cap = 0;
	delete[] this->elems;
}

void SecondPriorityQueue::resize()
{
	this->cap *= 2;
	Element* aux = new Element[this->cap];
	for (int i = 1; i <= this->len; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}

void SecondPriorityQueue::bubbleUp(int p)
{
	int poz{ p };
	auto elem{ this->elems[poz] };
	int parent{ p / 2 };
	while (poz > 1 and this->R(elem.second, this->elems[parent].second)) {
		this->elems[poz] = this->elems[parent];
		poz = parent;
		parent = poz / 2;
	}
	this->elems[poz] = elem;
}

void SecondPriorityQueue::bubbleDown(int p)
{
	int poz = p, maxChild = -1;
	Element elem = this->elems[p];
	while (poz < this->len)
	{
		maxChild = -1;
		if (poz * 2 <= this->len) maxChild = poz * 2;
		if (poz * 2 + 1 <= this->len and this->R(this->elems[2 * poz + 1].second, this->elems[2 * poz].second))
			maxChild = poz * 2 + 1;
		if (maxChild != -1 and this->R(this->elems[maxChild].second, elem.second))
			swap(this->elems[poz], this->elems[maxChild]),
			poz = maxChild;
		else poz = this->len + 1;
	}
}

void SecondPriorityQueue::print()
{
	for (int i = 1; i <= this->len; i++)
		std::cout << "( " << this->elems[i].first << " , " << this->elems[i].second << " ); ";
	std::cout << "\n";
}
