#include "UI_undoByStates.h"

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

void addElementsToSignalsList(DynamicArray* signals, DynamicArray* undoRedoList)
{
	/*
		Adds staticly 5 elements into a signals list
	*/
	addSignal(1, "zab", "d", 1, signals, undoRedoList);
	addSignal(2, "zbc", "d", 2, signals, undoRedoList);
	addSignal(3, "abc", "d", 3, signals, undoRedoList);
	addSignal(4, "aaa", "d", 2, signals, undoRedoList);
	addSignal(5, "aab", "d", 3, signals, undoRedoList);
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