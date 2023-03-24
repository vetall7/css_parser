#pragma once
#include "string.hpp"

class Selectors {
private:
	String array[8];
	size_t length;
public:
	Selectors();
	size_t GetSize();
	void Print();
	void append (String line);
	String GetElement(int index);
};