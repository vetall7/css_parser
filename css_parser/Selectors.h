#pragma once
#include "string.h"

class Selectors {
private:
	String array[8];
	size_t length;
public:
	Selectors();
	size_t GetSize() const;
	void Print() const;
	void append (String line);
	String GetElement(int index) const;
	bool HasElement(String name) const;
	Selectors(const Selectors& other);
	Selectors& operator=(const Selectors& other);
};
