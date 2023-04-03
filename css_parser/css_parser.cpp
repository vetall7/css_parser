#include "List.h"
#include "List.cpp"
#include "sekcja.h"
#include <iostream>
#include <fstream>


bool is_selector(char zn) {
    if (zn == '{') {
        return true;
    }
    return false;
}

bool is_attribute(char zn) {
    if (zn == ';') {
        return true;
    }
    return false;
}


size_t to_number(String num) {
    size_t number = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        number += (num[i] - '0') * pow(10, num.size() - i - 1);
    }
    return number;
}


void counter(list<Section>& Sections, String str) {
    size_t i = 0;
    while (str[i] != ',') {
        i++;
    }
    size_t num = to_number(str.cut(0, i));
    if (str[i + 1] == 'S' && str[i + 2] == ',') {
        if (num <= Sections.GetSize()) {
            if (Sections[num - 1].is_selector_exists("")) {
                cout << num << ",S,? == " << 0 << endl;
            }
            else {
                cout << num << ",S,? == " << Sections[num - 1].GetSelectorsCounter() << endl;
            }
        }
    }
    else if (str[i + 1] == 'A' && str[i + 2] == ',') {
        if (num <= Sections.GetSize()) {
             cout << num << ",A,? == " << Sections[num - 1].GetAttributesCounter() << endl;
        }
    }
}


void print_selector(list<Section>& Sections, String str) {
    size_t i = 0;
    while (str[i] != ',') {
        i++;
    }
    size_t num = to_number(str.cut(0, i));
    size_t num2 = to_number(str.cut(i + 3, str.size()));
    if (num - 1 < Sections.GetSize() && num2 - 1 < Sections[num - 1].GetSelectorsCounter() && !(Sections[num - 1].is_selector_exists("") && Sections[num - 1].GetSelectorsCounter() == 1) ) {
        cout << num << ",S," << num2 << " == ";
        Sections[num - 1].GetSelector(num2 - 1).Print();
        cout << endl;
    }
}


void print_attribute(list<Section>& Sections, String str) {
    size_t i = 0;
    while (str[i] != ',') {
        i++;
    }
    size_t num = to_number(str.cut(0, i));
    String temp = str.cut(i + 3, str.size());
    if (num > Sections.GetSize()) {
        return;
    }
    if (!(Sections[num - 1].GetAttributeValue(temp) == "")) {
        cout << num << ",A," << temp << " == ";
        Sections[num - 1].GetAttributeValue(temp).Print();
        cout << endl;
    }
}

void elements_counter(list<Section>& Sections, String str) {
    int i = 0;
    while (str[i] != ',') {
        i++;
    }
    String temp = str.cut(0, i);
    int counter = 0;
    if (str.is_consist('A')) {
        for ( Section& element : Sections) {
            if (element.is_attribute_exists(temp)) {
                counter++;
            }
        }
        cout << temp << ",A,? == " << counter << endl;
    }
    else if (str.is_consist('S')) {
        for (Section& element : Sections) {
            if (element.is_selector_exists(temp)) {
                counter++;
            }
        }
        cout << temp << ",S,? == " << counter << endl;
    }
}


void print_attribute_value(list<Section>& Sections, String str) {
    size_t i = 0;
    while (str[i] != ',') {
        i++;
    }
    String selec_tmp = str.cut(0, i);
    String attribute_tmp = str.cut(i + 3, str.size());
    String selec = "", attribute = "", value = "";
    for (Section& element : Sections) {
        if (element.is_selector_exists(selec_tmp) && element.is_attribute_exists(attribute_tmp)) {
            selec = selec_tmp;
            attribute = attribute_tmp;
            value = element.GetAttributeValue(attribute_tmp);
        }
    }
    if (selec == "" || attribute == "" || value == "") {
        return;
    }
    cout << selec << ",E," << attribute << " == ";
    value.Print();
    cout << endl;
}


void section_remove(list<Section>& Sections, String str) {
    size_t i = 0;
    while (str[i] != ',') {
        i++;
    }
    size_t num = to_number(str.cut(0, i));
    if (num > Sections.GetSize()) {
        return;
    }
    Sections[num - 1].remove();
    Sections.remove_element(num - 1);
    cout << num << ",D,* == deleted" << endl;
}


