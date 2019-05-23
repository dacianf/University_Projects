#include "Matrix.h"
#include <exception>
#include <algorithm>
#include <iostream>
#include <fstream>
Matrix::Matrix(int nrLines, int nrColumns)
{
	this->nLines = nrLines;
	this->nCols = nrColumns;
	this->m = 1;
	this->lf = 0;
	this->T = new Node*[1]{};
}

Matrix::~Matrix()
{
	this->nCols = 0;
	this->nLines = 0;
	Node* crt = nullptr;
	Node* prev = nullptr;
	for (int i = 0; i < m; i++) {
		crt = this->T[i];
		while (crt)
		{
			prev = crt;
			crt = crt->next;
			delete prev;
		}
	}
	delete[] this->T;
	this->m = 0;
	this->lf = 0;

}
//O(1) //not sure //O(len(T[hash]))
TElem Matrix::element(int i, int j) const
{
	//std::cout << i << "   ----   " << j << "\n";
	if (i >= this->nLines or j >= this->nCols or i < 0 or j < 0) throw std::exception("Invalid position!");
	int hash = this->TFunction(i, j);
	Node* crt = this->T[hash];
	while (crt != nullptr && !(crt->l == i and crt->c == j))crt = crt->next;
	if (crt == nullptr) return 0;
	return crt->v;
}
//O(m+lf);
TElem Matrix::modify(int i, int j, TElem e)
{
	if (i >= this->nLines or j >= this->nCols or i < 0 or j < 0)throw std::exception("Invalid position!");
	if ((double)((double)lf / (double)this->m) > 0.7)this->resizeHash();
	int hash = this->TFunction(i, j);
	Node* crt = this->T[hash];
	Node* prev = nullptr;
	//std::cout << i << "  --  " << j << "\n";
	while (crt != nullptr && !(crt->l == i and crt->c == j))
		prev = crt, crt = crt->next;
	if (crt != nullptr) {
		std::swap(e, crt->v);
		if (crt->v == 0) {
			if (prev != nullptr)
				prev->next = crt->next;
			this->T[hash] = nullptr;
			delete crt;
		}
		return e;
		
	}
	if (e == NULL_TELEM)return 0;
	if (prev == nullptr) {
		this->T[hash] = new Node;
		prev = this->T[hash];
	}
	else {
		prev->next = new Node;
		prev = prev->next;
	}

	prev->l = i;
	prev->c = j;
	prev->v = e;
	prev->next = nullptr;
	this->lf++;
	return 0;
}
//theta(1)
int Matrix::TFunction(int l, int c) const
{
	return (l*this->nLines + c) % this->m;
}
//Theta(lf) -- nb of elements
void Matrix::resizeHash()
{
	//this->print();
	/*if(this->m >3)
		std::cout << this->T[3]->v << " hhh\n\n";*/
	Node** aux = this->T;
	int oldM = this->m;
	this->m *= 2;
	this->T = new Node*[2 * this->m]{};
	this->lf = 0;
	Node* crt;
	Node* prev;
	for (int i = 0; i < oldM; i++) {
		crt = aux[i];
		while (crt != nullptr)
		{
			this->modify(crt->l, crt->c, crt->v);
			prev = crt;
			crt = crt->next;
			delete prev;
		}
	}
	delete[] aux;
	//this->print();
}

void Matrix::print()
{
	std::ofstream fout("bau.txt", std::ofstream::app);
	Node* crt = nullptr;
	for (int i = 0; i < this->m; i++) {
		crt = this->T[i];
		while (crt != nullptr)
		{
			std::cout << "Hash: " << this->TFunction(crt->l, crt->c) << " and L: " << crt->l << "  C: "<< 
				crt->c << " V: " << crt->v << "\n";
			crt = crt->next;
		}
	}
	std::cout << "\n\n\n\t\t\tDONE!!!\n\n\n";
}
//O(nbOfElements)
void Matrix::resizeMatrix(int nrLin, int nrCol)
{
	if (nrLin <= 0 or nrCol <= 0)throw std::exception("Invalid size!");
	Node** aux = this->T;
	this->T = new Node*[this->m]{};
	this->nLines = nrLin;
	this->nCols = nrCol;
	Node* crt;
	Node* prev;
	for (int i = 0; i < this->m; i++) {
		crt = aux[i];
		while (crt!=nullptr)
		{
			prev = crt;
			crt = crt->next;
			if (prev->c < nrCol && prev->l < nrLin)
				this->modify(prev->l, prev->c, prev->v);
			delete prev;
		}
	}
	delete[] aux;
}
