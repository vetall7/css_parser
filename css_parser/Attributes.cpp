#include "Attributes.h"

Attributes::Attributes()
{
	length = 0;
}

size_t Attributes::GetSize()
{
	return length;
}

void Attributes::Print() const
{
	for (int i = 0; i < length; i++) {
		array[i].GetName().Print();
		array[i].GetValue().Print() ;
	}
}

void Attributes::append(String name, String value)
{
	Single_Attribute temp(name, value);
	array[length] = temp;
	length++;
}

Single_Attribute Attributes::GetAttr(size_t index) const
{
	return array[index];
}

String Attributes::FindValue(String name) const
{
	for (int i = 0; i < length; i++) {
		if (array[i].GetName() == name) {
			return array[i].GetValue();
		}
	}
	return "";
}

int Attributes::FindSameName(String name) const
{
	for (int i = 0;i < length; i++) {
		if (array[i].GetName() == name) {
			return i;
		}
	}
	return -1;
}


void Attributes::SetValue(size_t index, String value)
{
	array[index].SetValue(value);
}

bool Attributes::remove_element(String name)
{
	for (int i = 0; i < length; i++) {
		if (array[i].GetName() == name) {
			for (int j = i; j < length; j++) { 
				array[j] = array[j + 1];
			}
			length--;
			return true;
		}
	}
	return false;
}

Attributes::Attributes(const Attributes& other) {
	length = other.length;
	for (size_t i = 0; i < length; i++) {
		array[i] = other.array[i];
	}
}

Attributes& Attributes::operator=(const Attributes& other) {
	if (this != &other) {
		// Copy the data members from the other object
		length = other.length;
		for (size_t i = 0; i < length; i++) {
			array[i] = other.array[i];
		}
	}
	return *this;
}

