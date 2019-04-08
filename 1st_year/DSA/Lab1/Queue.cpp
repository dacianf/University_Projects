#include "Queue.h"



Queue::Queue()
{//theta(1)
	this->front = 0;
	this->size = 0;
	this->capacity = 50;
	this->elements = new TElem[this->capacity];
}

void Queue::push(TElem e)
{//O(nbOfElements)
	if (this->size == this->capacity and this->front==0)
		this->resize();
	if (this->front == this->size + 1)
		this->resize();
	if (this->size == this->capacity and this->front > 0)
		this->size = 0;
	this->elements[this->size++] = e;
}

TElem Queue::top() const
{//theta(1)
	if (this->size == this->front)
		throw std::exception("Queue is empty!");
	return this->elements[this->front];
}

TElem Queue::pop()
{//theta(1)
	if (this->size == this->front)
		throw std::exception("Queue is empty!");
	auto val = this->elements[this->front++];
	return val;
}


bool Queue::isEmpty() const
{//theta(1)
	return (this->size == this->front);
}

bool Queue::search(TElem elem) const
{
	//checks if a given element appears in the Queue
	for (int i = this->front; i < this->size; i++)
		if (this->elements[i] == elem)
			return true;
	if (this->size < this->front)
		for (int i = 0; i < this->size; i++)
			if (this->elements[i] == elem)
				return true;
	return false;
}

Queue::~Queue()
{//theta(1)
	this->front = 0;
	this->size = 0;
	this->capacity = 0;
	delete[] this->elements;
}

void Queue::resize(double val)
{//theta(nbOfElements)
	int tail = this->capacity;
	this->capacity += 100;
	TElem* aux = new TElem[this->capacity];
	int auxIndex = 0;

	for (int i = this->front; i < tail; i++)
		aux[auxIndex++] = this->elements[i];
	if (this->size < this->front)
		for (int i = 0; i < this->size; i++)
			aux[auxIndex++] = this->elements[i];
	delete[] this->elements;
	this->elements = aux;
	this->front = 0;
	this->size = tail;
}
