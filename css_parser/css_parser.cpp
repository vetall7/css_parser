#include "List.h"
#include "List.cpp"
#include "sekcja.h"
#include <iostream>


int main()
{
    bool is_write = true;
    while (is_write) {
        char zn;
        String str = "";
        bool is_word_end = true;
        while (is_word_end) {
            cin >> zn;
            if (zn == '{') {
                is_write = false;
                is_word_end = false;

            }
            str.append(zn);
        }
    }
}


