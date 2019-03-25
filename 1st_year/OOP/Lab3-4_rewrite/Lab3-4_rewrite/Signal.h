#pragma once
#include <stdlib.h>

typedef struct {
	int id;
	char *modulatedSignal,
		*type;
	int priorityNumber;
}Signal;

Signal* createSignal(int id, char *modulateSignal, char *type, int priorityNumber);

void destroySignal(Signal *signal);

Signal* copySignal(Signal *signalToCopy);

int compareTwoSignalsLexicographicByModulatedSignal(Signal *firstSignal, Signal *secondSignal);

int compareTwoSignalsByID(Signal * firstSignal, Signal * secondSignal);

void copyFromASignalToAnother(Signal *destinationDynamicArray, Signal *sourceDynamicArray);
