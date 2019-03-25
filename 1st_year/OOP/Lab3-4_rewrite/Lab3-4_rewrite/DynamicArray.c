#include "DynamicArray.h"

DynamicArray * createDynamicArray(int elementSize, void * createElement, void * distoryElement, void * copyElements, void * compareElements)
{
	/*
			Creats a dynamic array which can contain pointers to any kind of elements as long
		as they are of the same type
		Input:
			elementSize - integer
			createElement - pointer to a function that can create the element
			copyElements - pointer to a function that gives a pointer to a copy of an element
			compareElements - pointer to a function that compares to elements
			distroyElement - pointer to a function that can distroy given element
	*/
	DynamicArray* newDynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	newDynamicArray->elements = (void **)malloc(100 * elementSize);
	newDynamicArray->capacity = 100;
	newDynamicArray->numberOfElements = 0;
	newDynamicArray->compareElements = compareElements;
	newDynamicArray->copyElement = copyElements;
	newDynamicArray->createElement = createElement;
	newDynamicArray->distroyElement = distoryElement;
	return newDynamicArray;
}

void distoryDynamicArray(DynamicArray * arrayToDistroy)
{
	/*
		Distroy the given array
		Input:
			arrayToDistroy - pointer to array
	*/
	for (int i = 0; i < arrayToDistroy->numberOfElements; i++) {
		arrayToDistroy->distroyElement(arrayToDistroy->elements[i]);
	}
	free(arrayToDistroy->elements);
	free(arrayToDistroy);
}

void removeElementDynamicArray(DynamicArray * dynamicArray, void * elementToRemove)
{
	/*
		Removes a given element from dynamicArray
		Input:
			dynamicArray - dynamicArray from which the element will be removed
			elementToRemove - pointer to element that will be removed
	*/
	for (int i = 0; i < dynamicArray->numberOfElements; i++)
		if (dynamicArray->compareElements(dynamicArray->elements[i], elementToRemove) == 0) {
			dynamicArray->distroyElement(dynamicArray->elements[i]);
			if (dynamicArray->numberOfElements - 1 != i)
				dynamicArray->elements[i] = dynamicArray->elements[dynamicArray->numberOfElements - 1];
			dynamicArray->elements[dynamicArray->numberOfElements - 1] = NULL;
			dynamicArray->numberOfElements--;
			break;
		}
}

void resizeDynamicArray(DynamicArray * arrayToResize) {
	/*
		Resize the given dynamic array by 100 units
		Input:
			arrayToResize - pointer to dynamic array that will be resized
	*/
	void** resizedLocationForElements = (void**)malloc((arrayToResize->capacity + 100)*sizeof(arrayToResize->elements[0]));
	for (int i = 0; i < arrayToResize->numberOfElements; i++) {
		resizedLocationForElements[i] = arrayToResize->elements[i];
	}
	free(arrayToResize->elements);
	arrayToResize->elements = resizedLocationForElements;
	arrayToResize->capacity += 100;
}

void addElementDynamicArray(DynamicArray * dynamicArray, void * element)
{
	/*
		Adds the given element's address into the dynamic array
		Input:
			dynamicArray - pointer to array
			element - pointer to element that will be add
	*/
	if (dynamicArray->numberOfElements == dynamicArray->capacity)
		resizeDynamicArray(dynamicArray);
	dynamicArray->elements[dynamicArray->numberOfElements] = dynamicArray->copyElement(element);
	dynamicArray->numberOfElements++;
}