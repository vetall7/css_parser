#include "List.hpp"
#include "List.cpp"
#include "sekcja.hpp"
#include <iostream>



void what_is(String str, char zn) {

}


int main()
{
    Sections a;
    list<Sections> Section;
    Section.push_back(a);
    bool is_write = true;
    /*while (is_write) {
        char zn;
        String str = "";
        bool is_word_end = true;
        Sections sec;
        while (is_word_end) {
            cin >> zn;
            if (zn == '{') {
            }
            str.append(zn);
        }
    }*/
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].Attribute_append("AAA", "BBBB");
    Section[0].PrintAttributes();
}


