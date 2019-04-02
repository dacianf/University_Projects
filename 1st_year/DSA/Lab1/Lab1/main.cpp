#pragma once
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
using namespace std;

int main()
{
	testAll();
	testAllExtended();
	cout << "Done!";
	return 0;
}