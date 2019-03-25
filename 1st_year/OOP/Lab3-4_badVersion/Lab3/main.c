#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#include "Signal.h"
void addElementsToSignalsList(SignalsList* signals, DynamicArray *archive)
{
	addSignal(1, "zab", "d", 1, signals, archive);
	addSignal(2, "zbc", "d", 2, signals, archive);
	addSignal(3, "abc", "d", 3, signals, archive);
	addSignal(4, "aaa", "d", 2, signals, archive);
	addSignal(5, "aab", "d", 3, signals, archive);
}
void ui(SignalsList* signals, DynamicArray *archive) {
	signals->numberOfSignals = 0;
	char command[101], *pointerToCommandParameter, listOfParameters[100][100];
	int numberOfCommandParameters = 0;
	char *pointerToNextCharForConvertingStringToInt;
	for (int i = 0; i < 101; i++)command[i] = 0;
	//addElementsToSignalsList(signals, archive);
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
			
			int success = addSignal(atoi(listOfParameters[1]), listOfParameters[2], listOfParameters[3], atoi(listOfParameters[4]), signals, archive);
			if (success == -1) printf("This signal already exist!\n");
		}
		else if (strcmp(listOfParameters[0], "update") == 0 && numberOfCommandParameters == 5) {
			
			int success = updateSignal(atoi(listOfParameters[1]), listOfParameters[2], listOfParameters[3], atoi(listOfParameters[4]), signals, archive);
			if (success == -1) printf("There is no signal with such id!\n");
		}
		else if (strcmp(listOfParameters[0], "delete") == 0 && numberOfCommandParameters == 2) {

			int success = deleteSignal(atoi(listOfParameters[1]), signals, archive);
			if (success == -1) printf("There is no signal with such id!\n");
		}
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 1)
			listSignals(signals);
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 2 && strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) == 0)
			listSignalsByType(listOfParameters[1], signals);
		else if (strcmp(listOfParameters[0], "list") == 0 && numberOfCommandParameters == 2 && strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10) != 0)
			listSignalsWithMaximumPriorityNumber(signals, strtol(listOfParameters[1], &pointerToNextCharForConvertingStringToInt, 10));
		else if (strcmp(listOfParameters[0], "undo") == 0 && numberOfCommandParameters == 1) {
			if (archive->undoRedoIndex - 1 < 0)
				printf("No more undos!\n");
			else {
				/*if (archive->undoRedoIndex == archive->numberOfElements){
					SignalsList* currentState = createSignalsList();
					copySignalList(currentState, signals);
					addItemInDynamicArray(archive, currentState);
				}*/
				archive->undoRedoIndex--;
				SignalsList* currentState = createSignalsList();
				copySignalList(currentState, signals);
				addItemInDynamicArray(archive, currentState);
				signals = archive->data[archive->undoRedoIndex];
			}

		}
		else if (strcmp(listOfParameters[0], "redo") == 0 && numberOfCommandParameters == 1) {
			if (archive->undoRedoIndex >= archive->numberOfElements - 1)
				printf("No more redos!\n");
			else archive->undoRedoIndex++,
				signals = archive->data[archive->undoRedoIndex - 1];
		}
	}
}
int main() {
	SignalsList* signals = createSignalsList();
	
	DynamicArray *archive = createDynamicArray();
	/*SignalsList* currentState = createSignalsList();
	copySignalList(currentState, signals);
	addItemInDynamicArray(archive, currentState);*/

	ui(signals, archive);
	distroyDynamicArray(archive);
	distroySignalsList(signals);
	_CrtDumpMemoryLeaks();
	return 0;
	
}

