// Copyright 2020 JiJay
#include "MyStack.h"
#include "postfix.h"
#include "cstring"

std::string infix2postfix(std::string infix) {
    MyStack<char> outstack(500);
    MyStack<char> operationstack(500);
    int len = infix.length();
    int flag_num = 2;
    for (int i = 0; i < len; i++) {
        if (flag_num == 1) {
            outstack.push(' ');
        }
        if (infix[i] == ' ') {
            flag_num++;
            continue;
        }
        else if ((infix[i] >= '0') && (infix[i] <= '9') || ((infix[i] == '.'))) {
            outstack.push(infix[i]);
            flag_num = 0;
        }
        else if (infix[i] == '(') {
            flag_num++;
            operationstack.push(infix[i]);
        }
        else if (infix[i] == ')') {
            flag_num++;
            outstack.push(' ');
            while (operationstack.get() != '(') {
                outstack.push(operationstack.get());
                outstack.push(' ');
                operationstack.pop_const();
                if (operationstack.get() == '(')
                {
                    operationstack.pop_const();
                    break;
                }
            }
        }
        else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '/') || (infix[i] == '*')) {
            flag_num++;
            if ((infix[i] == '*') || (infix[i] == '/')) {
                if (!operationstack.isEmpty()) {
                    while ((operationstack.get() == '*') || (operationstack.get() == '/')) {
                        outstack.push(operationstack.get());
                        outstack.push(' ');
                        operationstack.pop_const();
                        if (operationstack.isEmpty())
                            break;
                    }
                }
            }

            if ((infix[i] == '+') || (infix[i] == '-'))
            {
                if (!operationstack.isEmpty()) {
                    while ((operationstack.get() == '*') || (operationstack.get() == '/') || (operationstack.get() == '+') || (operationstack.get() == '-')) {
                        outstack.push(operationstack.get());
                        outstack.push(' ');
                        operationstack.pop_const();
                        if (operationstack.isEmpty())
                            break;
                    }
                }
            }
            operationstack.push(infix[i]);
        }
    }
    while (!operationstack.isEmpty()) {
        outstack.push(operationstack.get());
        operationstack.pop_const();
        if (!operationstack.isEmpty()) {
            outstack.push(' ');
        }
    }
    int new_len = outstack.size_s();
    outstack.invert();
    char* transl = new char[new_len + 2];
    int j = 0;
    while (!outstack.isEmpty()) {
        transl[j++] = outstack.get();
        outstack.pop();
    }
    transl[j++] = '\0';
    std::string postfix = std::string(transl);
    infix = postfix;
    delete[] transl;
    return infix;
}
