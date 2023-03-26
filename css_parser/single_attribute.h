#pragma once
#include "string.h"

class Single_Attribute {
	String name;
	String value;
public:
	Single_Attribute(String name, String value);
	void SetName(String name);
	void SetValue(String value);
	Single_Attribute();
	String GetName() const;
	String GetValue() const;
	Single_Attribute(const Single_Attribute& other);
	Single_Attribute& operator=(const Single_Attribute& other);
};
