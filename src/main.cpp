// Copyright 2020 JiJay
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
    //std::string s1("2 + 6 * 3 / (4 - 2)");
    //std::string s2 = infix2postfix(s1);
    //std::cout << s2;  // 2 6 3 * 4 2 - / +

    std::string inf = "2 + 2";
    std::string postf = infix2postfix(inf);
    std::cout << postf; //"2 2 +";

    //std::string inf = "2 + 6 * 3 / (4 - 2)";
    //std::string postf = infix2postfix(inf);
    //std::cout << postf; // "2 6 3 * 4 2 - / +";


    //std::string inf = "(2 + 8.3) * (6 - 3.2)";
    //std::string postf = infix2postfix(inf);
    //std::cout << postf; // "2 8.3 + 6 3.2 - *";

    //std::string inf = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
    //std::string postf = infix2postfix(inf);
    //std::cout << postf; // "6 4 2 - * 5 + 2.6 3 7 * + * 9 -";
    return 0;
}
