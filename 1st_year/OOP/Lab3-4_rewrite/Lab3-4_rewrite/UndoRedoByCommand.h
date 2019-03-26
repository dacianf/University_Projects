#pragma once
#ifndef DYNAMICARRAY_H
#include "DynamicArray.h"
#ifndef SIGNAL_H
#include "Signal.h"


typedef struct {
	int commandID;
	Signal *signalForCommand;
}UndoRedoByCommand;

#endif // !SIGNAL_H
#endif // !DYNAMICARRAY_H
