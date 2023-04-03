#include "sekcja.h"
#include <iostream>
Section::Section()
{
	selectors_counter = 0;
	attributes_counter = 0;
}

void Section::Selector_append(String line)
{
	for (size_t i = 0; i < selectors_counter; i++) {
			if (selectors[i].HasElement(line)) {
				return;
			}
	}
	if (selectors_counter == 0) {
		Selectors selc;
		selc.append(line);
		selectors.push_back(selc); 
		selectors_counter++;
	}
	else if (selectors[selectors_counter-1].GetSize() == ARRAY_SIZE) {
		Selectors temp;
		temp.append(line);
		selectors.push_back(temp);
		selectors_counter++;
	}
	else {
		selectors[selectors_counter-1].append(line); 
	}
}

void Section::Attribute_append(String name, String value)
{
	if (attributes_counter == 0) {
		Attributes attr;
		attr.append(name, value);
		attributes.push_back(attr);
		attributes_counter++;
	}
	else if (attributes[attributes_counter - 1].GetSize() == ARRAY_SIZE) {
		Attributes temp;
		temp.append(name, value);
		attributes.push_back(temp);
		attributes_counter++;
	}
	else {
		attributes[attributes_counter - 1].append(name, value);
	}
}

void Section::New_selector(String str)
{
	size_t index = 0;
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			int k = i;
			if (index == 0) {
				while (str[index] == ' ') {
					index++;
				}
				while (str[k-1] == ' ') {
					k--;
				}
				Selector_append(str.cut(index, k));
			}
			else {
				while (str[index + 1] == ' ') {
					index++;
				}
				while (str[k-1] == ' ') {
					k--;
				}
				Selector_append(str.cut(index + 1, k));
			}
			index = i;
		}
	}
	size_t count = 0;
	if (index != 0) {
		count = 1;
	}
	while (str[index+1] == ' ') {
		index++;
	}
	int temp = str.size() - 1;
	while (str[temp -1 ] == ' ') {
		temp--;
	}
	Selector_append(str.cut(index + count, temp));
}

void Section::New_attribute(String str)
{
	String name, value;
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == ':') {
			name = str.cut(0, i);
			while (str[i+1] == ' ') {
				i++;
			}
			int k = -1;
			while (str[str.size() + k-1] == ' ') {
				k--;
			}
			value = str.cut(i + 1, str.size() + k);
			break;
		}
	}
	name.remove_spaces();
	for (size_t i = 0; i < attributes_counter; i++) {
		size_t index = attributes[i].FindSameName(name);
		if (index != -1){
			attributes[i].SetValue(index, value);
			return;
		}
	}
	Attribute_append(name, value);
}


size_t Section::GetSelectorsCounter()
{
	return ((selectors_counter-1) * ARRAY_SIZE + selectors[selectors_counter-1].GetSize());
}

size_t Section::GetAttributesCounter() 
{
	return ((attributes_counter - 1) * ARRAY_SIZE + attributes[attributes_counter - 1].GetSize());
}

String Section::GetSelector(size_t index) 
{
	return selectors[index / ARRAY_SIZE].GetElement(index % ARRAY_SIZE);
}

String Section::GetAttributeValue(String name) 
{
	for (size_t i = 0; i < attributes_counter; i++) {
		String temp = attributes[i].FindValue_by_name(name);
		if ( !(temp == "")) {
			return temp;
		}
	}
	return "";
}

bool Section::is_attribute_exists(String name) 
{
	for (size_t i = 0; i < attributes_counter; i++) {
		if (attributes[i].FindSameName(name) != -1) {
			return true;
		}
	}
	return false;
}

bool Section::is_selector_exists(String name) 
{
	for (size_t i = 0; i < selectors.GetSize(); i++) {
		if (selectors[i].HasElement(name)) {
			return true;
		}
	}
	return false;
}

void Section::remove()
{
	selectors.clear();
	attributes.clear();
}

bool Section::removeAttribute(String name)
{
	for (size_t i = 0; i < attributes_counter; i++) {
		if (attributes[i].remove_element(name)) {
			return true;
		}
	}
	return false;
}

Section::Section(const Section& other)
	: selectors(other.selectors), attributes(other.attributes),
	selectors_counter(other.selectors_counter),
	attributes_counter(other.attributes_counter)
{
}

Section& Section::operator=(const Section& other)
{
	attributes = other.attributes;
	selectors_counter = other.selectors_counter;
	attributes_counter = other.attributes_counter;
	return *this;
}
