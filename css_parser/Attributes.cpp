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

