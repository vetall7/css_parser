#pragma once
#include "Attributes.h"
#include "Selectors.h"
#include "Single_list.h"
#include "Single_list.cpp"
class Sections {
private:
	single1_list<Selectors>  selectors;
	single1_list<Attributes> attributes;
	size_t selectors_counter;
	size_t attributes_counter;
public:
	Sections();
	void Selector_append(String line);
	void Attribute_append(String name, String value);
	void PrintSelectors() ;
	void PrintAttributes() ;
	void New_selector(String str);
	void New_attribute(String str);
	int GetSelectorsCounter() ;
	int GetAttributesCounter();
	String GetSelector(int index) ;
	String GetAttributeValue(String name);
	bool is_attribute_exists(String name);
	bool is_selector_exists(String name);
	void remove();
	bool removeAttribute(String name);
	Sections(const Sections& other);
	Sections& operator=(const Sections& other);
};

