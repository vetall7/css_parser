#pragma once
using namespace std;
#include <iostream>
class String {
private:
	char* str;
	int length;
public:
	String() {
		str = nullptr;
		length = 0;
	}
	String(const char* str);
	int containString(const String& other) const;
	~String();
	void Print() const;
	String& operator=(const String& other);
	friend ostream& operator<<(ostream& os, const String& str);
	friend bool operator==(const String& a, const String& b);
	int size() const;
	char& operator[](int i) const;
	void append(const char a);
	String(String&& other);
	String(const String& other);
	String cut(size_t i, size_t j) const;
	bool is_consist(char a) const;
	String& operator=(String&& other);
	void remove_spaces();
	void remove_selectors_spaces();
	bool contains(const char* subStr) const;
};
