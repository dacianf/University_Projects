#include "Signal.h"
#include <stdio.h>
#include <stdlib.h>

int searchSignalByID(int id, SignalsList *signalsList) {
	//Search by id if in the signals list exists a signal with given id
	//Input: id - positive integer
	//		 signalsList - list of signals
	//Output: i - integer representing position 
	//			- if in the list exists a signal with given id
	//		  -1 - otherwise
	for (int i = 0; i < signalsList->numberOfSignals; i++)
		if (signalsList->signals[i].id == id)
			return i;
	return -1;
}

void listSignalsWithMaximumPriorityNumber(SignalsList* signalsList, int maximumPriorityNumber)
{
	/*Prints a the list with the signals which have priority number less than maximumPriorityNumber
	sorted by modulatedSignal
	Input: signalsList - SignalsList
		   maximumPriorityNumber - int
	*/
	SignalsList* signalListForFilter = createSignalsList();
	copySignalList(signalListForFilter, signalsList);
	qsort(signalListForFilter->signals, signalListForFilter->numberOfSignals, sizeof(Signal), compareTwoSignalsLexicographicByModulatedSignal);
	int numberOfSignalsFound = 0;
	for (int i = 0; i < signalListForFilter->numberOfSignals; i++)
		if (signalListForFilter->signals[i].priorityNumber < maximumPriorityNumber) {
			if (numberOfSignalsFound == 0)printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
			printf("%-8d%-24s%-16s%-8d\n",
				signalListForFilter->signals[i].id, signalListForFilter->signals[i].modulatedSignal,
				signalListForFilter->signals[i].type, signalListForFilter->signals[i].priorityNumber),
				numberOfSignalsFound++;
		}
	if (numberOfSignalsFound == 0)
		printf("There is no signal with priority number less than: %d.\n", maximumPriorityNumber);

}

int compareTwoSignalsLexicographicByModulatedSignal(Signal *firstSignal, Signal *secondSignal)
{
	/*Compares two signals by their modulated signal name lexicographic
	Input: firstSignal - Signal
		   secondSignal - Signal
	Output: 1 if the first signal's modulated name is lexicographic smaller then the second one
		    0 otherwise
	*/
	if (strcmp(secondSignal->modulatedSignal, firstSignal->modulatedSignal) < 0)
		return 1;
	return 0;
}

void listSignals(SignalsList* signalsList) {
	/*Prints on the screen evry signal from given list
	Input: signalsList - list of signals
	*/
	if (signalsList->numberOfSignals == 0)
		printf("There are no signals in the list!\n");
	else {
		printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
		for (int i = 0; i < signalsList->numberOfSignals; i++)
			printf("%-8d%-24s%-16s%-8d\n",
				signalsList->signals[i].id, signalsList->signals[i].modulatedSignal,
				signalsList->signals[i].type, signalsList->signals[i].priorityNumber);
	}
}

void listSignalsByType(char * type, SignalsList* signalsList) {
	/*Prints on the screen evry signal from given list
	Input:	type - string of chars between (damage-inner, damage-outer, sensor-reading)
			signalsList - list of signals
	*/
	int numberOfSignalsFound = 0;
	for (int i = 0; i < signalsList->numberOfSignals; i++)
		if (strcmp(signalsList->signals[i].type, type) == 0) {
			if(numberOfSignalsFound==0)printf("Signals are:\nID\tModulated Signal\tSignal type\tPriority number\n");
			printf("%-8d%-24s%-16s%-8d\n",
				signalsList->signals[i].id, signalsList->signals[i].modulatedSignal,
				signalsList->signals[i].type, signalsList->signals[i].priorityNumber),
				numberOfSignalsFound++;
		}
	if (numberOfSignalsFound == 0)
		printf("There is no signal with type: %s.\n", type);
}

int copyFromASignalToAnother(Signal *destinationSignal, Signal *sourceSignal) {
	/*Copies from source signal into destination signal
	Input: destinationString - Signal
		   sourceSignal - Signal
	Output: 1 - after modification occured
	*/
	destinationSignal->id = sourceSignal->id;
	destinationSignal->priorityNumber = sourceSignal->priorityNumber;
	strcpy(destinationSignal->modulatedSignal, sourceSignal->modulatedSignal);
	strcpy(destinationSignal->type, sourceSignal->type);
	return 1;
}

