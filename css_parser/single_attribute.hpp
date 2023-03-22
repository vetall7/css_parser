#pragma once
#include "string.hpp"

class Single_Attribute {
	String name;
	String value;
public:
	Single_Attribute(String name, String value);
	void SetName(String name);
	void SetValue(String value);
	Single_Attribute();
	String GetName();
	String GetValue();
};
