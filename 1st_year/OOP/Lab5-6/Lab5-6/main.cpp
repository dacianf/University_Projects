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
		auto record_matei = SecurityRecord("Matei", "108", Date("2-28-2010"), 5, "Mircea.mp4");
		auto dateOfRecord = record_matei.getTimeOfCreation();
		testDA();
		auto newController = Controller();
		auto record_bla = SecurityRecord("Bla", "DA", Date(), 0, "DAS");
		newController.addRecord(record_bla);
		newController.addRecord("Bla3", "DA", Date(), 0, "DAS");
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
	auto record_bla = SecurityRecord("bla", "iad", Date("2-10-2010"), 4, "da.mp4");
	auto record_blaa = SecurityRecord("blaa", "iad", Date("2-10-2010"), 4, "da.mp4");
	assert((record_bla == record_blaa) == 0);
	record_blaa.setTitle("bla");
	assert((record_bla == record_blaa) == 1);
}