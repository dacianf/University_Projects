#include "Controller_UndoByCommand.h"

int addSignal(int id, char * modulatedSignal, char * type, int priorityNumber, DynamicArray *signalsList, DynamicArray* undoList, DynamicArray* redoList) {
	/*Add a given signal into signals list
	Input: id - positive integer
		   modulatedSignal - string of chars
		   type - string of chars (damage-inner, damage-outer, sensor-reading)
		   priorityNumber - positive integer
		   signalsList - list of signals
		   undoRedoList - list of backups
	Output: 1 - if operation succeded
			0 - otherwise
	*/
	Signal* newSignal = createSignal(id, modulatedSignal, type, priorityNumber);
	if (findElementFromDynamicArray(signalsList, newSignal) != NULL) {
		destroySignal(newSignal);
		return 0;
	}
	addElementDynamicArray(signalsList, newSignal);

	UndoRedoByCommand* commands = createUndoRedoByCommand(2, newSignal, 1, newSignal, copySignal, destroySignal);
	int successfulOperation = updateElementDynamicArray(signalsList, newSignal);

	addOperationForUndoRedoByCommand(undoList, commands);

	destroyUndoRedoByCommand(commands);
	destroySignal(newSignal);
	return 1;
}

int updateSignal(int id, char * newModulatedSignal, char * newType, int newPriorityNumber, DynamicArray * signalsList, DynamicArray* undoList, DynamicArray* redoList) {
	/*Updates a signal info from signals list and finding it by id
	Input: id - positive integer
		   newModulatedSignal - string of chars
		   newType - string of chars (damage-inner, damage-outer, sensor-reading)
		   newPriorityNumber - positive integer
		   signalsList - list of signals
		   undoRedoList - list of backups
	Output: 1 - if operation succeded
			0 - otherwise
	*/
	Signal* newSignal = createSignal(id, newModulatedSignal, newType, newPriorityNumber);
	void* signalToUpdate = findElementFromDynamicArray(signalsList, newSignal);
	if (signalToUpdate == NULL) {
		destroySignal(newSignal);
		return 0;
	}
	UndoRedoByCommand* commands = createUndoRedoByCommand(3, signalToUpdate, 3, newSignal, copySignal, destroySignal);
	int successfulOperation = updateElementDynamicArray(signalsList, newSignal);

	addOperationForUndoRedoByCommand(undoList, commands);

	destroyUndoRedoByCommand(commands);
	destroySignal(newSignal);
	return successfulOperation;
}

int deleteSignal(int id, DynamicArray * signalsList, DynamicArray* undoList, DynamicArray* redoList) {
	/*Delets a signal from signals list
	Input: id - positive integer
		   signalsList - list of signals
		   undoRedoList - list of backups
	Output: 1 - if operation succeded
			0 - otherwise
	*/
	Signal* signal = createSignal(id, "", "", 0);
	Signal* signalToDelete = findElementFromDynamicArray(signalsList, signal);
	if (signalToDelete == NULL){
		destroySignal(signal);
		return 0;
	}
	UndoRedoByCommand* commands = createUndoRedoByCommand(1, signalToDelete, 2, signal, copySignal, destroySignal);

	removeElementDynamicArray(signalsList, signal);

	addOperationForUndoRedoByCommand(undoList, commands);

	destroyUndoRedoByCommand(commands);
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

DynamicArray* listSignals(DynamicArray * signalsList) {
	/*Prints on the screen evry signal from given list
	Input: signalsList - list of signals
	*/
	return createCopyOfDynamicArray(signalsList);
}

DynamicArray* listSignalsByType(char * type, DynamicArray * signalsList) {
	/*Prints on the screen evry signal from given list with given type
	Input:	type - string of chars between (damage-inner, damage-outer, sensor-reading)
			signalsList - list of signals
	*/
	DynamicArray* signalsForListing = createDynamicArray(sizeof(void*), signalsList->createElement, signalsList->destroyElement, signalsList->copyElement, signalsList->compareElements);
	for (int i = 0; i < signalsList->numberOfElements; i++)
		if (strcmp(((Signal *)signalsList->elements[i])->type, type) == 0)
			addElementDynamicArray(signalsForListing, signalsList->elements[i]);
	return signalsForListing;
}

DynamicArray* listSignalsByPriority(int priorityNumber, DynamicArray * signalsList) {
	/*Prints on the screen evry signal from given list with given priority
	Input:	priorityNumber - integer
			signalsList - list of signals
	*/
	DynamicArray* signalsForListing = createDynamicArray(sizeof(void*), signalsList->createElement, signalsList->destroyElement, signalsList->copyElement, signalsList->compareElements);
	for (int i = 0; i < signalsList->numberOfElements; i++)
		if (((Signal *)signalsList->elements[i])->priorityNumber == priorityNumber)
			addElementDynamicArray(signalsForListing, signalsList->elements[i]);
	return signalsForListing;
}

DynamicArray* listSignalsWithMaximumPriorityNumber(int maximumPriorityNumber, DynamicArray * signalsList, int sortingWay) {
	/*Prints a the list with the signals which have priority number less than maximumPriorityNumber
	sorted by modulatedSignal
	Input: signalsList - SignalsList
		   maximumPriorityNumber - int
		   sortingWay - integer {0 - ascending | 1 - descending)
	*/
	DynamicArray* signalsForListing = createDynamicArray(sizeof(void*), signalsList->createElement, signalsList->destroyElement, signalsList->copyElement, signalsList->compareElements);
	for (int i = 0; i < signalsList->numberOfElements; i++)
		if (((Signal *)signalsList->elements[i])->priorityNumber < maximumPriorityNumber)
			addElementDynamicArray(signalsForListing, signalsList->elements[i]);
	if (sortingWay)
		qsort(signalsForListing->elements, signalsForListing->numberOfElements, sizeof(Signal*), compareTwoSignalsLexicographicByModulatedSignalReverse);
	else
		qsort(signalsForListing->elements, signalsForListing->numberOfElements, sizeof(Signal*), compareTwoSignalsLexicographicByModulatedSignal);
	return signalsForListing;
}