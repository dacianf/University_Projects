#pragma once
#include "DynamicVector.h"


typedef struct {
	int id;
	char modulatedSignal[200],
		type[200];
	int priorityNumber;
}Signal;

typedef struct {
	Signal *signals;
	int numberOfSignals;
	int sizeOfList;
}SignalsList;

SignalsList* resizeSignalsList(SignalsList* listToResize, int size);

SignalsList* createSignalsList();

void distroySignalsList(SignalsList* signals);

int searchSignalByID(int id, SignalsList *signalsList);
	//Search by id if in the signals list exists a signal with given id
	//Input: id - positive integer
	//		 signalsList - list of signals
	//Output: i - integer representing position 
	//			- if in the list exists a signal with given id
	//		  0 - otherwise

void listSignalsWithMaximumPriorityNumber(SignalsList* signalsList, int maximumPriorityNumber);

int compareTwoSignalsLexicographicByModulatedSignal(Signal *firstSignal, Signal *secondSignal);

void listSignals(SignalsList* signalsList);
	/*Prints on the screen evry signal from given list
	Input: signalsList - list of signals
	*/

void listSignalsByType(char * type, SignalsList* signalsList);
	/*Prints on the screen evry signal from given list
	Input:	type - string of chars between (damage-inner, damage-outer, sensor-reading)
			signalsList - list of signals
	*/

int copyFromASignalToAnother(Signal *destinationSignal, Signal *sourceSignal);
	/*Copies from source signal into destination signal
	Input: destinationString - Signal
		   sourceSignal - Signal
	Output: 1 - after modification occured
	*/

int addSignal(int id, char *modulatedSignal, char *type, int priorityNumber, SignalsList *signalsList, DynamicArray* archive);
	/*Add a given signal into signals list
	Input: id - positive integer
		   modulatedSignal - string of chars
		   type - string of chars (damage-inner, damage-outer, sensor-reading)
		   priorityNumber - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			0 - otherwise
	*/

int updateSignal(int id, char *newModulatedSignal, char *newType, int newPriorityNumber, SignalsList *signalsList, DynamicArray* archive);
	/*Updates a signal info from signals list and finding it by id
	Input: id - positive integer
		   newModulatedSignal - string of chars
		   newType - string of chars (damage-inner, damage-outer, sensor-reading)
		   newPriorityNumber - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			0 - otherwise
	*/

int deleteSignal(int id, SignalsList *signalsList, DynamicArray* archive);

void copySignalList(SignalsList* destinationList, SignalsList* sourceList);

	/*Delets a signal from signals list
	Input: id - positive integer
		   signalsList - list of signals
	Output: 1 - if operation succeded
			0 - otherwise
	*/
