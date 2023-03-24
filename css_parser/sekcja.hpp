#pragma once
#include "Attributes.hpp"
#include "Selectors.hpp"
#include "List.hpp"

class Sections {
private:
	list<Selectors>  selectors;
	list<Attributes> attributes;
	size_t selectors_counter;
	size_t attributes_counter;
public:
	Sections();
	void Selector_append(String line);
	void Attribute_append(String name, String value);
	void PrintSelectors();
	void PrintAttributes();
	void New_selector(String str);
	void New_attribute(String str);
	int GetSelectorsCounter();
	int GetAttributesCounter();
	String GetSelector(int index);
	String GetSttributeValue(String name);
	/*bool is_empty();
	void copy_attributes(Sections sec);*/
};

