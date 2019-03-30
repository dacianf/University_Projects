#pragma once
#include "DynamicArray.h"
#include "Signal.h"

typedef struct {
	int commandID;
	Signal *elementForCommand;
}UndoRedoByCommand;

UndoRedoByCommand* createUndoRedoByCommand(int commandID, void* elementForCommand);
void destroyUndoRedoByCommand(UndoRedoByCommand*);
UndoRedoByCommand* copyUndoRedoByCommand(UndoRedoByCommand*);
