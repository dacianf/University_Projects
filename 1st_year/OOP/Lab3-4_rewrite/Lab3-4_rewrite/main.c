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
void addElementsToSignalsList(DynamicArray* signals);

int main() {
	testSignal();
	testDynamicArr();

	DynamicArray* signalsList = createDynamicArray(sizeof(Signal*), createSignal, destroySignal, copySignal, compareTwoSignalsByID);
	addElementsToSignalsList(signalsList);
	UI(signalsList);
	destroyDynamicArray(signalsList);
	_CrtDumpMemoryLeaks();
	return 0;
}

void UI(DynamicArray* signalsList) {
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
		if (strcmp(command, "exit") == 0 || strcmp(command, "0") == 0)break;
		pointerToCommandParameter = strtok(command, " ");
		while (pointerToCommandParameter) {
			strcpy(listOfParameters[numberOfCommandParameters], pointerToCommandParameter);
			numberOfCommandParameters++;
			pointerToCommandParameter = strtok(NULL, " ");
		}
		if (strcmp(listOfParameters[0], "add") == 0 && numberOfCommandParameters == 5) {

			int success = addSignal(atoi(listOfParameters[1]), listOfParameters[2], listOfParameters[3], atoi(listOfParameters[4]), signalsList);
			if (success == -1) printf("This signal already exist!\n");
		}
		else if (strcmp(listOfParameters[0], "update") == 0 && numberOfCommandParameters == 5) {

			int success = updateSignal(atoi(listOfParameters[1]), listOfParameters[2], listOfParameters[3], atoi(listOfParameters[4]), signalsList);
			if (success == -1) printf("There is no signal with such id!\n");
		}
		else if (strcmp(listOfParameters[0], "delete") == 0 && numberOfCommandParameters == 2) {

			int success = deleteSignal(atoi(listOfParameters[1]), signalsList);
			if (success == -1) printf("There is no signal with such id!\n");
		}
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 1)
			listSignals(signalsList);
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 2 && strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) == 0)
			listSignalsByType(listOfParameters[1], signalsList);
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 2 && strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) != 0)
			listSignalsWithMaximumPriorityNumber(strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10), signalsList, 0);
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 3
			&& strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) != 0
			&& strcmp(listOfParameters[2], "reverse") == 0)
			listSignalsWithMaximumPriorityNumber(strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10), signalsList, 1);
		//else if (strcmp(listOfParameters[0], "undo") == 0 && numberOfCommandParameters == 1) {
		//	if (signalsList->undoRedoIndex - 1 < 0)
		//		printf("No more undos!\n");
		//	else {
		//		/*if (archive->undoRedoIndex == archive->numberOfElements){
		//			SignalsList* currentState = createSignalsList();
		//			copySignalList(currentState, signals);
		//			addItemInDynamicArray(archive, currentState);
		//		}*/
		//		archive->undoRedoIndex--;
		//		SignalsList* currentState = createSignalsList();
		//		copySignalList(currentState, signals);
		//		addItemInDynamicArray(archive, currentState);
		//		signals = archive->data[archive->undoRedoIndex];
		//	}

		//}
		//else if (strcmp(listOfParameters[0], "redo") == 0 && numberOfCommandParameters == 1) {
		//	if (archive->undoRedoIndex >= archive->numberOfElements - 1)
		//		printf("No more redos!\n");
		//	else archive->undoRedoIndex++,
		//		signals = archive->data[archive->undoRedoIndex - 1];
		//}
	}
}

void addElementsToSignalsList(DynamicArray* signals)
{
	addSignal(1, "zab", "d", 1, signals);
	addSignal(2, "zbc", "d", 2, signals);
	addSignal(3, "abc", "d", 3, signals);
	addSignal(4, "aaa", "d", 2, signals);
	addSignal(5, "aab", "d", 3, signals);
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
	destroySignal(signal1);
	destroySignal(signal2);
	destroyDynamicArray(signalsArray);
}