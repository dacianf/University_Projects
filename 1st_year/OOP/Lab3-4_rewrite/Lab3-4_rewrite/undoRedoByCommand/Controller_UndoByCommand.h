#pragma once
#include <stdlib.h>
#include "../DynamicArray.h"
#include "../Signal.h"
#include "UndoRedoByCommand.h"

int addSignal(int id, char *modulatedSignal, char *type, int priorityNumber, DynamicArray* signalsList, DynamicArray * undoList, DynamicArray * redoList);
int updateSignal(int id, char *newModulatedSignal, char *newType, int newPriorityNumber, DynamicArray *signalsList, DynamicArray * undoList, DynamicArray * redoList);
int deleteSignal(int id, DynamicArray *signalsList, DynamicArray * undoList, DynamicArray * redoList);

DynamicArray* listSignals(DynamicArray* signalsList);
DynamicArray* listSignalsByType(char * type, DynamicArray* signalsList);
DynamicArray* listSignalsByPriority(int priority, DynamicArray* signalsList);
DynamicArray* listSignalsWithMaximumPriorityNumber(int maximumPriorityNumber, DynamicArray* signalsList, int sortingWay);
