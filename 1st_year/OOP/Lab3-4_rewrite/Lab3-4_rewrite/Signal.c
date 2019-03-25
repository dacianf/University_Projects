#include "Signal.h"

Signal * createSignal(int id, char *modulateSignal, char *type, int priorityNumber){
	/*
		Creats a new signal
		Input: id - positive integer
		   newModulatedSignal - string of chars
		   newType - string of chars (damage-inner, damage-outer, sensor-reading)
		   newPriorityNumber - positive integer
		   signalsList - list of signals
		Output:
			newSignal - pointer to the new signal
	*/
	Signal* newSignal = (Signal*)malloc(sizeof(Signal));
	newSignal->id = id;
	newSignal->modulatedSignal = (char*)malloc(strlen(modulateSignal) + 1);
	strcpy_s(newSignal->modulatedSignal, strlen(modulateSignal) + 1, modulateSignal);
	newSignal->type = (char*)malloc(strlen(type) + 1);
	strcpy_s(newSignal->type, strlen(type) + 1, type);
	newSignal->priorityNumber = priorityNumber;
	return newSignal;
}

void distroySignal(Signal * signal){
	/*
		Frees the memory allocated for given signal
		Input:
			signal - pointer to a signal
	*/
	free(signal->modulatedSignal);
	free(signal->type);
	free(signal);
}

Signal * copySignal(Signal * signalToCopy){
	/*
		Creates a copy of given signal and returns a pointer to it
		Input:
			signalToCopy - pointer to signal
		Output:
			pointer to a new signal which is a copy of a given one
	*/
	return createSignal(signalToCopy->id, signalToCopy->modulatedSignal, signalToCopy->type, signalToCopy->priorityNumber);
}

int compareTwoSignalsLexicographicByModulatedSignal(Signal *firstSignal, Signal *secondSignal){
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

int compareTwoSignalsByID(Signal *firstSignal, Signal *secondSignal) {
	/*Compares two signals by their ID
	Input: firstSignal - Signal
		   secondSignal - Signal
	Output: 0 - if theirs id are equal
			int > 0 - if firstSignals id is grater than second one
			int < 0 - otherwise
	*/
	return firstSignal->id - secondSignal->id;
}

