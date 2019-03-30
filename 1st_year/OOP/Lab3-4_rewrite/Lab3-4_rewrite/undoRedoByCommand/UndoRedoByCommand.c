#include "UndoRedoByCommand.h"

UndoRedoByCommand * createUndoRedoByCommand(int undoCommandID, void* elementForUndoCommand,
	int redoCommandID, void* elementForRedoCommand,
	void* functionToCopyAnElement, void* functionToDeleteAnElement)
{
	UndoRedoByCommand *newUndoRedo = (UndoRedoByCommand*)malloc(sizeof(UndoRedoByCommand));
	newUndoRedo->copyElement = functionToCopyAnElement;
	newUndoRedo->undo = createCommand(undoCommandID, newUndoRedo->copyElement(elementForUndoCommand));
	newUndoRedo->redo = createCommand(redoCommandID, newUndoRedo->copyElement(elementForRedoCommand));
	newUndoRedo->deleteElement = functionToDeleteAnElement;
	return newUndoRedo;
}

void destroyUndoRedoByCommand(UndoRedoByCommand * undoRedoInstance)
{
	if (undoRedoInstance->undo->elementForCommand != NULL)
		destroyCommand(undoRedoInstance->undo, undoRedoInstance->deleteElement);
	if (undoRedoInstance->redo->elementForCommand != NULL)
		destroyCommand(undoRedoInstance->redo, undoRedoInstance->deleteElement);
	free(undoRedoInstance);
}

UndoRedoByCommand * copyUndoRedoByCommand(UndoRedoByCommand *undoRedoInstance)
{
	UndoRedoByCommand *copyUndoRedo = (UndoRedoByCommand*)malloc(sizeof(UndoRedoByCommand));
	copyUndoRedo->undo = createCommand(undoRedoInstance->undo->commandID, undoRedoInstance->copyElement(undoRedoInstance->undo->elementForCommand));
	copyUndoRedo->redo = createCommand(undoRedoInstance->redo->commandID, undoRedoInstance->copyElement(undoRedoInstance->redo->elementForCommand));
	return copyUndoRedo;
}

void addOperationForUndoRedoByCommand(DynamicArray * undoRedoArray, UndoRedoByCommand * operation)
{
	if (!undoRedoArray->isCommingFromUndoRedo)
	{
		while (undoRedoArray->indexForCommandBasedUndo != undoRedoArray->numberOfElements - 1)
			undoRedoArray->destroyElement(popFromDynamicArray(undoRedoArray));
		undoRedoArray->indexForCommandBasedUndo++;
		addElementDynamicArray(undoRedoArray, operation);
	}
}

int undoByCommand(DynamicArray* undoRedoArray, DynamicArray* currentList)
{
	if (undoRedoArray->indexForCommandBasedUndo <= -1)
		return -1;
	undoRedoArray->isCommingFromUndoRedo = 1;
	Command* commandToUndo = ((UndoRedoByCommand*)undoRedoArray->elements[undoRedoArray->indexForCommandBasedUndo])->undo;
	Signal* undoSignal = commandToUndo->elementForCommand;
	if (commandToUndo->commandID == 1)
		addSignal(undoSignal->id,
			undoSignal->modulatedSignal,
			undoSignal->type,
			undoSignal->priorityNumber,
			currentList, undoRedoArray);
	else if (commandToUndo->commandID == 2)
		deleteSignal(undoSignal->id,
			currentList, undoRedoArray);
	else if (commandToUndo->commandID == 3)
		updateSignal(undoSignal->id,
			undoSignal->modulatedSignal,
			undoSignal->type,
			undoSignal->priorityNumber,
			currentList, undoRedoArray);
	undoRedoArray->isCommingFromUndoRedo = 0;
	undoRedoArray->indexForCommandBasedUndo--;
	return 1;
}

int redoByCommand(DynamicArray* undoRedoArray, DynamicArray* currentList)
{
	if (undoRedoArray->indexForCommandBasedUndo >= undoRedoArray->numberOfElements - 1)
		return -1;
	undoRedoArray->isCommingFromUndoRedo = 1;
	Command* commandToRedo = ((UndoRedoByCommand*)undoRedoArray->elements[undoRedoArray->indexForCommandBasedUndo])->redo;
	Signal* redoSignal = commandToRedo->elementForCommand;
	undoRedoArray->indexForCommandBasedUndo++;
	if (commandToRedo->commandID == 1)
		addSignal(redoSignal->id,
			redoSignal->modulatedSignal,
			redoSignal->type,
			redoSignal->priorityNumber,
			currentList, undoRedoArray);
	else if (commandToRedo->commandID == 2)
		deleteSignal(redoSignal->id,
			currentList, undoRedoArray);
	else if (commandToRedo->commandID == 3)
		updateSignal(redoSignal->id,
			redoSignal->modulatedSignal,
			redoSignal->type,
			redoSignal->priorityNumber,
			currentList, undoRedoArray);
	undoRedoArray->isCommingFromUndoRedo = 0;
	return 1;
}

Command * createCommand(int commandID, void * commandParameter)
{
	Command* newCommnad = (Command*)malloc(sizeof(Command));
	newCommnad->commandID = commandID;
	newCommnad->elementForCommand = commandParameter;
	return newCommnad;
}

void destroyCommand(Command * commandToDestroy, void* (*functionToDestroyAnElement)())
{
	functionToDestroyAnElement(commandToDestroy->elementForCommand);
	free(commandToDestroy);
}
