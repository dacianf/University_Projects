#pragma once
#ifndef SIGNAL_H
#include "Signal.h"

#ifndef DYNAMICVECTOR_H
#include "DynamicVector.h"


typedef struct {
	Signal signal;
	int commandValue;
	//commandValue is: 1 - Add
	//				   2 - Update
	//				   3 - Delete
	int undoRedoFlag;
	//undoRedoFlag is: 1 - if command comes from an undo/redo operation
	//				   0 - otherwise
}Command;

void doCommand(Command *command, SignalsList *signals, DynamicArray *undoStack, DynamicArray *redoStack);
#endif // !SIGNAL_H
#endif // !SIGNAL_H