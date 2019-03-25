#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "Signal.h"
#include "DynamicArray.h"

void testSignal();
void testDynamicArr();


int main() {
	testSignal();
	testDynamicArr();
	_CrtDumpMemoryLeaks();
	return 0;
}

void testSignal() {
	Signal* signal1 = createSignal(1, "Test", "danger", 1);
	assert(signal1 != NULL);
	assert(signal1->id == 1);
	assert(strcmp(signal1->type, "danger") == 0);
	Signal* copyOfSignal1 = copySignal(signal1);
	assert(copyOfSignal1 != NULL);
	assert(compareTwoSignalsLexicographicByModulatedSignal(signal1, copyOfSignal1) == 0);
	assert(signal1 != copyOfSignal1);
	distroySignal(signal1);
	distroySignal(copyOfSignal1);
}

void testDynamicArr() {
	Signal* signal1 = createSignal(1, "Test", "danger", 1);
	Signal* signal2 = createSignal(2, "Test2", "danger2", 99);
	DynamicArray* signalsArray = createDynamicArray(sizeof(Signal), createSignal, distroySignal, copySignal, compareTwoSignalsByID);
	assert(signalsArray != NULL);
	assert(signalsArray->numberOfElements == 0);
	addElementDynamicArray(signalsArray, signal1);
	assert(signalsArray->numberOfElements == 1);
	addElementDynamicArray(signalsArray, signal2);
	assert(signalsArray->numberOfElements == 2);
	removeElementDynamicArray(signalsArray, signal1);
	assert(signalsArray->numberOfElements == 1);
	distroySignal(signal1);
	distroySignal(signal2);
	distoryDynamicArray(signalsArray);
}