#pragma once
#include "string.hpp"
#include "single_attribute.hpp"


class Attributes {
private:
	Single_Attribute array[8];
	size_t length;
public:
	Attributes();
	size_t GetSize();
	void Print();
	void append(String name, String value);
};