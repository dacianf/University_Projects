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
	if (findElementFromDynamicArray(signalsList, newSignal) != NULL)
		return 0;
	addElementDynamicArray(signalsList, newSignal);

	//undo with list of commands
	UndoRedoByCommand* commandUNDO = createUndoRedoByCommand(2, copySignal(newSignal));
	UndoRedoByCommand* commandREDO = createUndoRedoByCommand(1, copySignal(newSignal));
	
	addElementDynamicArray(undoList, commandUNDO);
	addElementDynamicArray(redoList, commandREDO);

	destroyUndoRedoByCommand(commandUNDO);
	destroyUndoRedoByCommand(commandREDO);
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
	void* signalToRemove = findElementFromDynamicArray(signalsList, newSignal);
	if (signalToRemove == NULL) return 0;
	UndoRedoByCommand* commandUNDO = createUndoRedoByCommand(3, copySignal(signalToRemove));
	UndoRedoByCommand* commandREDO = createUndoRedoByCommand(3, copySignal(newSignal));

	int successfulOperation = updateElementDynamicArray(signalsList, newSignal);

	addElementDynamicArray(undoList, commandUNDO);
	addElementDynamicArray(redoList, commandREDO);

	destroyUndoRedoByCommand(commandUNDO);
	destroyUndoRedoByCommand(commandREDO);
	destroySignal(newSignal);
	return successfulOperation;
}

int deleteSignal(int id, DynamicArray * signalsList, DynamicArray* undoList, DynamicArray* redoList) {
	/*Delets a signal from signals list
	Input: id - positive integer
		   signalsList - list of signals
		   undoRedoList - list of backups
	Output: 1 - if operation succeded
			-1 - otherwise
	*/
	Signal* signal = createSignal(id, "", "", 0);
	Signal* signalToDelete = findElementFromDynamicArray(signalsList, signal);
	if (signalToDelete == NULL)
		return -1;

	UndoRedoByCommand* commandUNDO = createUndoRedoByCommand(1, copySignal(signalToDelete));
	UndoRedoByCommand* commandREDO = createUndoRedoByCommand(2, copySignal(signalToDelete));

	removeElementDynamicArray(signalsList, signal);

	//undo with list of commands
	addElementDynamicArray(undoList, commandUNDO);
	addElementDynamicArray(redoList, commandREDO);

	destroyUndoRedoByCommand(commandUNDO);
	destroyUndoRedoByCommand(commandREDO);
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
	printf("%p", signalsForListing);
	return signalsForListing;
}

DynamicArray* listSignalsWithMaximumPriorityNumber(int maximumPriorityNumber, DynamicArray * signalsList, int sortingWay) {
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
	return copyOfSignalsList;
}

void prepareUndo(DynamicArray * undoRedoList)
{
	if (undoRedoList->undoRedoIndex < undoRedoList->numberOfElements)
		for (int i = undoRedoList->undoRedoIndex; i < undoRedoList->numberOfElements; i++)
			undoRedoList->destroyElement(undoRedoList->elements[i]);
	undoRedoList->numberOfElements = undoRedoList->undoRedoIndex;
}

void undoCMD(DynamicArray * undoList, DynamicArray* currentList)
{
	if (undoList->undoRedoIndex == 0)
		printf("No more undos are available!\n");
	else {
		UndoRedoByCommand* commandToExecute = popFromDynamicArray(undoList);
		if (commandToExecute->commandID == 1)
			addElementDynamicArray(currentList, commandToExecute->elementForCommand);
		else if (commandToExecute->commandID == 2)
			removeElementDynamicArray(currentList, commandToExecute->elementForCommand);
		else if (commandToExecute->commandID == 3)
			updateElementDynamicArray(currentList, commandToExecute->elementForCommand);
		destroyUndoRedoByCommand(commandToExecute);
	}
}

void redoCMD(DynamicArray * redoList, DynamicArray* currentList)
{
	if (redoList->undoRedoIndex == redoList->numberOfElements - 1)
		printf("No more redos are available!\n");
	else {
		UndoRedoByCommand* commandToExecute = popFromDynamicArray(redoList);
		if (commandToExecute->commandID == 1)
			addElementDynamicArray(currentList, commandToExecute->elementForCommand);
		else if (commandToExecute->commandID == 2)
			removeElementDynamicArray(currentList, commandToExecute->elementForCommand);
		else if (commandToExecute->commandID == 3)
			updateElementDynamicArray(currentList, commandToExecute->elementForCommand);
		destroyUndoRedoByCommand(commandToExecute);
	}
}
