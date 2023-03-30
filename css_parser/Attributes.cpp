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
		cout << array[i].GetName() << " " <<
		array[i].GetValue();
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
		if (array[i].GetName().containString(name) != -1) {
			return array[i].GetValue();
		}
	}
	return "";
}

String Attributes::FindValue_by_name(String name) const
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
		if (array[i].GetName().containString(name) != -1) {
			if (i == length) {
				length--;
				return true;
			}
			array[i] = array[length];
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

