#pragma once
#include <stdlib.h>

typedef struct {
	void **elements;
	int numberOfElements;
	int capacity;
	int undoRedoIndex;
	void* (*createElement)();
	void* (*copyElement)();
	void* (*compareElements)();
	void* (*destroyElement)();
}DynamicArray;

DynamicArray* createDynamicArray(int elementSize, void *createElement, void *destroyElement, void *copyElements, void *compareElements);

void destroyDynamicArray(DynamicArray *arrayTodestroy);

void addElementDynamicArray(DynamicArray *dynamicArray, void* element);

void removeElementDynamicArray(DynamicArray *dynamicArray, void* element);

int updateElementDynamicArray(DynamicArray *dynamicArray, void* newElement);

void* findElementFromDynamicArray(DynamicArray *dynamicArray, void *element);

void * topOfDynamicArray(DynamicArray * dynamicArray);

void* popFromDynamicArray(DynamicArray *dynamicArray);

DynamicArray* createCopyOfDynamicArray(DynamicArray* dynamicArrayToCopy);

int compareTwoDynamicArrays(DynamicArray* firstArray, DynamicArray* secondArray);