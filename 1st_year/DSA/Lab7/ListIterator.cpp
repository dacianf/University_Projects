//
// Created by daci on 5/26/19.
//
#include "ListIterator.h"
#include "SortedIndexedList.h"


ListIterator::ListIterator(const SortedIndexedList &sl_) : sl(sl_) {
    this->s = new std::stack<Node *>;
    auto crt = sl_.root;
    while (crt) {
        this->s->push(crt);
        crt = crt->left;
    }
    if (!this->s->empty())
        this->crtNode = this->s->top();
    else
        this->crtNode = nullptr;
}


void ListIterator::first() {
    if(this->s)


        delete this->s;
    this->s = new std::stack<Node *>;
    auto crt = sl.root;
    while (crt){
        this->s->push(crt);
        crt = crt->left;
    }
    if(!this->s->empty())
        this->crtNode = this->s->top();
    else
        this->crtNode = nullptr;
}

bool ListIterator::valid() const {
    if(crtNode)return true;
    return false;
}

TComp ListIterator::getCurrent() const {
    if(!this->valid())throw std::exception();
    return this->crtNode->info;
}

void ListIterator::next() {
    if(!this->valid())throw std::exception();
    auto crt = this->s->top();
    this->s->pop();
    if (crt->right) {
        crt = crt->right;
        while (crt)
            this->s->push(crt),
                    crt = crt->left;
    }
    if (!this->s->empty())
        this->crtNode = this->s->top();
    else
        this->crtNode = nullptr;
}


