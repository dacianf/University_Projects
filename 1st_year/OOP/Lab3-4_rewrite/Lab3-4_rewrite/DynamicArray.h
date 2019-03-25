#pragma once
#include <stdlib.h>

typedef struct {
	void **elements;
	int numberOfElements;
	int capacity;
	void* (*createElement)();
	void* (*copyElement)();
	void* (*compareElements)();
	void* (*distroyElement)();
}DynamicArray;

DynamicArray* createDynamicArray(int elementSize, void *createElement, void *distoryElement, void *copyElements, void *compareElements);

void distoryDynamicArray(DynamicArray *arrayToDistroy);

void addElementDynamicArray(DynamicArray *dynamicArray, void* element);

void removeElementDynamicArray(DynamicArray *dynamicArray, void* element);
