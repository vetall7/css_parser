#include "sekcja.hpp"
#include "List.cpp"
#include <iostream>
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

void Sections::New_selector(String str)
{
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			if (index == 0) {
				Selector_append(str.cut(index, i));
			}
			else {
				Selector_append(str.cut(index + 1, i));
			}
			index = i;
		}
	}
	size_t count = 0;
	if (index != 0) {
		count = 1;
	}
	Selector_append(str.cut(index + count, str.size()));
}

void Sections::New_attribute(String str)
{
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ':') {
			Attribute_append(str.cut(0, i), str.cut(i + 1, str.size()));
		}
	}
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
	selectors[index / 8].GetElement(index % 8);
	return 0;
}

String Sections::GetSttributeValue(String name)
{
	for (int i = 0; i < attributes_counter; i++) {
		if ( !(attributes[i].FindValue(name) == "")) {
			return attributes[i].FindValue(name);
		}
	}
	return String();
}

//bool Sections::is_empty()
//{
//	if (selectors_counter == 0) {
//		return true;
//	}
//	return false;
//}

//void Sections::copy_attributes(Sections sec)
//{
//	//for (int j = 0; j <= sec.attributes_counter; j++) {
//		//for (int i = 0; i < 1; i++) {
//			//Attribute_append(sec.attributes[0].GetAttr(0), sec.attributes[0].GetAttr(0));
//		//}
//		//cout << "asdf";
//	//}
//}
