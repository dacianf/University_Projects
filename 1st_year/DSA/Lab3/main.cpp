#pragma once
#include <iostream>
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;

int main() {
	cout << "Hello!\n";
	testAll();
	cout << "Short test done!";
	testAllExtended();
	cout << "Finally done!";
}