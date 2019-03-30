#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../Signal.h"
#include "../DynamicArray.h"
#include "Controller_UndoByCommand.h"
#include "UndoRedoByCommand.h"

void* UI(DynamicArray* signalsList, DynamicArray* undoList, DynamicArray* redoList);

void addElementsToSignalsList(DynamicArray * signals, DynamicArray * undoList, DynamicArray * redoList);

void printSignalsFromArray(DynamicArray *signalsList);