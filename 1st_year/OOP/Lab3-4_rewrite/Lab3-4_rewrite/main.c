#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "Signal.h"
#include "DynamicArray.h"
#include "Controller.h"

void testSignal();
void testDynamicArr();
void UI(DynamicArray* signalsList);

int main() {
	testSignal();
	testDynamicArr();

	DynamicArray* signalsList = createDynamicArray(sizeof(Signal), createSignal, destroySignal, copySignal, compareTwoSignalsByID);
	void UI(signalsList);
	destroyDynamicArray(signalsList);
	_CrtDumpMemoryLeaks();
	return 0;
}

void UI(DynamicArray* signalsList) {

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
	destroySignal(signal1);
	destroySignal(copyOfSignal1);
}

void testDynamicArr() {
	Signal* signal1 = createSignal(1, "Test", "danger", 1);
	Signal* signal2 = createSignal(2, "Test2", "danger2", 99);
	DynamicArray* signalsArray = createDynamicArray(sizeof(Signal), createSignal, destroySignal, copySignal, compareTwoSignalsByID);
	assert(signalsArray != NULL);
	assert(signalsArray->numberOfElements == 0);
	addElementDynamicArray(signalsArray, signal1);
	assert(signalsArray->numberOfElements == 1);
	addElementDynamicArray(signalsArray, signal2);
	assert(signalsArray->numberOfElements == 2);
	removeElementDynamicArray(signalsArray, signal1);
	assert(signalsArray->numberOfElements == 1);
	assert(signalsArray->elements[1] == NULL);
	assert(((Signal*)signalsArray->elements[0])->id == 2);
	assert(((Signal*)signalsArray->elements[0])->priorityNumber == 99);
	signal1->id = 2;
	updateElementDynamicArray(signalsArray, signal1);
	assert(((Signal*)signalsArray->elements[0])->priorityNumber == 1);
	destroySignal(signal1);
	destroySignal(signal2);
	destroyDynamicArray(signalsArray);
}