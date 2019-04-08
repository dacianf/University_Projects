#include <Windows.h>
#include <iostream>
#include <exception>
#include <assert.h>

#include "UI.h"

using namespace std;

void testDA();
int main()
{
	auto menu = UI();
	menu.start();
	try {
		auto x = SecurityRecord("Matei", "108", Date("2-28-2010"), 5, "Mircea.mp4");
		auto d1 = x.getTimeOfCreation();
		testDA();
		auto n = Controller_Admin();
		auto da = SecurityRecord("Bla", "DA", Date(), 0, "DAS");
		n.addRecord(da);
		n.addRecord("Bla3", "DA", Date(), 0, "DAS");
	}
	catch (const char* s) {
		cout <<"ERROR!!! --->\t"<< s<<endl;
	}
	return 0;
}

void testDA() {
	auto da = DynamicArray<int>();
	assert(da.getCapacity() == 10);
	assert(da.getSize() == 0);
	int x = 0;
	for (int i = 0; i <= 11; i++)
		x = i + 3,
		da.addElement(x);
	assert(da.getCapacity() == 20);
	assert(da.getSize() == 12);
	auto rec1 = SecurityRecord("bla", "iad", Date("2-10-2010"), 4, "da.mp4");
	auto rec2 = SecurityRecord("blaa", "iad", Date("2-10-2010"), 4, "da.mp4");
	assert((rec1 == rec2) == 0);
	rec2.setTitle("bla");
	assert((rec1 == rec2) == 1);
}