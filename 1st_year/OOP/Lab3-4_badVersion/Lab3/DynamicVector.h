#pragma once
typedef struct {
	void **data;
	int numberOfElements;
	int sizeOfArray;
	int undoRedoIndex;
}DynamicArray;

DynamicArray* createDynamicArray();

DynamicArray* addItemInDynamicArray(DynamicArray *destinationArray, void *item);

DynamicArray * removeElementFromDynamicArray(DynamicArray * array, int index);

void distroyDynamicArray(DynamicArray *array);

void testDynamicArray();