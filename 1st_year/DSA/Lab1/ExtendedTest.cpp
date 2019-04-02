#include <assert.h>
#include "Queue.h"
#include "ExtendedTest.h"
#include <vector>
#include <exception>

using namespace std;

void testCreate() {
	Queue q;
	assert(q.isEmpty() == true);
	try {
		q.top(); 
		assert(false); 
	}
	catch (exception&) {
		assert(true);
	}
	try {
		q.pop(); 
		assert(false); 
	}
	catch (exception&) {
		assert(true);
	}
}

void testPush() {
	Queue q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);
	for (int i = -10; i < 20; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);
	for (int i = -100; i < 100; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);

	for (int i = 10000; i > -10000; i--) {
		q.push(i);
	}
	assert(q.isEmpty() == false);
	assert(q.top() != -9999);
	assert(q.top() == 0);

	assert(q.pop() == 0);
	assert(q.top() == 1);
}

void testPop() {
	Queue q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);
	for (int i = -10; i < 20; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);
	for (int i = -100; i < 100; i++) {
		q.push(i);
	}
	assert(q.isEmpty() == false);

	for (int i = 10000; i > -10000; i--) {
		q.push(i);
	}
	assert(q.isEmpty() == false);

	
	for (int i = 0; i < 10; i++) {
		assert(q.pop() == i);
	}
	assert(q.isEmpty() == false);
	for (int i = -10; i < 20; i++) {
		assert(q.pop() == i);
	}
	assert(q.isEmpty() == false);
	for (int i = -100; i < 100; i++) {
		assert(q.pop() == i);
	}
	assert(q.isEmpty() == false);

	for (int i = 10000; i > -10000; i--) {
		assert(q.pop() == i);
	}
	assert(q.isEmpty() == true);
}

void testQuantity() {
	Queue q;
	for (int i = 1; i <= 10; i++) {
		for (int j = 30000; j >= -3000; j--) {
			q.push(i + j);
		}
	}

	for (int i = 1; i <= 10; i++) {
		for (int j = 30000; j >= -3000; j--) {
			assert(q.pop() == i + j);
		}
	}
}

void testAllExtended() {
	testCreate();
	testPush();
	testPop();
	testQuantity();
}