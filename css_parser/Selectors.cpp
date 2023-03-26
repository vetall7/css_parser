#include "Selectors.h"

Selectors::Selectors()
{
	length = 0;
}

void Selectors::append(String line)
{
	array[length] = line;
	length++;
}

String Selectors::GetElement(int index) const
{
	return array[index];
}

bool Selectors::HasElement(String name) const
{
	for (int i = 0; i < length; i++) {
		if (array[i] == name) {
			return true;
		}
	}
	return false;
}

Selectors::Selectors(const Selectors& other) {
	this->length = other.length;
	for (size_t i = 0; i < this->length; i++) {
		this->array[i] = other.array[i];
	}
}


void Selectors::Print() const
{
	for (int i = 0; i < length; i++) {
		array[i].Print();
	}
}

size_t Selectors::GetSize()  const {
	return length;
}

Selectors& Selectors::operator=(const Selectors& other) {
	if (this == &other) {
		return *this;
	}

	for (size_t i = 0; i < length; i++) {
		array[i] = "";
	}
	length = 0;

	for (size_t i = 0; i < other.length; i++) {
		append(other.array[i]);
	}

	return *this;
}

