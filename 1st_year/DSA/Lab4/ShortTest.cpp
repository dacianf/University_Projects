#pragma once
#include "ShortTest.h"
#include <assert.h>
#include "Bag_DLLA.h"
#include "BagIterator.h"
#include <exception>


void testAll() { 
	Bag_DLLA b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0); 
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}

	//test elementsWithThisFrequency
	Bag_DLLA bg = Bag_DLLA();
	bg.add(5);
	bg.add(5);
	bg.add(5);
	assert(bg.elementsWithThisFrequency(3) == 1);
	bg.add(3);
	assert(bg.elementsWithThisFrequency(3) == 1);
	bg.add(3);
	bg.add(3);
	assert(bg.elementsWithThisFrequency(3) == 2);
	bg.add(4);
	bg.add(4);
	bg.add(9);
	assert(bg.elementsWithThisFrequency(3) == 2);
	try {
		bg.elementsWithThisFrequency(0);
		assert(false);
	}
	catch (std::exception&) {
		assert(true);
	}

}
