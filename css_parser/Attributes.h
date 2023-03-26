#pragma once
#include "string.h"
#include "single_attribute.h"


class Attributes {
private:
	Single_Attribute array[8];
	size_t length;
public:
	Attributes();
	size_t GetSize();
	void Print() const;
	void append(String name, String value);
	Single_Attribute GetAttr(size_t index) const;
	String FindValue(String name) const;
	int FindSameName(String name) const;
	void SetValue(size_t index, String value);
	bool remove_element(String name);
	Attributes(const Attributes& other);
	Attributes& operator=(const Attributes& other);
};