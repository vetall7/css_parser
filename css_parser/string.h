#pragma once
using namespace std;

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
	~String();
	void Print();
	String& operator=(const String& other);
	int size();
	bool operator==(const String& other);
	char& operator[](int i);
	void append(const char a);
	String(const String& other);
};
