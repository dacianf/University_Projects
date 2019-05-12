#include <Windows.h>
#include <iostream>
#include <exception>
#include <assert.h>

#include "ui/UI.h"
#include "tests/TestEverything.h"

using namespace std;

int main()
{
	auto testing = TestEverything();
	testing.testAll();
	auto menu = UI();
	menu.start();
	return 0;
}
