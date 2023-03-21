#pragma once
#include "string.h"

class Atr {
	String name;
	String value;
};


class Attributes {
private:
	Atr* array = new Atr[8];
	size_t length;
	Attributes* next;
public:

};