int addSignal(int id, char *modulatedSignal, char *type, int priorityNumber, SignalsList *signalsList, DynamicArray* archive) {
	/*Add a given signal into signals list
	Input: id - positive integer
		   modulatedSignal - string of chars
		   type - string of chars (damage-inner, damage-outer, sensor-reading)
		   priorityNumber - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			-1 - otherwise
	*/
	if (signalsList->numberOfSignals == 0 || searchSignalByID(id, signalsList) == -1) {
		
		SignalsList* currentState = createSignalsList();
		copySignalList(currentState, signalsList);
		/*if (archive->undoRedoIndex < archive->numberOfElements)
			for (int i = archive->undoRedoIndex + 1; i < archive->numberOfElements; i++)
				free(archive->data[i]);
		archive->numberOfElements = archive->undoRedoIndex;*/
		addItemInDynamicArray(archive, currentState);

		signalsList->signals[signalsList->numberOfSignals].id = id;
		signalsList->signals[signalsList->numberOfSignals].priorityNumber = priorityNumber;
		strcpy(signalsList->signals[signalsList->numberOfSignals].modulatedSignal, modulatedSignal);
		strcpy(signalsList->signals[signalsList->numberOfSignals].type, type);
		signalsList->numberOfSignals++;
		/*Signal givenSignal;
		copyFromASignalToAnother(&givenSignal, signalsList->signals[signalsList->numberOfSignals]);*/
		/*Command *undoCommand = malloc(sizeof(Command));
		undoCommand->commandValue = 3;
		copyFromASignalToAnother(&undoCommand->signal, &givenSignal);

		Command *redoCommand = malloc(sizeof(Command));
		redoCommand->commandValue = 1;
		copyFromASignalToAnother(&redoCommand->signal, &givenSignal);*/
		
		return 1;
	}
	return -1;
}

int updateSignal(int id, char *newModulatedSignal, char *newType, int newPriorityNumber, SignalsList *signalsList, DynamicArray* archive) {
	/*Updates a signal info from signals list and finding it by id
	Input: id - positive integer
		   newModulatedSignal - string of chars
		   newType - string of chars (damage-inner, damage-outer, sensor-reading)
		   newPriorityNumber - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			-1 - otherwise
	*/
	int signalPosition = searchSignalByID(id, signalsList);
	if (signalPosition == -1) return 0;
	SignalsList* currentState = createSignalsList();
	copySignalList(currentState, signalsList);
	addItemInDynamicArray(archive, currentState);
	strcpy(signalsList->signals[signalPosition].modulatedSignal, newModulatedSignal);
	strcpy(signalsList->signals[signalPosition].type, newType);
	signalsList->signals[signalPosition].priorityNumber = newPriorityNumber;
	/*Signal givenSignal;
	copyFromASignalToAnother(&givenSignal, &signalsList->signals[signalsList->numberOfSignals]);*/

	/*Command *undoCommand = malloc(sizeof(Command));
	undoCommand->commandValue = 2;
	copyFromASignalToAnother(&undoCommand->signal, &signalsList->signals[searchSignalByID(givenSignal.id, signals)]);

	Command *redoCommand = malloc(sizeof(Command));
	redoCommand->commandValue = 2;
	copyFromASignalToAnother(&redoCommand->signal, &givenSignal);*/
	
	return 1;
}

int deleteSignal(int id, SignalsList *signalsList, DynamicArray* archive) {
	/*Delets a signal from signals list
	Input: id - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			-1 - otherwise
	*/
	int signalPosition = searchSignalByID(id, signalsList);
	if (signalPosition == -1) return -1;

	/*Signal givenSignal;
	copyFromASignalToAnother(&givenSignal, &signalsList->signals[signalPosition]);*/
	SignalsList* currentState = createSignalsList();
	copySignalList(currentState, signalsList);
	addItemInDynamicArray(archive, currentState);
	for (int i = signalPosition; i < signalsList->numberOfSignals; i++)
		copyFromASignalToAnother(&(signalsList->signals[i]), &(signalsList->signals[i + 1]));
	signalsList->numberOfSignals--;

	/*Command *undoCommand = malloc(sizeof(Command));
	undoCommand->commandValue = 1;
	copyFromASignalToAnother(&undoCommand->signal, &signalsList->signals[searchSignalByID(givenSignal.id, signalsList)]);

	Command *redoCommand = malloc(sizeof(Command));
	redoCommand->commandValue = 3;
	copyFromASignalToAnother(&redoCommand->signal, &givenSignal);*/
	
	return 1;
}

void copySignalList(SignalsList* destinationList, SignalsList* sourceList) {
	/**/
	destinationList->numberOfSignals = sourceList->numberOfSignals;
	if (destinationList->sizeOfList < sourceList->sizeOfList)
		resizeSignalsList(destinationList, destinationList->sizeOfList);
	for (int i = 0; i < sourceList->numberOfSignals; i++)
		copyFromASignalToAnother(&destinationList->signals[i], &sourceList->signals[i]);
}

SignalsList* resizeSignalsList(SignalsList *listToResize, int size) {
	/**/
	Signal *temp = realloc(listToResize->signals, size);
	if (temp)
		listToResize->signals = temp;
	return listToResize;
}

SignalsList* createSignalsList() {
	/**/
	SignalsList* signals = (SignalsList*)malloc(sizeof(SignalsList));
	signals->signals = (Signal *)malloc(100 * sizeof(Signal));
	signals->numberOfSignals = 0;
	signals->sizeOfList = 100;
	return signals;
}

void distroySignalsList(SignalsList* signals) {
	free(signals->signals);
	free(signals);
}
