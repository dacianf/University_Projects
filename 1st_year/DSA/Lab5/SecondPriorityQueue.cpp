#include "SecondPriorityQueue.h"
#include <exception>
#include <iostream>
//theta(1)
SecondPriorityQueue::SecondPriorityQueue(Relation r)
{
	this->cap = 3;
	this->len = 0;
	this->elems = new Element[3];
	this->R = r;
}
//O(n*log3(n))
void SecondPriorityQueue::push(TElem e, TPriority p)
{
	if (this->len == this->cap - 1)this->resize();
	this->elems[++this->len] = Element(e, p);
	this->bubbleUp(this->len);
}
//theta(1)
Element SecondPriorityQueue::top() const
{
	if (this->len < 2)throw exception("len is < 2!");
	if (this->len == 2) return this->elems[2];
	if (this->len == 3) {
		if (this->R(this->elems[2].second, this->elems[3].second)) return this->elems[2];
		else return this->elems[2];
	}
	if (this->R(this->elems[2].second, this->elems[3].second)) {
		if(this->R(this->elems[2].second, this->elems[4].second)) return this->elems[2];
		else return this->elems[4];
	}
	else {
		if (this->R(this->elems[3].second, this->elems[4].second)) return this->elems[3];
		else return this->elems[4];
	}
}
//O(log3(n))
Element SecondPriorityQueue::pop()
{
	if (this->len < 2)throw exception("len is < 2!");
	if (this->len == 2) { return this->elems[this->len--]; }
	Element delElem = this->top();
	int pos = 0;
	for (int i = 1; i <= this->len; i++)
		if (this->elems[i] == delElem)
			pos = i, i = this->len + 5;
	this->elems[pos] = this->elems[this->len--];
	this->bubbleDown(pos);
	return delElem;
}
//theta(1)
bool SecondPriorityQueue::atMostOne() const
{
	if (this->len <= 1) return true;
	return false;
}
//theta(1)
SecondPriorityQueue::~SecondPriorityQueue()
{
	this->len = 0;
	this->cap = 0;
	delete[] this->elems;
}
//theta(n)
void SecondPriorityQueue::resize()
{
	this->cap *= 2;
	Element* aux = new Element[this->cap];
	for (int i = 1; i <= this->len; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}
//O(log3(n)
void SecondPriorityQueue::bubbleUp(int p)
{
	int poz{ p };
	auto elem{ this->elems[poz] };
	int parent{ (p + 1) / 3 };
	while (poz > 1 and this->R(elem.second, this->elems[parent].second)) {
		this->elems[poz] = this->elems[parent];
		poz = parent;
		parent = (poz + 1) / 3;
	}
	this->elems[poz] = elem;
}

//O(log3(n)
void SecondPriorityQueue::bubbleDown(int p)
{
	int poz = p, maxChild = -1;
	Element elem = this->elems[p];
	while (poz < this->len)
	{
		maxChild = -1;
		if (poz * 3 - 1 <= this->len) maxChild = poz * 3 - 1;
		if (poz * 3 <= this->len and this->R(this->elems[poz * 3].second, this->elems[poz * 3 - 1].second))
			maxChild = poz * 3;
		if (poz * 3 + 1<= this->len and this->R(this->elems[poz * 3 + 1].second, this->elems[maxChild].second))
			maxChild = poz * 3 + 1;
		if (maxChild != -1 and this->R(this->elems[maxChild].second, elem.second))
			swap(this->elems[poz], this->elems[maxChild]),
			poz = maxChild;
		else poz = this->len + 1;
	}
}
//theta(n)
void SecondPriorityQueue::print()
{
	for (int i = 1; i <= this->len; i++)
		std::cout << "( " << this->elems[i].first << " , " << this->elems[i].second << " ); ";
	std::cout << "\n\n";
}
