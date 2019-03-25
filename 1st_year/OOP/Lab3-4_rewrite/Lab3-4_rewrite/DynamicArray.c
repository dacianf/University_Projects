#include "DynamicArray.h"

DynamicArray * createDynamicArray(int elementSize, void * createElement, void * destroyElement, void * copyElements, void * compareElements)
{
	/*
			Creats a dynamic array which can contain pointers to any kind of elements as long
		as they are of the same type
		Input:
			elementSize - integer
			createElement - pointer to a function that can create the element
			copyElements - pointer to a function that gives a pointer to a copy of an element
			compareElements - pointer to a function that compares to elements
			destroyElement - pointer to a function that can destroy given element
	*/
	DynamicArray* newDynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	newDynamicArray->elements = (void **)malloc(100 * elementSize);
	newDynamicArray->capacity = 100;
	newDynamicArray->numberOfElements = 0;
	newDynamicArray->compareElements = compareElements;
	newDynamicArray->copyElement = copyElements;
	newDynamicArray->createElement = createElement;
	newDynamicArray->destroyElement = destroyElement;
	return newDynamicArray;
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

void destroyDynamicArray(DynamicArray * arrayTodestroy)
{
	/*
		destroy the given array
		Input:
			arrayTodestroy - pointer to array
	*/
	for (int i = 0; i < arrayTodestroy->numberOfElements; i++) {
		arrayTodestroy->destroyElement(arrayTodestroy->elements[i]);
	}
	free(arrayTodestroy->elements);
	free(arrayTodestroy);
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
			dynamicArray->destroyElement(dynamicArray->elements[i]);
			if (dynamicArray->numberOfElements - 1 != i)
				dynamicArray->elements[i] = dynamicArray->elements[dynamicArray->numberOfElements - 1];
			dynamicArray->elements[dynamicArray->numberOfElements - 1] = NULL;
			dynamicArray->numberOfElements--;
			break;
		}
}

int updateElementDynamicArray(DynamicArray * dynamicArray, void * newElement){
	/*
		Updates an element from given dinamy array if it exists
		Input:
			dynamicArray - pointer to dynamicArray in which the element with
						the same id as newElement will be modified
			newElement - pointer to the element that will replace the existing element with its id
		Output:
			1 - if operation succeds
			0 - otherwise
	*/
	for (int i = 0; i < dynamicArray->numberOfElements; i++)
		if (dynamicArray->compareElements(dynamicArray->elements[i], newElement) == 0) {
			dynamicArray->destroyElement(dynamicArray->elements[i]);
			dynamicArray->elements[i] = dynamicArray->copyElement(newElement);
			return 1;
		}
	return 0;
}

void* findElementFromDynamicArray(DynamicArray * dynamicArray, void * element)
{
	/*
		Tries to find given element inside given array and returns a pointer to its location
		Input:
			dynamicArray - pointer to the dynamicArray in which element is searched
			element - pointer to the element user wants to find
		Output:
			pointer - to element location
			null pointer - if element is not found
	*/
	for(int i=0;i<dynamicArray->numberOfElements;i++)
		if (dynamicArray->compareElements(dynamicArray->elements[i], element) == 0) {
			return dynamicArray->elements[i];
			break;
		}
	return NULL;
}

DynamicArray * createCopyOfDynamicArray(DynamicArray * dynamicArrayToCopy)
{
	/*
		Creats a copy of given array and retruns a pointer to it
		Input:
			dynamicArrayToCopy - pointer to dynamic array that will be copied
		Output:
			copyOfGivenArray - pointer to dynamicArrayToCopy's copy
	*/
	DynamicArray *copyOfGivenArray = createDynamicArray(sizeof(dynamicArrayToCopy->elements[0]),
		dynamicArrayToCopy->createElement, dynamicArrayToCopy->destroyElement,
		dynamicArrayToCopy->copyElement, dynamicArrayToCopy->compareElements);
	while (copyOfGivenArray->capacity < dynamicArrayToCopy->capacity)
		resizeDynamicArray(copyOfGivenArray);
	for (copyOfGivenArray->numberOfElements; copyOfGivenArray->numberOfElements < dynamicArrayToCopy->numberOfElements; copyOfGivenArray->numberOfElements++)
		copyOfGivenArray->elements[copyOfGivenArray->numberOfElements] = copyOfGivenArray->copyElement(dynamicArrayToCopy->elements[copyOfGivenArray->numberOfElements]);
	return copyOfGivenArray;
}

void addElementDynamicArray(DynamicArray * dynamicArray, void * element)
{
	/*
		Adds the given element's address into the dynamic array
		Input:
			dynamicArray - pointer to array
			element - pointer to the element that will be added
	*/
	if (dynamicArray->numberOfElements == dynamicArray->capacity)
		resizeDynamicArray(dynamicArray);
	dynamicArray->elements[dynamicArray->numberOfElements] = dynamicArray->copyElement(element);
	dynamicArray->numberOfElements++;
}