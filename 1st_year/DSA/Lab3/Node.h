#pragma once
template <class T>
struct Node
{
	T valoare;
	Node* nextNode;
	Node* prevNode;
	Node() {
		this->nextNode = nullptr;
		this->prevNode = nullptr;
	}
};