#include "sekcja.h"
#include <iostream>
Sections::Sections()
{
	selectors_counter = 0;
	attributes_counter = 0;
}

void Sections::Selector_append(String line)
{
	for (int i = 0; i < selectors_counter; i++) {
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

void Sections::New_selector(String str)
{
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
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
				//cout << str.cut(index, k);
			}
			else {
				while (str[index + 1] == ' ') {
					index++;
				}
				while (str[k-1] == ' ') {
					k--;
				}
				//cout << str.cut(index + 1, k);
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
	//cout << str.cut(index + count, temp);
	Selector_append(str.cut(index + count, temp));
}

void Sections::New_attribute(String str)
{
	String name, value;
	for (int i = 0; i < str.size(); i++) {
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
			//cout << value;
			break;
		}
	}
	name.remove_spaces();
	for (int i = 0; i < attributes_counter; i++) {
		int index = attributes[i].FindSameName(name);
		if (index != -1){
			attributes[i].SetValue(index, value);
			return;
		}
	}
	//cout << name << endl;
	Attribute_append(name, value);
}


int Sections::GetSelectorsCounter()
{
	return ((selectors_counter-1) * 8 + selectors[selectors_counter-1].GetSize());
}

int Sections::GetAttributesCounter() 
{
	return ((attributes_counter - 1) * 8 + attributes[attributes_counter - 1].GetSize());
}

String Sections::GetSelector(int index) 
{
	return selectors[index / 8].GetElement(index % 8);
}

String Sections::GetAttributeValue(String name) 
{
	for (int i = 0; i < attributes_counter; i++) {
		String temp = attributes[i].FindValue_by_name(name);
		if ( !(temp == "")) {
			return temp;
		}
	}
	return "";
}

bool Sections::is_attribute_exists(String name) 
{
	for (int i = 0; i < attributes_counter; i++) {
		if (attributes[i].FindSameName(name) != -1) {
			return true;
		}
	}
	return false;
}

bool Sections::is_selector_exists(String name) 
{
	for (int i = 0; i < selectors.GetSize(); i++) {
		if (selectors[i].HasElement(name)) {
			return true;
		}
	}
	return false;
}

void Sections::remove()
{
	selectors.clear();
	attributes.clear();
}

bool Sections::removeAttribute(String name)
{
	for (int i = 0; i < attributes_counter; i++) {
		if (attributes[i].remove_element(name)) {
			return true;
		}
	}
	return false;
}

Sections::Sections(const Sections& other)
	: selectors(other.selectors), attributes(other.attributes),
	selectors_counter(other.selectors_counter),
	attributes_counter(other.attributes_counter)
{
}

Sections& Sections::operator=(const Sections& other)
{
	attributes = other.attributes;
	selectors_counter = other.selectors_counter;
	attributes_counter = other.attributes_counter;
	return *this;
}
