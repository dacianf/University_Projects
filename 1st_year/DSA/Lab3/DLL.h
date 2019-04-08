#pragma once
#include "Node.h"
#include "SortedSetIterator.h"
template <class T>
class DLL
{
	friend class SortedSetIterator;
private:
	int size;
	Node<T>* headNode;
	Node<T>* currentNode;
public:
	DLL() { this->size = 0; this->headNode = new Node<T>; this->currentNode = this->headNode; }
	void insert(Node<T>* n, T element);
	void remove(Node<T>* n);
	T getValue(Node<T>* n) const { return n->valoare; }
	int getSize() const { return this->size; }
	Node<T>& getFirst() { return this->headNode; };
	~DLL() {
		this->currentNode = this->headNode->nextNode;
		while (this->currentNode->nextNode != nullptr)
			delete this->currentNode->prevNode,
			this->currentNode = this->currentNode->nextNode;
	}
};

template<class T>
inline void DLL<T>::insert(Node<T>* n, T element)
{//inserts a node before given node
	if (!n) {
		this->currentNode->valoare = element;
		this->currentNode->nextNode = new Node<T>;
		this->currentNode->nextNode->prevNode = this->currentNode;
		this->currentNode = this->currentNode->nextNode;
	}
	else {
		Node<T>* aux = n->prevNode;
		n->prevNode = new Node<T>;
		n->prevNode->valoare = element;
		n->prevNode->nextNode = n;
		aux->nextNode = n->prevNode;
		n->prevNode->prevNode = aux;
	}
	this->size++;
}

template<class T>
inline void DLL<T>::remove(Node<T>* n)
{
	Node<T>* aux = n;
	n->prevNode->nextNode = n->nextNode;
	n->nextNode->prevNode = n->prevNode;
	delete aux;
}
