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
        cout << "command start" << endl;
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


void css_read(list<Sections>& Section);

void command_read(list<Sections>& Section) {
    bool is_write = true;
    while (is_write) {
        char zn;
        bool is_word_end = false;
        String str = "";
        while (!is_word_end) {
            zn = getchar();
            str.append(zn);
            if (str == "?") {
                cout << Section.GetSize() << endl;
                is_word_end = true;
            }
            else if (str == "****") {
                css_read(Section);
            }
            else if (zn == '?') {
                if (str[0] >= '0' && str[0] <= '9') {
                    int i = 0;
                    while (str[i] != ',') {
                        i++;
                    }
                    int num = to_number(str.cut(0, i));
                    if (str[str.size() - 1] >= '0' && str[str.size() - 1] <= '9') {
                        cout << "fasdfasd";
                        int j = str.size();
                        while (str[j] != ',') {
                            j--;
                        }
                        int num2 = to_number(str.cut(j, str.size()));
                        Section[num - 1].GetSelector(num2 - 1);
                    }
                    if (str[i + 1] == 'S' && str[i + 2] == ',') {
                        if (num <= Section.GetSize()) {
                            cout << Section[num - 1].GetSelectorsCounter();
                        }
                    }
                    else if (str[i + 1] == 'A' && str[i + 2] == ',') {
                        if (num <= Section.GetSize()) {
                            cout << Section[num - 1].GetAttributesCounter();
                        }
                    }
                    is_word_end = true;
                }
            }
             if (zn == '\n' && str[0] >= '0' && str[0] <= '9' ) {
                cout << "fasd";
                is_word_end = true;
                /*int i = 0;
                while (str[i] != ',') {
                    i++;
                }
                int num = to_number(str.cut(0, i));
                String temp = str.cut(i + 2, str.size());
                temp.Print();*/
                //Section[num].GetSttributeValue(temp).Print();
            }
        }
    }
}

// TODO: разбить все на функции  
void css_read(list<Sections>& Section) {
    cout << "css_read" << endl;
    bool is_write = true;
    static size_t section_counter = -1;
    while (is_write) {
        char zn;
        bool is_word_end = false;
        String str = "";
        while (!is_word_end) {
            cin >> zn;
            if (is_selector(str, zn)) {
                Sections a;
                Section.push_back(a);
                section_counter++;
                Section[section_counter].New_selector(str);
                Section[section_counter].PrintSelectors();
                is_word_end = true;
            }
            else if (is_attribute(str, zn)) {
                Section[section_counter].New_attribute(str);
                //Section[section_counter].PrintAttributes();
                is_word_end = true;
            }
            else if (zn == '}') {
                if (str.size() != 0) {
                    Section[section_counter].New_attribute(str);
                    //Section[section_counter].PrintAttributes();
                    is_word_end = true;
                }
                continue;
            }
            str.append(zn);

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