void attribute_remove(list<Section>& Sections, String str) {
    size_t i = 0;
    while (str[i] != ',') {
        i++;
    }
    size_t num = to_number(str.cut(0, i));
    String temp = str.cut(i + 3, str.size());
    bool exists = false;
    for (Section& element : Sections) {
        if (element.is_attribute_exists(temp)) {
            exists = true;
            break;
        }
    }
    if (!exists) { return; }
    Sections[num - 1].removeAttribute(temp);
    if (Sections[num - 1].GetAttributesCounter() == 0 || (Sections[num-1].is_attribute_exists("") && Sections[num - 1].GetAttributesCounter() == 1)) {
        Sections[num - 1].remove();
        Sections.remove_element(num - 1);
    }
    cout << num << ",D," << temp << " == deleted" << endl;
    
}


void css_read(list<Section>& Sections);


void command_read(list<Section>& Sections) {
    while (true) {
        char zn;
        bool is_word_end = false;
        String str = "";
        while (!is_word_end) {
            zn = getchar();
            if (zn != '\n') { str.append(zn); }
            if (zn == '?') {
                int counter = 0;
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] == ',') {
                        counter++;
                    }
                }
                if (counter != 2 && counter != 0) {
                    is_word_end = true;
                    continue;
                }
            }
            if (str == "?") {
                cout << "? == " << Sections.GetSize() << endl;
                is_word_end = true;
            }
            else if (str == "****") {
                css_read(Sections);
            }
            else if (zn == '?' && str[0] >= '0' && str[0] <= '9') {
                counter(Sections, str);
                is_word_end = true;
            }
            else if (zn == '\n' && str[0] >= '0' && str[0] <= '9' && str[str.size() - 1] >= '0' && str[str.size() - 1] <= '9'){
                if (!str.is_consist('S')) {
                    is_word_end = true;
                    continue;
                }
                print_selector(Sections, str);
                is_word_end = true;
            }
            else if (zn == '\n' && str[0] >= '0' && str[0] <= '9' && str.is_consist('A') && !str.is_consist('?')) {
                print_attribute(Sections, str);
                is_word_end = true;
            }
            else if (zn == '?') {
                elements_counter(Sections, str);
                is_word_end = true;
            }
            else if (zn == '\n' && str.is_consist('E')) {
                print_attribute_value(Sections, str);
                is_word_end = true;
            }
            else if (str.contains(",D,*")) {
                section_remove(Sections, str);
                is_word_end = true;
            }
            else if (zn == '\n' && str.contains(",D,") && !str.is_consist('*')) {
                attribute_remove(Sections, str);
                is_word_end = true;
            }
            else if (zn == EOF) {
                return;
            }
        }
    }
}

void css_read(list<Section>& Sections) {
    while (true) {
        char zn;
        bool is_word_end = false;
        char input[10000];
        int i = 0;
        while (!is_word_end) {
            zn = getchar();
            if (zn == '\n' || zn < ' ') continue;
            input[i] = zn;
            if (is_selector(input[i])) {
                input[i + 1] = '\0';
                String str(input);
                Section a;
         
                Sections.push_back(a);

                Sections[Sections.GetSize() - 1].New_selector(str);
                is_word_end = true;
            }
            else if (is_attribute(input[i])) {
                input[i + 1] = '\0';
                String str(input);
                Sections[Sections.GetSize() - 1].New_attribute(str);
                is_word_end = true;
            }
            else if (input[i] == '}') {
                input[i + 1] = '\0';
                String str(input);
                if (str.size() != 1) {
                    Sections[Sections.GetSize() - 1].New_attribute(str);
                    is_word_end = true;
                }
                continue;
            }

            if (i >= 3 && input[i - 1] == '?' && input[i - 2] == '?' && input[i - 3] == '?')
            {
                command_read(Sections);
                return;
            }
            i++;
        }
    }
}


int main()
{
    list<Section> Sections;
    css_read(Sections);
}