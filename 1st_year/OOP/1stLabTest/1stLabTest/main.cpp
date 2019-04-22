#pragma once
#include <iostream>
#include "Controller.h"
#include <assert.h>
#include "UI.h"
using namespace std;

void test();
UI ui;
int main() {
	test();
	ui.start();
	return 0;
}

void test() {
	auto ct = Controller();
	assert(ct.getSize() == 0);
	assert(ct.totalQuantity() == 0);
	assert(ct.addProject("da", "bla", "01-01-10", 1, false) == true);
	assert(ct.getSize() == 1);
	assert(ct.totalQuantity() == 0);
	assert(ct.addProject("da1", "bla", "01-01-10", 7, true));
	assert(ct.getSize() == 2);
	assert(ct.totalQuantity() == 7);
	assert(ct.addProject("da2", "bla", "01-01-10", 9, true));
	assert(ct.getSize() == 3);
	assert(ct.totalQuantity() == 16);
	cout << "tests passed!\n";
}