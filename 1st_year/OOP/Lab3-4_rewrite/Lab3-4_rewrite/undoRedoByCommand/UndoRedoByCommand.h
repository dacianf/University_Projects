#pragma once
#include "../DynamicArray.h"
#include "../Signal.h"
#include "Controller_UndoByCommand.h"

typedef struct {
	int commandID;
	void* elementForCommand;
}Command;

typedef struct {
	Command* undo;
	Command* redo;
	void* (*copyElement)();
	void* (*deleteElement)();
}UndoRedoByCommand;

UndoRedoByCommand * createUndoRedoByCommand(int undoCommandID, void* elementForUndoCommand, int redoCommandID, void* elementForRedoCommand, void* functionToCopyAnElement, void* functionToDeleteAnElement);
void destroyUndoRedoByCommand(UndoRedoByCommand*);
UndoRedoByCommand* copyUndoRedoByCommand(UndoRedoByCommand*);

void addOperationForUndoRedoByCommand(DynamicArray* undoRedoArray, UndoRedoByCommand* operation);

int undoByCommand(DynamicArray * undoArray, DynamicArray * currentList);

int redoByCommand(DynamicArray * redoArray, DynamicArray * currentList);

Command* createCommand(int commandID, void* commandParameter);
void destroyCommand(Command* commandToDestroy, void* (*functionToDestroyAnElement)());
