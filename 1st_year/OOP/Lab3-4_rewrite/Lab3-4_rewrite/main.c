#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "undoRedoByHistoryLists/UI_undoByStates.h"

void testSignal();
void testDynamicArr();


int main() {
	testSignal();
	testDynamicArr();

	DynamicArray* signalsList = createDynamicArray(sizeof(Signal*), createSignal, destroySignal, copySignal, compareTwoSignalsByID);
	DynamicArray* undoRedoList = createDynamicArray(sizeof(DynamicArray*), createDynamicArray, destroyDynamicArray, createCopyOfDynamicArray, compareTwoDynamicArrays);
	//DynamicArray* undoByCommandList = createDynamicArray(sizeof(UndoRedoByCommand*), createUndoRedoByCommand, destroyUndoRedoByCommand, copyUndoRedoByCommand, NULL);
	//DynamicArray* redoByCommandList = createDynamicArray(sizeof(UndoRedoByCommand*), createUndoRedoByCommand, destroyUndoRedoByCommand, copyUndoRedoByCommand, NULL);
	
	addElementDynamicArray(undoRedoList, signalsList);
	addElementsToSignalsList(signalsList, undoRedoList);
	signalsList = UI(signalsList, undoRedoList);


	//destroyDynamicArray(undoByCommandList);
	//destroyDynamicArray(redoByCommandList);
	destroyDynamicArray(signalsList);
	destroyDynamicArray(undoRedoList);
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
	assert(strcmp(signal1, copyOfSignal1) == 0);
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
	signal2->id = 21;
	addElementDynamicArray(signalsArray, signal2);
	DynamicArray *copie = createCopyOfDynamicArray(signalsArray);
	assert(signalsArray->capacity == copie->capacity);
	assert(signalsArray->undoRedoIndex == copie->undoRedoIndex);
	assert(signalsArray->numberOfElements == copie->numberOfElements);
	assert(signalsArray->elements != copie->elements);
	for (int i = 0; i < signalsArray->numberOfElements; i++) {
		assert(signalsArray->elements[i] != copie->elements[i]);
		assert(signalsArray->compareElements(signalsArray->elements[i], copie->elements[i]) == 0);
	}

	DynamicArray* backup = createDynamicArray(sizeof(DynamicArray*), createDynamicArray, destroyDynamicArray, createCopyOfDynamicArray, compareTwoDynamicArrays);
	addElementDynamicArray(backup, signalsArray);
	assert(backup->numberOfElements == 1);
	addElementDynamicArray(backup, copie);
	assert(backup->numberOfElements == 2);
	addElementDynamicArray(backup, copie);
	addElementDynamicArray(backup, copie);
	addElementDynamicArray(backup, signalsArray);
	addElementDynamicArray(backup, copie);
	assert(backup->numberOfElements == 6);
	destroyDynamicArray(backup);
	destroySignal(signal1);
	destroySignal(signal2);
	destroyDynamicArray(copie);
	destroyDynamicArray(signalsArray);
}
