//
// Created by daci on 5/26/19.
//
#pragma once

#include "SortedIteratedList.h"

static Node *initNode(TComp e) {
    auto newNode = new Node;
    newNode->info = e;
    newNode->right = nullptr;
    newNode->left = nullptr;
    newNode->nbOfNodesInL = 0;
    return newNode;
}

static void deleteBST(Node *root) {
    if (root) {
        deleteBST(root->left);
        deleteBST(root->right);
        delete root;
        root = nullptr;
    }
}

static Node *insertElement(Node *node, TComp e, Relation r) {
    if (node == nullptr)
        node = initNode(e);
    else if (r(e, node->info))
        node->nbOfNodesInL++,
                node->left = insertElement(node->left, e, r);
    else
        node->right = insertElement(node->right, e, r);
    return node;
}

SortedIteratedList::SortedIteratedList(Relation r) {
    this->rel = r;
    this->root = nullptr;
    this->nbOfElems = 0;
}

SortedIteratedList::~SortedIteratedList() {
    this->nbOfElems = 0;

    deleteBST(this->root);
    this->root = nullptr;
}

int SortedIteratedList::size() const {
    return this->nbOfElems;
}

bool SortedIteratedList::isEmpty() const {
    return !(this->nbOfElems);
}

TComp SortedIteratedList::getElement(int pos) const {
    if (pos < 0 or pos >= this->nbOfElems)
        throw std::exception();
    auto crt = this->root;
    int contor = 0;
    while(contor + crt->nbOfNodesInL != pos){
        if(contor + crt->nbOfNodesInL > pos)
            crt = crt->left;
        else{
            contor += crt->nbOfNodesInL + 1;
            crt = crt->right;
        }
    }
    return crt->info;
}

void SortedIteratedList::add(TComp e) {
    if (this->root == nullptr) {
        this->root = initNode(e);
        this->nbOfElems++;
        return;
    }
    Node *crt = this->root;
    insertElement(crt, e, this->rel);
    this->nbOfElems++;
}

TComp SortedIteratedList::remove(int pos) {
    return 0;
}

int SortedIteratedList::search(TComp e) const {
    int contor=0;
    auto crt = this->root;
    while (crt!= nullptr and crt->info!=e){
        if(this->rel(e, crt->info))crt=crt->left;
        else { contor+=crt->nbOfNodesInL+1; crt=crt->right;}
    }
    if(crt)contor+=crt->nbOfNodesInL;
    return (crt)?contor:-1;
}

ListIterator SortedIteratedList::iterator() {
    return ListIterator(*this);
}

void SortedIteratedList::print() {
    auto crt = this->root;
    auto f = [crt](auto &&self, Node *parent) -> void {
        if (parent) {
            self(self, parent->left);
            std::cout << "\n";
            self(self, parent->right);
            std::cout << "( " << parent->info << "; " << parent->nbOfNodesInL << ") ";
        }
    };
    f(f, crt);
    std::cout << "\n\n";
}
