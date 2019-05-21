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

TElem Matrix::element(int i, int j) const
{
	std::cout << i << "   ----   " << j << "\n";
	if (i >= this->nLines or j >= this->nCols or i < 0 or j < 0) throw std::exception("Invalid position!");
	int hash = this->TFunction(i, j);
	Node* crt = this->T[hash];
	while (crt != nullptr && !(crt->l == i and crt->c == j))crt = crt->next;
	if (crt == nullptr) return 0;
	return crt->v;
}

TElem Matrix::modify(int i, int j, TElem e)
{
	if (i >= this->nLines or j >= this->nCols or i < 0 or j < 0)throw std::exception("Invalid position!");
	if ((double)((double)lf / (double)this->m) > 0.7)this->resize();
	int hash = this->TFunction(i, j);
	Node* crt = this->T[hash];
	Node* prev = nullptr;
	//std::cout << i << "  --  " << j << "\n";
	while (crt != nullptr && !(crt->l == i and crt->c == j))
		prev = crt, crt = crt->next;
	if (crt != nullptr) {
		std::swap(e, crt->v);
		return e;
	}
	if (prev != this->T[hash]) {
		prev->next = new Node;
		prev->next->l = i;
		prev->next->c = j;
		prev->next->v = e;
		prev->next->next = nullptr;
	}
	else {
		this->T[hash] = new Node;
		prev = this->T[hash];
		prev->l = i;
		prev->c = j;
		prev->v = e;
	}
	this->lf++;
	return 0;
}

int Matrix::TFunction(int l, int c) const
{
	return (l*this->nLines + c) % this->m;
}

void Matrix::resize()
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
			fout << "Hash: " << this->TFunction(crt->l, crt->c) << " and L: " << crt->l << "  C: "<< 
				crt->c << " V: " << crt->v << "\n";
			crt = crt->next;
		}
	}
	fout << "\n\n\n\t\t\tDONE!!!\n\n\n";
}
