#include "List.hpp"
#include "List.cpp"
#include "sekcja.hpp"
#include <iostream>



bool is_selector(String str, char zn) {
    if (zn == '{') {
        return true;
    }
    return false;
}

bool is_attribute(String str, char zn) {
    if (zn == ';') {
        return true;
    }
    return false;
}

bool is_commands_start(String str, char zn) {
    if (str == "????") {
        return true;
    }
    return false;
}


int to_number(String num) {
    int number = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        number += (num[i] - '0') * pow(10, num.size() - i - 1);
    }
    return number;
}


void counter(list<Sections>& Section, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    int num = to_number(str.cut(0, i));
    if (str[i + 1] == 'S' && str[i + 2] == ',') {
        if (num <= Section.GetSize()) {
            cout << num << ",S,? == " << Section[num - 1].GetSelectorsCounter() << endl;
        }
    }
    else if (str[i + 1] == 'A' && str[i + 2] == ',') {
        if (num <= Section.GetSize()) {
            cout << num << ",A,? == " << Section[num - 1].GetAttributesCounter() << endl;
        }
    }
}


void print_selector(list<Sections>& Section, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    int num = to_number(str.cut(0, i));
    int num2 = to_number(str.cut(i + 3, str.size()));
    cout << num << ",S," << num2 << " == ";
    if (num - 1 < Section.GetSize() && num2 - 1 < Section[num - 1].GetSelectorsCounter()) {
        Section[num - 1].GetSelector(num2 - 1).Print();
    }
}


void print_attribute(list<Sections>& Section, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    int num = to_number(str.cut(0, i));
    String temp = str.cut(i + 3, str.size());
    if (num > Section.GetSize()) {
        return;
    }
    if (!(Section[num - 1].GetAttributeValue(temp) == "")) {
        cout << num << ",A," << temp << " == ";
        Section[num - 1].GetAttributeValue(temp).Print();
    }
}

void elements_counter(list<Sections>& Section, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    String temp = str.cut(0, i);
    int counter = 0;
    if (str.is_consist('A')) {
        for (int i = 0; i < Section.GetSize(); i++) {
            if (Section[i].is_attribute_exists(temp)) {
                counter++;
            }
        }
        cout << temp << ",A,? == " << counter << endl;
    }
    else if (str.is_consist('S')) {
        for (int i = 0; i < Section.GetSize(); i++) {
            if (Section[i].is_selector_exists(temp)) {
                counter++;
            }
        }
        cout << temp << ",S,? == " << counter << endl;
    }
}


void print_attribute_value(list<Sections>& Section, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    String selec_tmp = str.cut(0, i);
    String attribute_tmp = str.cut(i + 3, str.size());
    for (int i = Section.GetSize(); i > 0; i--) {
        if (Section.search_reverse(i).is_selector_exists(selec_tmp) && Section.search_reverse(i).is_attribute_exists(attribute_tmp)) {
            cout << selec_tmp << ",E," << attribute_tmp << " == ";
            Section.search_reverse(i).GetAttributeValue(attribute_tmp).Print();
            break;
        }
    }
}


void section_remove(list<Sections>& Section, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    int num = to_number(str.cut(0, i));
    Section[num - 1].remove();
    Section.remove_element(num - 1);
    cout << num << ",D,* == deleted" << endl;
}


void attribute_remove(list<Sections>& Section, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    int num = to_number(str.cut(0, i));
    String temp = str.cut(i + 3, str.size());
    Section[num - 1].removeAttribute(temp);
    if (Section[num - 1].GetAttributesCounter() == 0) {
        Section[num - 1].remove();
        Section.remove_element(num - 1);
    }
    cout << num << ",D," << temp << " == deleted" << endl;
}



void css_read(list<Sections>& Section);



void command_read(list<Sections>& Section) {
    bool is_write = true;
    while (is_write) {
        char zn;
        bool is_word_end = false;
        String str = "";
        while (!is_word_end) {
            cin.get(zn);
            if (zn != '\n') { str.append(zn); }
            if (str == "?") {
                cout << "? == " << Section.GetSize() << endl;
                is_word_end = true;
            }
            else if (str == "****") {
                css_read(Section);
            }
            else if (zn == '?' && str[0] >= '0' && str[0] <= '9') {
                    counter(Section, str);
                    is_word_end = true;
            }
            else if (zn == '\n' && str[0] >= '0' && str[0] <= '9' && str[str.size() - 1] >= '0' && str[str.size() - 1] <= '9') {
                print_selector(Section, str);
                is_word_end = true;
            }
            else if (zn == '\n' && str[0] >= '0' && str[0] <= '9' && str.is_consist('A') && !str.is_consist('?')) {
                print_attribute(Section, str);
                is_word_end = true;
             }
            else if (zn == '?') {
                elements_counter(Section, str);
                is_word_end = true;
            }
            else if (zn == '\n' && str.is_consist('E')) {
                print_attribute_value(Section, str);
                is_word_end = true; 
            }
            else if (str.is_consist('D') && str.is_consist('*')) {
                section_remove(Section, str);
                is_word_end = true;
            }
            else if (zn == '\n' && str.is_consist('D') && !str.is_consist('*')) {
                attribute_remove(Section, str);
                is_word_end = true;
            }
        }
    }
}
 
void css_read(list<Sections>& Section) {
    bool is_write = true;
    while (is_write) {
        char zn;
        bool is_word_end = false;
        String str = "";
        while (!is_word_end) {
            cin.get(zn);
            if (is_selector(str, zn)) {
                Sections a;
                Section.push_back(a);
                Section[Section.GetSize()-1].New_selector(str);
                //Section[Section.GetSize()-1].PrintSelectors();
                is_word_end = true;
            }
            else if (is_attribute(str, zn)) {
                Section[Section.GetSize()-1].New_attribute(str);
                //Section[Section.GetSize()-1].PrintAttributes();
                is_word_end = true;
            }
            else if (zn == '}') {
                if (str.size() != 0) {
                    Section[Section.GetSize()-1].New_attribute(str);
                    //Section[Section.GetSize()-1].PrintAttributes();
                    is_word_end = true;
                }
                continue;
            }
            if (zn != '\n') { str.append(zn); }

            if (is_commands_start(str, zn))
            {
                command_read(Section);
            }
        }
    }
}


int main()
{
    static list<Sections> Section;
    css_read(Section);
}


