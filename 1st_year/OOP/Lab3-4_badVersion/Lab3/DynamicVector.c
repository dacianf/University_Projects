#include "DynamicVector.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
DynamicArray * createDynamicArray(){
	DynamicArray * dynamicArray = (DynamicArray *)malloc(sizeof(DynamicArray));
	dynamicArray->data = NULL;
	dynamicArray->numberOfElements = 0;
	dynamicArray->sizeOfArray = 0;
	dynamicArray->undoRedoIndex = -1;
	return dynamicArray;
}

DynamicArray * addItemInDynamicArray(DynamicArray * destinationArray, void * item){
	if (destinationArray->numberOfElements == 0)
	{
		destinationArray->data = (void **)calloc(100, sizeof(item));
		destinationArray->sizeOfArray = 100;
	}
	else if (destinationArray->numberOfElements == destinationArray->sizeOfArray) {
		destinationArray->numberOfElements = 1 + destinationArray->numberOfElements * 2;
		void **temp = (void **)realloc(destinationArray->data, (destinationArray->sizeOfArray * sizeof(*destinationArray->data)));
		if (temp)
			destinationArray->data = temp;
	}
	destinationArray->data[destinationArray->numberOfElements] = item;
	destinationArray->numberOfElements++;
	destinationArray->undoRedoIndex++;
	return destinationArray;
}

DynamicArray * removeElementFromDynamicArray(DynamicArray * array, int index) {
	if (array->numberOfElements > 0 && index < array->numberOfElements) {
		free(array->data[index]);
		for (int i = index; i < array->numberOfElements - 1; i++)
			array->data[i] = array->data[i + 1];
		array->data[array->numberOfElements] = NULL;
		array->numberOfElements--;	
	}
	return array;
}

void distroyDynamicArray(DynamicArray * array){
	/*for (int i = 0; i < array->sizeOfArray; i++)
		free(array->data[i]);*/
	free(array->data);
	free(array);
}

void testDynamicArray(){
	DynamicArray* vectorel = createDynamicArray();
	int* var1 = (int*)malloc(5 * sizeof(int));
	int* var2 = (int*)malloc(2 * sizeof(int));
	int* var3 = (int*)malloc(8 * sizeof(int));
	addItemInDynamicArray(vectorel, var1);
	assert(vectorel->numberOfElements == 1);
	addItemInDynamicArray(vectorel, var2);
	addItemInDynamicArray(vectorel, var3);
	assert(vectorel->numberOfElements == 3);
	removeElementFromDynamicArray(vectorel, 1);
	assert(vectorel->numberOfElements == 2);
	assert(vectorel->data[1] == var3);
	distroyDynamicArray(vectorel);
}
