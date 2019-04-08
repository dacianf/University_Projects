#pragma once
#include <exception>
typedef int TElem;

class Queue
{
private:
	/*representation of Queue*/
	int front;
	int size;
	int capacity;
	TElem* elements;
public:
	Queue();
	//pushes an element to the end of the queue

	void push(TElem e);

	//returns the element from the front of the queue

	//throws exception if the queue is empty

	TElem top() const;

	//removes and returns the element from the front of the queue

	//throws exception if the queue is empty

	TElem pop();

	//checks if the queue is empty

	bool isEmpty() const;
	// destructor

	bool search(TElem elem) const;

	~Queue();
private:
	void resize(double val = 1.3);
};
