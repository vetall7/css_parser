#include "single_Attribute.h"

Single_Attribute::Single_Attribute(String name, String value)
{
	this->name = name;
	this->value = value;
}

void Single_Attribute::SetName(String name)
{
	this->name = name;
}

void Single_Attribute::SetValue(String value)
{
	this->value = value;
}

Single_Attribute::Single_Attribute()
{
	name = "";
	value = "";
}

String Single_Attribute::GetName() const
{
	return name;
}

String Single_Attribute::GetValue() const
{
	return value;
}

Single_Attribute::Single_Attribute(const Single_Attribute& other) {
	name = other.name;
	value = other.value;
}

Single_Attribute& Single_Attribute::operator=(const Single_Attribute& other) {
	if (this != &other) {
		name = other.name;
		value = other.value;
	}
	return *this;
}
