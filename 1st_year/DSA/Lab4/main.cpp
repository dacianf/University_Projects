#pragma once
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "Bag_DLLA.h"

using namespace std;

int main() {
	cout << "Tests are starting...\n";
	testAll();
	cout << "First round is done :)\n\tNow it's time for the real tests :))\n";
	testAllExtended();
	cout<<"Now everything is done and it's working! Well done! :D\n Have a great day!\n\n";
	return 0;
}