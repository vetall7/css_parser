#include  "string.h "
using namespace std;

char& String::operator[](int i) const{
	return str[i];    
}

void String::append(const char a)
{
	char *str2 = new char[length + 2];
	if (str != nullptr) {
		memcpy(str2, str, length);
		delete[] str;
	}
	str2[length] = a;
	str2[length + 1] = '\0';
	length++;
	str = str2;
}


String::String(String&& other) {
	this->str = other.str;
	this->length = other.length;
	other.str = nullptr;
	other.length = 0;
}

String& String::operator=(String&& other) {
	if (this == &other) {
		return *this;
	}

	delete[] str;
	str = other.str;
	length = other.length;
	other.str = nullptr;
	other.length = 0;
	return *this;
}



bool operator==(const String& a, const String& b) {
	if (a.length != b.length) {
		return false;
	}
	return (memcmp(a.str, b.str, a.length) == 0);
}

int String::size() const{
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

String String::cut(size_t i, size_t j) const
{
	String temp;
	for (int k = i; k < j; k++) {
		temp.append(str[k]);
	}
	return move(temp);
}

bool String::is_consist(char a) const
{
	for (int i = 0; i < length; i++) {
		if (str[i] == a) {
			return true;
		}
	}
	return false;
}


void String::Print() const {
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

ostream& operator<<(ostream& os, const String& other)
{
	os << other.str;
	return os;
}
