#include "sekcja.hpp"
#include "List.cpp"
Sections::Sections()
{
	selectors_counter = 0;
	attributes_counter = 0;
}

void Sections::Selector_append(String line)
{
	if (selectors_counter == 0) {
		Selectors selc;
		selc.append(line);
		selectors.push_back(selc);
		selectors_counter++;
	}
	else if (selectors[selectors_counter-1].GetSize() == 8) {
		Selectors temp;
		temp.append(line);
		selectors.push_back(temp);
		selectors_counter++;
	}
	else {
		selectors[selectors_counter-1].append(line);
	}
}

void Sections::Attribute_append(String name, String value)
{
	if (attributes_counter == 0) {
		Attributes attr;
		attr.append(name, value);
		attributes.push_back(attr);
		attributes_counter++;
	}
	else if (attributes[attributes_counter - 1].GetSize() == 8) {
		Attributes temp;
		temp.append(name, value);
		attributes.push_back(temp);
		attributes_counter++;
	}
	else {
		attributes[attributes_counter - 1].append(name, value);
	}
}

void Sections::PrintSelectors()
{
	selectors[selectors_counter - 1].Print();
}

void Sections::PrintAttributes()
{
	attributes[attributes_counter - 1].Print();
}
