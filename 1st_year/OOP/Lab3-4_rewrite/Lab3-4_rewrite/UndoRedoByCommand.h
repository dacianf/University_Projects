#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "DynamicArray.h"
#ifndef SIGNAL_H
#define SIGNAL_H
#include "Signal.h"

typedef struct {
	int commandID;
	Signal *signalForCommand;
}UndoRedoByCommand;

UndoRedoByCommand* createUndoRedoByCommand();
void destroyUndoRedoByCommand(UndoRedoByCommand*);
UndoRedoByCommand* copyUndoRedoByCommand(UndoRedoByCommand*);


#endif // !SIGNAL_H
#endif // !DYNAMICARRAY_H
