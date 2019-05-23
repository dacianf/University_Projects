#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
using namespace std;
/*
	1.ADT Matrix–represented as a sparse matrix where <line, column, value> 
	triples (value !=0)are memorized, ordered lexicographically considering 
	the line and column of every element. The elements are stored in a 
	hashtable with separate chaining
*/
int main() {
	cout << "Hello!\n\tShort test is starting...\n";
	testAll();
	cout << "Short test are done but it's not done yet\n\tExtending test are comming..\n";
	testAllExtended();
	cout << "Now you are done!\n\tCONGRATS!\n";
	/*auto m = Matrix(10, 10);
	m.modify(0, 0, 1);
	m.modify(0, 1, 1);
	m.print();
	m.modify(1, 0, 1);
	m.print();
	m.modify(1, 1, 1);
	m.print();
	m.modify(0, 2, 1);
	m.print();
	m.modify(2, 0, 1);
	m.modify(2, 1, 1);
	m.modify(2, 2, 1);
	m.print();
	m.modify(0, 3, 1);
	m.modify(3, 0, 1);
	m.print();*/
	return 0;
}