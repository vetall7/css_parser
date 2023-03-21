#include "List.h"
#include <iostream>
//#include "sekcja.h"


int main()
{
    list<int> b;
    b.push_back(0);
    b.push_back(1);
    b.push_back(2);
    b.pop_back();
    b.push_back(3);
    b.push_front(9);
    b.pop_front();

    for (int i = 0; i < b.GetSize(); i++) {
        std::cout << b[i];
    }


    //String a = "asdf";
    //bool is_write = true;
    //while (is_write) {
    //    char zn;
    //    String str = "";
    //    bool is_word_end = true;
    //    while (is_word_end) {
    //        cin >> zn;
    //        if (zn == '{') {
    //            is_write = false;
    //            is_word_end = false;

    //        }
    //        str.append(zn);
    //    }
    //}
}


