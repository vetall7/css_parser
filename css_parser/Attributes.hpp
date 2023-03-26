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
	Single_Attribute GetAttr(size_t index);
	String FindValue(String name);
	int FindSameName(String name);
	void SetValue(size_t index, String value);
	bool remove_element(String name);
};