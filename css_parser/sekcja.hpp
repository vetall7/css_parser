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
};

