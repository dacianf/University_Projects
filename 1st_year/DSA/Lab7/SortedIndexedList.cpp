//
// Created by daci on 5/26/19.
//
#include "SortedIndexedList.h"

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

SortedIndexedList::SortedIndexedList(Relation r) {
    this->rel = r;
    this->root = nullptr;
    this->nbOfElems = 0;
}

SortedIndexedList::~SortedIndexedList() {
    this->nbOfElems = 0;

    deleteBST(this->root);
    this->root = nullptr;
}

int SortedIndexedList::size() const {
    return this->nbOfElems;
}

bool SortedIndexedList::isEmpty() const {
    return !(this->nbOfElems);
}

TComp SortedIndexedList::getElement(int pos) const {
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

void SortedIndexedList::add(TComp e) {
    if (this->root == nullptr) {
        this->root = initNode(e);
        this->nbOfElems++;
        return;
    }
    Node *crt = this->root;
    insertElement(crt, e, this->rel);
    this->nbOfElems++;
}

TComp SortedIndexedList::remove(int pos) {
    auto elemToReturn = this->getElement(pos);
    bool removed = false;
    this->root = removeRec(this->root, elemToReturn, removed);
    if (removed)
        this->nbOfElems--;
    return elemToReturn;

}

int SortedIndexedList::search(TComp e) const {
    int contor=0;
    auto crt = this->root;
    Node *result = nullptr;
    while (crt != nullptr) {
        if (crt->info == e)result = crt;
        if(this->rel(e, crt->info))crt=crt->left;
        else { contor+=crt->nbOfNodesInL+1; crt=crt->right;}
    }

    return (result) ? contor : -1;
}

ListIterator SortedIndexedList::iterator() {
    return ListIterator(*this);
}

void SortedIndexedList::print() {
    auto crt = this->root;
    auto f = [crt](auto &&self, Node *parent) -> void {
        if (parent) {
            self(self, parent->left);
            self(self, parent->right);
            std::cout << "( " << parent->info << "; " << parent->nbOfNodesInL << ") ";
        }
    };
    f(f, crt);
    std::cout << "\n\n";
}

Node *SortedIndexedList::removeRec(Node *treeRoot, TComp e, bool &removed) {
    if (treeRoot == nullptr) {
        return treeRoot;
    }

    if (e == treeRoot->info) {
        removed = true;

        if (treeRoot->left == nullptr) {
            auto nodeR = treeRoot->right;
            delete treeRoot;
            return nodeR;
        } else if (treeRoot->right == nullptr) {
            auto nodeL = treeRoot->left;
            delete treeRoot;
            return nodeL;
        } else {
            auto replaceNode = treeRoot->left;
            while (replaceNode and replaceNode->right)
                replaceNode = replaceNode->right;
            treeRoot->info = replaceNode->info;
            treeRoot->nbOfNodesInL--;
            treeRoot->left = removeRec(treeRoot->left, replaceNode->info, removed);
        }
    } else if (this->rel(e, treeRoot->info)) {
        treeRoot->nbOfNodesInL--;
        treeRoot->left = removeRec(treeRoot->left, e, removed);
    } else {
        treeRoot->right = removeRec(treeRoot->right, e, removed);
    }
    return treeRoot;
}
