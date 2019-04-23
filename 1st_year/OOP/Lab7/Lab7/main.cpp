#include <Windows.h>
#include <iostream>
#include <exception>
#include <assert.h>

#include "UI.h"
#include "TestEverything.h"

using namespace std;

int main()
{
	/*auto testing = TestEverything();
	testing.testAll();*/
	auto menu = UI();
	menu.start();
	return 0;
}
