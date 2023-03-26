#include "Attributes.hpp"

Attributes::Attributes()
{
	length = 0;
}

size_t Attributes::GetSize()
{
	return length;
}

void Attributes::Print()
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

Single_Attribute Attributes::GetAttr(size_t index)
{
	return array[index];
}

String Attributes::FindValue(String name)
{
	for (int i = 0; i < length; i++) {
		if (array[i].GetName() == name) {
			return array[i].GetValue();
		}
	}
	return "";
}

int Attributes::FindSameName(String name)
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

