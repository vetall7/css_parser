#include "single_Attribute.hpp"

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

String Single_Attribute::GetName()
{
	return name;
}

String Single_Attribute::GetValue()
{
	return value;
}
