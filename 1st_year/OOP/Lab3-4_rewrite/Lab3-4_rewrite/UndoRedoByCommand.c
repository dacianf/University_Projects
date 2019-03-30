#include "UndoRedoByCommand.h"

UndoRedoByCommand * createUndoRedoByCommand()
{
	UndoRedoByCommand *newUndoRedo = (UndoRedoByCommand*)malloc(sizeof(UndoRedoByCommand));
	newUndoRedo->commandID = 0;
	newUndoRedo->signalForCommand = NULL;
	return newUndoRedo;
}

void destroyUndoRedoByCommand(UndoRedoByCommand * undoRedoInstance)
{
	if (undoRedoInstance->signalForCommand != NULL)
		free(undoRedoInstance->signalForCommand);
	free(undoRedoInstance);
}

UndoRedoByCommand * copyUndoRedoByCommand(UndoRedoByCommand *undoRedoInstance)
{
	UndoRedoByCommand *copyUndoRedo = (UndoRedoByCommand*)malloc(sizeof(UndoRedoByCommand));
	copyUndoRedo->commandID = undoRedoInstance->commandID;
	copyUndoRedo->signalForCommand = copySignal(undoRedoInstance->signalForCommand);
	return copyUndoRedo;
}
