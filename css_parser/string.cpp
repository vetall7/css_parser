#include  "string.hpp"

#include <iostream>
using namespace std;

char& String::operator[](int i) {
	return str[i];    
}

void String::append(const char a)
{
	char *str2 = new char[length + 2];
	for (int i = 0; i < length; i++) {
		str2[i] = str[i];
	} 
	str2[length] = a;
	str2[length + 1] = '\0';
	length++;
	delete[]str;
	str = str2;
}


bool String::operator==(const String& other) {
	if (this->length != other.length) {
		return false;
	}
	else {
		for (int i = 0; i < length; i++) {
			if (str[i] != other.str[i]) {
				return false;
			}
		}
	}
	return true;
}

int String::size() {
	return length;
}


String::String(const String& other)
{
	length = other.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		str[i] = other.str[i];
	}
	str[length] = '\0';
}


void String::Print() {
	cout << str << endl;
}

String& String::operator=(const String& other)
{
	if (this->str != nullptr) {
		delete[] str;
	}

	length = 0;
	while (other.str[length] != '\0') {
		length++;
	}
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = other.str[i];
	}
	this->str[length] = '\0';
	return *this;
}


String::String(const char* str) {
	length = 0;
	while (str[length] != '\0') {
		length++;
	}
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->str[i] = str[i];
	}
	this->str[length] = '\0';
}


String::~String() {
	delete[] str;
}


