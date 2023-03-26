#include "Selectors.hpp"

Selectors::Selectors()
{
	length = 0;
}

void Selectors::append(String line)
{
	array[length] = line;
	length++;
}

String Selectors::GetElement(int index)
{
	return array[index];
}

bool Selectors::HasElement(String name)
{
	for (int i = 0; i < length; i++) {
		if (array[i] == name) {
			return true;
		}
	}
	return false;
}

void Selectors::Print()
{
	for (int i = 0; i < length; i++) {
		array[i].Print();
	}
}

size_t Selectors::GetSize() {
	return length;
}