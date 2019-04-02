#pragma once
#include <string>
#include <cstdlib>

template <typename TemplateForDynamicArray>
class DynamicArray
{
private:
	TemplateForDynamicArray* elements;
	int size;
	int capacity;
public:
	//constructor
	DynamicArray(int capacity = 10);
	//copy constructor
	DynamicArray(const DynamicArray& copyOfDynamicArray);
	//destructor
	~DynamicArray();

	int getCapacity() const{ return this->capacity; }
	int getSize() const { return this->size; }

	void addElement(TemplateForDynamicArray element);
	TemplateForDynamicArray insertElement(int position, TemplateForDynamicArray element);
	TemplateForDynamicArray getElementFromPosition(int position) const;
	int findElement(TemplateForDynamicArray element) const;
	void removeElement(TemplateForDynamicArray element);
	void removeFromIndex(int index);
	//std::string toString();
	TemplateForDynamicArray& operator [](int index);
	void operator =(TemplateForDynamicArray& newArray) {
		this = DynamicArray<TemplateForDynamicArray>(newArray);
	}
private:
	//resize the dynamic array by factor times
	void resize(double factor = 2);
};

template<typename TemplateForDynamicArray>
DynamicArray<TemplateForDynamicArray>::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new TemplateForDynamicArray[this->capacity];
}

template<typename TemplateForDynamicArray>
DynamicArray<TemplateForDynamicArray>::DynamicArray(const DynamicArray & copyOfDynamicArray)
{
	this->size = copyOfDynamicArray.size;
	this->capacity = copyOfDynamicArray.capacity;
	this->elements = new TemplateForDynamicArray[this->capacity];
	for (int i = 0; i < this->capacity; i++)
		this->elements[i] = copyOfDynamicArray.elements[i];
}

template <typename TemplateForDynamicArray>
DynamicArray<TemplateForDynamicArray>::~DynamicArray()
{
	delete[] this->elements;
	this->size = 0;
	this->capacity = 0;
}

template<typename TemplateForDynamicArray>
void DynamicArray<TemplateForDynamicArray>::addElement(TemplateForDynamicArray element)
{
	if (this->capacity == this->size + 1)
		resize();
	this->elements[this->size++] = element;
}

template<typename TemplateForDynamicArray>
TemplateForDynamicArray DynamicArray<TemplateForDynamicArray>::insertElement(int position, TemplateForDynamicArray element)
{
	if (position >= this->capacity) {
		std::string message = { "Position must be less then " };
		message += itoa(this->capacity);
		throw message.c_str();
	}
	TemplateForDynamicArray elementReplaced = this->elements[position];
	this->elements[position] = element;
	return elementReplaced;
}

template<typename TemplateForDynamicArray>
TemplateForDynamicArray DynamicArray<TemplateForDynamicArray>::getElementFromPosition(int position) const
{
	if (position >= this->capacity) {
		std::string message = { "Position must be less then " };
		message += itoa(this->capacity);
		throw message.c_str();
	}
	return this->elements[position];
}

template<typename TemplateForDynamicArray>
int DynamicArray<TemplateForDynamicArray>::findElement(TemplateForDynamicArray element) const
{
	for (int i = 0; i < this->size; i++)
		if (this->elements[i] == element)
			return i;
	return -1;
}

template<typename TemplateForDynamicArray>
void DynamicArray<TemplateForDynamicArray>::removeElement(TemplateForDynamicArray element)
{
	int elementsPosition = this->findElement(element);
	if (!elementsPosition)
		throw"The element you want to remove does not exist!";
	this->removeFromIndex(elementsPosition);
}

template<typename TemplateForDynamicArray>
void DynamicArray<TemplateForDynamicArray>::removeFromIndex(int index)
{
	if (index >= this->capacity) {
		std::string message = { "Index must be less then " };
		char sizeAsString[20];
		_itoa_s(this->capacity, sizeAsString, 19, 10);
		message += sizeAsString;
		throw message.c_str();
	}
	this->elements[index] = this->elements[this->size-- - 1];
}

//template<typename TemplateForDynamicArray>
//inline std::string DynamicArray<TemplateForDynamicArray>::toString()
//{
//	std::string arrayAsString;
//	for (int i = 0; i < this->size; i++)
//		arrayAsString += this->elements[i] + "\n";
//	return arrayAsString;
//}

template<typename TemplateForDynamicArray>
void DynamicArray<TemplateForDynamicArray>::resize(double factor)
{
	this->capacity *= factor;
	TemplateForDynamicArray* elementsSpaceResized = new TemplateForDynamicArray[this->capacity];
	for (int i = 0; i < this->size; i++)
		elementsSpaceResized[i] = this->elements[i];
	delete[] this->elements;
	this->elements = elementsSpaceResized;
}
template<typename TemplateForDynamicArray>
TemplateForDynamicArray& DynamicArray<TemplateForDynamicArray>::operator [](int index) {
	if (index >= this->capacity) {
		std::string message = { "Index must be less then " };
		char sizeAsString[20];
		_itoa_s(this->capacity, sizeAsString, 19, 10);
		message += sizeAsString;
		throw message.c_str();
	}
	return this->elements[index];
}


