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
        cout << "command start";
        return true;
    }
    return false;
}

void css_read();

void command_read(list<Sections>* Section) {
    bool is_write = true;
    while (is_write) {
        char zn;
        bool is_word_end = false;
        String str = "";
        while (!is_word_end) {
            cin >> zn;
            str.append(zn);
            if (str == "?") {
                cout << Section->GetSize();
                is_word_end = true;
            }
            if (str == "****") {
                css_read();
            }

        }
    }
}

// TODO: копирование аттрибутов, сдлеать так чтобы секция создавлась после { а не }, разбить все на фенкции  
void css_read() {
    Sections a;
    list<Sections> Section;
    Section.push_back(a);
    bool is_write = true;
    size_t section_counter = 0;
    while (is_write) {
        char zn;
        bool is_word_end = false;
        String str = "";
        while (!is_word_end) {
            cin >> zn;
            if (is_selector(str, zn)) {
                Section[section_counter].New_selector(str);
                Section[section_counter].PrintSelectors();
                is_word_end = true;
            }
            else if (is_attribute(str, zn)) {
                Section[section_counter].New_attribute(str);
                Section[section_counter].PrintAttributes();
                is_word_end = true;
            }
            else if (zn == '}') {
                if (str.size() != 0) {
                    Section[section_counter].New_attribute(str);
                    Section[section_counter].PrintAttributes();
                    is_word_end = true;
                }
                Sections next;
                Section.push_back(next);
                section_counter++;
                is_word_end = false;
                /*for (int i = 0; i < Section.GetSize(); i++) {
                    if (Section[i].is_empty()) {
                        Section[section_counter].copy_attributes(Section[i]);
                    }
                }*/
                continue;
            }
            str.append(zn);

            if (is_commands_start(str, zn))
            {
                command_read(&Section);
            }
        }
    }
}


int main()
{
    css_read();
}


