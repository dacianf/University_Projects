#pragma once
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

SortedSet::SortedSet(Relation r)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->rel = r;
	this->nbOfElements = 0;
}

bool SortedSet::add(TComp e)
{
	if (this->nbOfElements == 0) {
		this->nbOfElements++;
		this->head = new Node<TElem>;
		this->tail = head;
		this->head->nextNode = nullptr;
		this->head->prevNode = nullptr;
		this->head->valoare = e;
		return true;
	}
	if (e == this->head->valoare or e == this->tail->valoare)return false;
	if (rel(e, this->head->valoare)) {
		auto newNode = new Node<TElem>;
		newNode->valoare = e;
		newNode->prevNode = nullptr;
		newNode->nextNode = this->head;
		this->head->prevNode = newNode;
		this->head = newNode;
		this->nbOfElements++;
		return true;
	}
	else if (!rel(e, this->tail->valoare)) {
		auto newNode = new Node<TElem>;
		newNode->valoare = e;
		newNode->prevNode = this->tail;
		newNode->nextNode = nullptr;
		this->tail->nextNode = newNode;
		this->tail = newNode;
		this->nbOfElements++;
		return true;
	}
	else {
		auto crtNode = this->head;
		while (crtNode != nullptr) {
			if (crtNode->valoare == e) return false;
			if (rel(e, crtNode->valoare)) {
				auto newNode = new Node<TElem>;
				newNode->valoare = e;
				newNode->nextNode = crtNode;
				newNode->prevNode = crtNode->prevNode;
				crtNode->prevNode->nextNode = newNode;
				crtNode->prevNode = newNode;
				this->nbOfElements++;
				return true;
			}
			crtNode = crtNode->nextNode;
		}
	}
	return false;
}

bool SortedSet::remove(TComp e)
{
	if (this->isEmpty())return false;
	if (e == this->head->valoare) {
		if(this->head != this->tail)
			this->head->nextNode->prevNode = nullptr;
		auto x = this->head->nextNode;
		delete this->head;
		this->head = x;
		this->nbOfElements--;
		return true;
	}
	if (e == this->tail->valoare) {
		this->tail->prevNode->nextNode = nullptr;
		auto x = this->tail->prevNode;
		delete this->tail;
		this->tail = x;
		this->nbOfElements--;
		return true;
	}
	if (!this->rel(e, this->tail->valoare) or this->rel(e, this->head->valoare)) return false;
	auto nn = this->head;
	while (nn) {
		if (nn->valoare == e) {
			nn->prevNode->nextNode = nn->nextNode;
			nn->nextNode->prevNode = nn->prevNode;
			delete nn;
			this->nbOfElements--;
			return true;
		}
		nn = nn->nextNode;
	}
	return false;
}

bool SortedSet::search(TElem elem) const
{
	if (this->isEmpty())return false;
	if (elem == this->head->valoare or elem == this->tail->valoare)return true;
	if (!this->rel(elem, this->tail->valoare) or this->rel(elem, this->head->valoare)) return false;
	auto nn = this->head;
	while (nn) {
		if (nn->valoare == elem) return true;
		nn = nn->nextNode;
	}
	return false;
}

int SortedSet::size() const
{
	return this->nbOfElements;
}

bool SortedSet::isEmpty() const
{
	return !this->nbOfElements;
}

SortedSetIterator SortedSet::iterator() const
{
	return SortedSetIterator(*this);
}

SortedSet::~SortedSet()
{
	if (this->nbOfElements > 0) {
		Node<TElem>* nodeToDelete = this->head;
		while (nodeToDelete->nextNode != nullptr) {
			nodeToDelete = nodeToDelete->nextNode;
			delete nodeToDelete->prevNode;
		}
		delete nodeToDelete;
	}
	this->nbOfElements = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

void SortedSet::printNodes()
{
	if (this->isEmpty()) std::cout << "Empty list!\n";
	auto crtN = this->head;
	while (crtN)
	{
		std::cout << crtN->valoare << "\n";
		crtN = crtN->nextNode;
	}
}
