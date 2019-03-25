#include "Controller.h"
#include <stdio.h>

int addSignal(int id, char * modulatedSignal, char * type, int priorityNumber, DynamicArray *signalsList){
	/*Add a given signal into signals list
	Input: id - positive integer
		   modulatedSignal - string of chars
		   type - string of chars (damage-inner, damage-outer, sensor-reading)
		   priorityNumber - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			0 - otherwise
	*/
	Signal* newSignal = createSignal(id, modulatedSignal, type, priorityNumber);
	if (findElementFromDynamicArray(signalsList, newSignal) != NULL)
		return 0;
	addElementDynamicArray(signalsList, newSignal);
	destroySignal(newSignal);
	return 1;
}

int updateSignal(int id, char * newModulatedSignal, char * newType, int newPriorityNumber, DynamicArray * signalsList){
	/*Updates a signal info from signals list and finding it by id
	Input: id - positive integer
		   newModulatedSignal - string of chars
		   newType - string of chars (damage-inner, damage-outer, sensor-reading)
		   newPriorityNumber - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			0 - otherwise
	*/
	Signal* newSignal = createSignal(id, newModulatedSignal, newType, newPriorityNumber);
	int successfulOperation = updateElementDynamicArray(signalsList, newSignal);
	destroySignal(newSignal);
	return successfulOperation;
}

int deleteSignal(int id, DynamicArray * signalsList){
	/*Delets a signal from signals list
	Input: id - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			-1 - otherwise
	*/
	Signal* signal = createSignal(id, "", "", 0);
	if (findElementFromDynamicArray(signalsList, signal)==NULL)
		return -1;
	removeElementDynamicArray(signalsList, signal);
	destroySignal(signal);
	return 1;
}

void printSignal(Signal *signal) {
	/*
		Prints a signal formated
		Input:
			signal - pointer to signal to print
	*/
	printf("%-8d%-24s%-16s%-8d\n",
		signal->id, signal->modulatedSignal,
		signal->type, signal->priorityNumber);
}

void listSignals(DynamicArray * signalsList){
	/*Prints on the screen evry signal from given list
	Input: signalsList - list of signals
	*/
	if (signalsList->numberOfElements == 0)
		printf("%s\n", "There are no signals in the list!");
	else {
		printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
		for (int i = 0; i < signalsList->numberOfElements; i++)
			printSignal(signalsList->elements[i]);
	}
}

void listSignalsByType(char * type, DynamicArray * signalsList){
	/*Prints on the screen evry signal from given list with given type
	Input:	type - string of chars between (damage-inner, damage-outer, sensor-reading)
			signalsList - list of signals
	*/
	int numberOfSignalsFound = 0;
	for (int i = 0; i < signalsList->numberOfElements; i++)
		if (strcmp(((Signal *)signalsList->elements[i])->type, type) == 0) {
			if (numberOfSignalsFound == 0)printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
			printSignal(signalsList->elements[i]);
			numberOfSignalsFound++;
		}
	if (numberOfSignalsFound == 0)
		printf("There is no signal with type: %s.\n", type);
}

void listSignalsByPriority(int priorityNumber, DynamicArray * signalsList){
	/*Prints on the screen evry signal from given list with given priority
	Input:	priorityNumber - integer
			signalsList - list of signals
	*/
	int numberOfSignalsFound = 0;
	for (int i = 0; i < signalsList->numberOfElements; i++)
		if (((Signal *)signalsList->elements[i])->priorityNumber == priorityNumber) {
			if (numberOfSignalsFound == 0)printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
			printSignal(signalsList->elements[i]);
			numberOfSignalsFound++;
		}
	if (numberOfSignalsFound == 0)
		printf("There is no signal with priority number: %d.\n", priorityNumber);
}

void listSignalsWithMaximumPriorityNumber(int maximumPriorityNumber, DynamicArray * signalsList, int sortingWay){
	/*Prints a the list with the signals which have priority number less than maximumPriorityNumber
	sorted by modulatedSignal
	Input: signalsList - SignalsList
		   maximumPriorityNumber - int
		   sortingWay - integer {0 - ascending | 1 - descending)
	*/
	int numberOfSignalsFound = 0;
	DynamicArray *copyOfSignalsList = createCopyOfDynamicArray(signalsList);
	if (sortingWay)
		qsort(copyOfSignalsList->elements, copyOfSignalsList->numberOfElements, sizeof(Signal*), compareTwoSignalsLexicographicByModulatedSignalReverse);
	else
		qsort(copyOfSignalsList->elements, copyOfSignalsList->numberOfElements, sizeof(Signal*), compareTwoSignalsLexicographicByModulatedSignal);
	for (int i = 0; i < copyOfSignalsList->numberOfElements; i++)
		if (((Signal *)copyOfSignalsList->elements[i])->priorityNumber < maximumPriorityNumber) {
			if (numberOfSignalsFound == 0)printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
			printSignal(copyOfSignalsList->elements[i]);
			numberOfSignalsFound++;
		}
	destroyDynamicArray(copyOfSignalsList);
	if (numberOfSignalsFound == 0)
		printf("There is no signal with maximum priority number: %d.\n", maximumPriorityNumber);
}
