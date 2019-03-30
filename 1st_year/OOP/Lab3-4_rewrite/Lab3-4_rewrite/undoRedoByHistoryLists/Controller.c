#include "Controller.h"

int addSignal(int id, char * modulatedSignal, char * type, int priorityNumber, DynamicArray *signalsList, DynamicArray * undoRedoList){
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
	if (findElementFromDynamicArray(signalsList, newSignal) != NULL)
		return 0;
	addElementDynamicArray(signalsList, newSignal);
	prepareUndo(undoRedoList);

	//undo with list of states
	addElementDynamicArray(undoRedoList, signalsList);

	destroySignal(newSignal);
	return 1;
}

int updateSignal(int id, char * newModulatedSignal, char * newType, int newPriorityNumber, DynamicArray * signalsList, DynamicArray * undoRedoList){
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

	int successfulOperation = updateElementDynamicArray(signalsList, newSignal);
	if (!successfulOperation)return successfulOperation;

	prepareUndo(undoRedoList);

	//undo by list of states
	addElementDynamicArray(undoRedoList, signalsList);

	destroySignal(newSignal);
	return successfulOperation;
}

int deleteSignal(int id, DynamicArray * signalsList, DynamicArray * undoRedoList){
	/*Delets a signal from signals list
	Input: id - positive integer
		   signalsList - list of signals
		   undoRedoList - list of backups
	Output: 1 - if operation succeded
			-1 - otherwise
	*/
	Signal* signal = createSignal(id, "", "", 0);
	Signal* signalToDelete = findElementFromDynamicArray(signalsList, signal);
	if (signalToDelete==NULL)
		return -1;
	prepareUndo(undoRedoList);
	removeElementDynamicArray(signalsList, signal);
	//undo by list of states
	addElementDynamicArray(undoRedoList, signalsList);

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

DynamicArray* listSignals(DynamicArray * signalsList){
	/*Prints on the screen evry signal from given list
	Input: signalsList - list of signals
	*/
	return createCopyOfDynamicArray(signalsList);
}

DynamicArray* listSignalsByType(char * type, DynamicArray * signalsList){
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

DynamicArray* listSignalsByPriority(int priorityNumber, DynamicArray * signalsList){
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

DynamicArray* listSignalsWithMaximumPriorityNumber(int maximumPriorityNumber, DynamicArray * signalsList, int sortingWay){
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

void prepareUndo(DynamicArray * undoRedoList)
{
	if (undoRedoList->undoRedoIndex < undoRedoList->numberOfElements)
		for (int i = undoRedoList->undoRedoIndex; i < undoRedoList->numberOfElements; i++)
			undoRedoList->destroyElement(undoRedoList->elements[i]);
	undoRedoList->numberOfElements = undoRedoList->undoRedoIndex;
}


DynamicArray* undo(DynamicArray * undoRedoList, DynamicArray *currentList)
{
	if (undoRedoList->undoRedoIndex - 1 == 0)
		printf("No more undos are available!\n");
	else {
		//destroyDynamicArray(currentList);
		DynamicArray* x = currentList;
		currentList = createCopyOfDynamicArray(undoRedoList->elements[--undoRedoList->undoRedoIndex - 1]);
		destroyDynamicArray(x);
	}
	return currentList;
}

DynamicArray* redo(DynamicArray * undoRedoList, DynamicArray * currentList){
	if (undoRedoList->undoRedoIndex == undoRedoList->numberOfElements)
		printf("No more redos are available!\n");
	else {
		//destroyDynamicArray(currentList);
		DynamicArray* x = currentList;
		currentList = createCopyOfDynamicArray(undoRedoList->elements[++undoRedoList->undoRedoIndex - 1]);
		destroyDynamicArray(x);
	}
	return currentList;
}