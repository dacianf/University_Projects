#pragma once
#include <iostream>
//#include "ExtendedTest.h"
//#include "ShortTest.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
using namespace std;

int main() {
	cout << "Hello!\n";
	testAll();
	cout << "Short test done!";
	testAllExtended();
	cout << "Finally done!";
	return 0;
}