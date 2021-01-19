// Copyright 2020 JiJay
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2 = infix2postfix(s1);
    std::cout << s2;  // 2 6 3 * 4 2 - / +

    std::string inf_1 = "123 + 15 + 10";
    std::string postf_1 = infix2postfix(inf_1);
    std::cout << postf_1; //"123 15 10 + +";

    std::string inf_2 = "1 + 2 * 3 / (4 - 5)";
    std::string postf_2 = infix2postfix(inf_2);
    std::cout << postf_2; // "1 2 3 * 4 5 - / +";

    std::string inf_3 = "(0.1 + 0.9) * (4.1 - 0.1)";
    std::string postf_3 = infix2postfix(inf_3);
    std::cout << postf_3; // "0.1 0.9 + 4.1 0.1 - *";

    std::string inf_4 = "(1 * (2 * (3 * (4 * (5 * (6 * (7 * (8 * (9 * (10 + 1))))))))))";
    std::string postf_4 = infix2postfix(inf_4);
    std::cout << postf_4; // "1 2 3 4 5 6 7 8 9 10 1 + * * * * * * * * *";
    return 0;
}
