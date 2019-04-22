#include <Windows.h>
#include <iostream>
#include <exception>
#include <assert.h>

#include "UI.h"

using namespace std;

int main()
{
	auto menu = UI();
	menu.start();
	return 0;
}
