#pragma once
#include "Attributes.h"
#include "Selectors.h"
#include "Single_list.h"
#include "Single_list.cpp"
class Section {
private:
	single1_list<Selectors>  selectors;
	single1_list<Attributes> attributes;
	size_t selectors_counter;
	size_t attributes_counter;
public:
	Section();
	void Selector_append(String line);
	void Attribute_append(String name, String value);
	void New_selector(String str);
	void New_attribute(String str);
	size_t GetSelectorsCounter() ;
	size_t GetAttributesCounter();
	String GetSelector(size_t index) ;
	String GetAttributeValue(String name);
	bool is_attribute_exists(String name);
	bool is_selector_exists(String name);
	void remove();
	bool removeAttribute(String name);
	Section(const Section& other);
	Section& operator=(const Section& other);
};

