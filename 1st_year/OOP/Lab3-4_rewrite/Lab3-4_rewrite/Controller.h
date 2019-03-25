#pragma once
#include <stdlib.h>

#ifndef DYNAMICARRAY_H
#include "DynamicArray.h"
#ifndef SIGNAL_H
#include "Signal.h"

int addSignal(int id, char *modulatedSignal, char *type, int priorityNumber, DynamicArray* signalsList);
int updateSignal(int id, char *newModulatedSignal, char *newType, int newPriorityNumber, DynamicArray *signalsList);
int deleteSignal(int id, DynamicArray *signalsList);

void listSignals(DynamicArray* signalsList);
void listSignalsByType(char * type, DynamicArray* signalsList);
void listSignalsByPriority(int priority, DynamicArray* signalsList);
void listSignalsWithMaximumPriorityNumber(int maximumPriorityNumber, DynamicArray* signalsList, int sortingWay);


#endif
#endif