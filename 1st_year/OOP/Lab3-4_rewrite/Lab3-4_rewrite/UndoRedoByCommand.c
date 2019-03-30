#include "UndoRedoByCommand.h"

UndoRedoByCommand * createUndoRedoByCommand(int commandID, void* elementForCommand)
{
	UndoRedoByCommand *newUndoRedo = (UndoRedoByCommand*)malloc(sizeof(UndoRedoByCommand));
	newUndoRedo->commandID = commandID;
	newUndoRedo->elementForCommand = elementForCommand;
	return newUndoRedo;
}

void destroyUndoRedoByCommand(UndoRedoByCommand * undoRedoInstance)
{
	if (undoRedoInstance->elementForCommand != NULL)
		free(undoRedoInstance->elementForCommand);
	free(undoRedoInstance);
}

UndoRedoByCommand * copyUndoRedoByCommand(UndoRedoByCommand *undoRedoInstance)
{
	UndoRedoByCommand *copyUndoRedo = (UndoRedoByCommand*)malloc(sizeof(UndoRedoByCommand));
	copyUndoRedo->commandID = undoRedoInstance->commandID;
	copyUndoRedo->elementForCommand = copySignal(undoRedoInstance->elementForCommand);
	return copyUndoRedo;
}
