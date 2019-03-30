#pragma once
#include <stdlib.h>
#include "DynamicArray.h"
#include "Signal.h"
#include "UndoRedoByCommand.h"

int addSignal(int id, char *modulatedSignal, char *type, int priorityNumber, DynamicArray* signalsList, DynamicArray * undoRedoList);
int updateSignal(int id, char *newModulatedSignal, char *newType, int newPriorityNumber, DynamicArray *signalsList, DynamicArray * undoRedoList);
int deleteSignal(int id, DynamicArray *signalsList, DynamicArray * undoRedoList);

DynamicArray* listSignals(DynamicArray* signalsList);
DynamicArray* listSignalsByType(char * type, DynamicArray* signalsList);
DynamicArray* listSignalsByPriority(int priority, DynamicArray* signalsList);
DynamicArray* listSignalsWithMaximumPriorityNumber(int maximumPriorityNumber, DynamicArray* signalsList, int sortingWay);

DynamicArray* undo(DynamicArray* undoRedoList, DynamicArray* currentList);
DynamicArray* redo(DynamicArray* undoRedoList, DynamicArray* currentList);

void prepareUndo(DynamicArray * undoRedoList);

void undoCMD(DynamicArray *undoList, DynamicArray* currentList);
void redoCMD(DynamicArray *redoList, DynamicArray* currentList);