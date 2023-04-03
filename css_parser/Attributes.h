#pragma once
#include "string.h"
#include "single_attribute.h"
#define ARRAY_SIZE 8

class Attributes {
private:
	Single_Attribute array[ARRAY_SIZE];
	size_t length;
public:
	Attributes();
	size_t GetSize() const;
	void Print() const;
	void append(String name, String value);
	String FindValue_by_name(String name) const;
	int FindSameName(String name) const;
	void SetValue(size_t index, String value);
	bool remove_element(String name);
	Attributes(const Attributes& other);
	Attributes& operator=(const Attributes& other);
};