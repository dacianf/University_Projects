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
    return 0;
}

void SortedIteratedList::add(TComp e) {
    if (this->root == nullptr) {
        this->root = initNode(e);
        return;
    }
    Node *crt = this->root;
    insertElement(crt, e, this->rel);
}

TComp SortedIteratedList::remove(int pos) {
    return 0;
}

int SortedIteratedList::search(TComp e) const {
    auto parent = this->root;
    auto src = [](auto &&self, Node *crtNode, TComp e, Relation r, int &index) -> int {
        if (crtNode != nullptr and crtNode->info != e) {
            if (crtNode->nbOfNodesInL > 0 and r(e, crtNode->info) == true)
                return self(self, crtNode->left, e, r, index);
            if (!r(e, crtNode->info)) {
                index += crtNode->nbOfNodesInL + 1;
                return (self, crtNode->right, e, r, index) + crtNode->nbOfNodesInL;
            }
        }
        if(crtNode->info == e)return crtNode->nbOfNodesInL;
        return 0;
    };
    int ind = 0, res = 0;
    auto rez = src(src, parent, e, this->rel, ind);
    std::cout<<ind<<"\n";
    //std::cout << ind << "    " << rez << "  --  " << res << "\n";
    return rez;
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
