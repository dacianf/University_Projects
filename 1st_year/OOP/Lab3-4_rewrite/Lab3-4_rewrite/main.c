#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "Signal.h"
#include "DynamicArray.h"
#include "Controller.h"
#include "UndoRedoByCommand.h"

void testSignal();
void testDynamicArr();
void addElementsToSignalsList(DynamicArray* signals, DynamicArray* undoRedoList);
void printSignalsFromArray(DynamicArray *signalsList);
void* UI(DynamicArray* signalsList, DynamicArray* undoRedoList);


int main() {
	testSignal();
	testDynamicArr();

	DynamicArray* signalsList = createDynamicArray(sizeof(Signal*), createSignal, destroySignal, copySignal, compareTwoSignalsByID);
	DynamicArray* undoRedoList = createDynamicArray(sizeof(DynamicArray*), createDynamicArray, destroyDynamicArray, createCopyOfDynamicArray, compareTwoDynamicArrays);
	DynamicArray* undiRedoByCommandList = createDynamicArray(sizeof(UndoRedoByCommand*), createUndoRedoByCommand, destroyUndoRedoByCommand, copyUndoRedoByCommand, NULL);
	addElementDynamicArray(undoRedoList, signalsList);
	addElementsToSignalsList(signalsList, undoRedoList);
	signalsList = UI(signalsList, undoRedoList);
	destroyDynamicArray(undiRedoByCommandList);
	destroyDynamicArray(signalsList);
	destroyDynamicArray(undoRedoList);
	_CrtDumpMemoryLeaks();
	return 0;
}

void* UI(DynamicArray* signalsList, DynamicArray* undoRedoList) {
	char command[101], *pointerToCommandParameter, listOfParameters[100][100];
	int numberOfCommandParameters = 0;
	char *pointerToNextCharForConvertingStringToInt;
	for (int i = 0; i < 101; i++)command[i] = 0;
	printf("Type down the command you want:\n");
	while (1)
	{
		numberOfCommandParameters = 0;
		printf("> ");
		scanf(" %[^'\n']s", command);
		if (strcmp(command, "exit") == 0 || strcmp(command, "0") == 0)return signalsList;
		pointerToCommandParameter = strtok(command, " ");
		while (pointerToCommandParameter) {
			strcpy(listOfParameters[numberOfCommandParameters], pointerToCommandParameter);
			numberOfCommandParameters++;
			pointerToCommandParameter = strtok(NULL, " ");
		}
		if (strcmp(listOfParameters[0], "add") == 0 && numberOfCommandParameters == 5) {

			int success = addSignal(atoi(listOfParameters[1]), listOfParameters[2], listOfParameters[3], atoi(listOfParameters[4]), signalsList, undoRedoList);
			if (success == -1) printf("This signal already exist!\n");
		}
		else if (strcmp(listOfParameters[0], "update") == 0 && numberOfCommandParameters == 5) {

			int success = updateSignal(atoi(listOfParameters[1]), listOfParameters[2], listOfParameters[3], atoi(listOfParameters[4]), signalsList, undoRedoList);
			if (success == -1) printf("There is no signal with such id!\n");
		}
		else if (strcmp(listOfParameters[0], "delete") == 0 && numberOfCommandParameters == 2) {

			int success = deleteSignal(atoi(listOfParameters[1]), signalsList, undoRedoList);
			if (success == -1) printf("There is no signal with such id!\n");
		}
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 1)
		{
			DynamicArray *signalsToPrint = listSignals(signalsList);
			printSignalsFromArray(signalsToPrint);
			destroyDynamicArray(signalsToPrint);
		}
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 2 && strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) == 0) {
			DynamicArray *signalsToPrint = listSignalsByType(listOfParameters[1], signalsList);
			printSignalsFromArray(signalsToPrint);
			destroyDynamicArray(signalsToPrint);
		}
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 2 && strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) != 0)
		{
			DynamicArray *signalsToPrint = listSignalsWithMaximumPriorityNumber(strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10), signalsList, 0);
			printSignalsFromArray(signalsToPrint);
			destroyDynamicArray(signalsToPrint);
		}
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 3
			&& strcmp(listOfParameters[1], "priority") == 0
			&& strtol(listOfParameters[2], &pointerToNextCharForConvertingStringToInt, 10) != 0)
		{
			DynamicArray *signalsToPrint = listSignalsByPriority(strtol(listOfParameters[2], &pointerToNextCharForConvertingStringToInt, 10), signalsList);
			printSignalsFromArray(signalsToPrint);
			destroyDynamicArray(signalsToPrint);
		}
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 3
			&& strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) != 0
			&& strcmp(listOfParameters[2], "reverse") == 0)
		{
			DynamicArray *signalsToPrint = listSignalsWithMaximumPriorityNumber(strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10), signalsList, 1);
			printSignalsFromArray(signalsToPrint);
			destroyDynamicArray(signalsToPrint);
		}
		else if (strcmp(listOfParameters[0], "undo") == 0 && numberOfCommandParameters == 1)
			signalsList = undo(undoRedoList, signalsList);
		else if (strcmp(listOfParameters[0], "redo") == 0 && numberOfCommandParameters == 1)
			signalsList = redo(undoRedoList, signalsList);
	}
}

void printSignalsFromArray(DynamicArray *signalsList) {
	if (signalsList->numberOfElements == 0)
		printf("%s\n", "There are no signals in the list!");
	else {
		printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
		for (int i = 0; i < signalsList->numberOfElements; i++)
			printSignal(signalsList->elements[i]);
	}
}

void addElementsToSignalsList(DynamicArray* signals, DynamicArray* undoRedoList)
{
	addSignal(1, "zab", "d", 1, signals, undoRedoList);
	addSignal(2, "zbc", "d", 2, signals, undoRedoList);
	addSignal(3, "abc", "d", 3, signals, undoRedoList);
	addSignal(4, "aaa", "d", 2, signals, undoRedoList);
	addSignal(5, "aab", "d", 3, signals, undoRedoList);
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