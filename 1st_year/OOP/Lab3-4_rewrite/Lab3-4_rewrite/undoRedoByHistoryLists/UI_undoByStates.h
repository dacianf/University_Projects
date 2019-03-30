#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../Signal.h"
#include "../DynamicArray.h"
#include "Controller.h"

void* UI(DynamicArray* signalsList, DynamicArray* undoRedoList);

void addElementsToSignalsList(DynamicArray* signals, DynamicArray* undoRedoList);

void printSignalsFromArray(DynamicArray *signalsList);