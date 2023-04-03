#pragma once
#include "string.h"
#define ARRAY_SIZE 8
class Selectors {
private:
	String array[ARRAY_SIZE];
	size_t length;
public:
	Selectors();
	size_t GetSize() const;
	void Print() const;
	void append (String line);
	String GetElement(size_t index) const;
	bool HasElement(String name) const;
	Selectors(const Selectors& other);
	Selectors& operator=(const Selectors& other);
};
