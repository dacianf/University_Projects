#pragma once
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
using namespace std;

int main()
{
	testAll();
	cout << "shortTests done!\n";
	testAllExtended();
	cout << "Done!";
	return 0;
}