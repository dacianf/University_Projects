#include <assert.h>
#include "Matrix.h"
#include <iostream>

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modify(1, 1, 6);
	assert(m.element(1, 2) == 0);
	std::cout << "Matrix resize test!!\n";
	Matrix mr(10, 10);
	for (int i = 0; i < mr.nrLines(); i++)
		for (int j = 0; j < mr.nrColumns(); j++)
			mr.modify(i, j, i + i+5);
	for (int i = 0; i < mr.nrLines(); i++)
		for (int j = 0; j < mr.nrColumns(); j++)
			assert(mr.element(i, j) == i + i + 5);
	std::cout << "\n\n\n";
	//mr.print();
	mr.resizeMatrix(15, 15);
	for (int i = 0; i < mr.nrLines(); i++)
		for (int j = 0; j < mr.nrColumns(); j++)
			if(i<10 and j<10)
				assert(mr.element(i, j) == i + i + 5);
	std::cout << "\n\n\n";
	//mr.print();
	mr.resizeMatrix(7, 7);
	for (int i = 0; i < mr.nrLines(); i++)
		for (int j = 0; j < mr.nrColumns(); j++)
			assert(mr.element(i, j) == i + i + 5);
	//mr.print();
}