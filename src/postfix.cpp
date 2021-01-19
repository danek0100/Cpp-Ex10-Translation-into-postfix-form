// Copyright 2020 JiJay
#include "MyStack.h"
#include "postfix.h"
#include "cstring"

std::string infix2postfix(std::string infix) {
    MyStack<char> outstack(500);
    MyStack<char> operationstack(500);
    int len = infix.length();
    for (int i = 0; i < len; i++)
    {
        //Если будет первод строки, то закончим ввод. (Для удобства, при необходимости можно убрать)
        if (infix[i] == ' ')
        {
            continue;
        }
        if (infix[i] == '\0')
        {
            while (!operationstack.isEmpty()) {
                outstack.push(operationstack.get());
                operationstack.pop();
            }
            break;
        }
        if ((infix[i] >= 'a') && (infix[i] <= 'z'))
        {
            outstack.push(infix[i]);
        }
        if (infix[i] == '(')
        {
            outstack.push(infix[i]);
        }
        if (infix[i] == ')')
        {
            while (operationstack.get() != '(')
            {
                outstack.push(operationstack.get());
                operationstack.pop();
                if (operationstack.get() == '(')
                {
                    operationstack.pop();
                    break;
                }
            }
        }
        if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '/') || (infix[i] == '*'))
        {
            if ((infix[i] == '*') || (infix[i] == '/'))
            {
                if (!operationstack.isEmpty())
                {
                    while ((operationstack.get() == '*') || (operationstack.get()== '/'))
                    {
                        outstack.push(operationstack.get());
                        operationstack.pop();
                        if (operationstack.isEmpty())
                            break;
                    }
                }
            }

            if ((infix[i] == '+') || (infix[i] == '-'))
            {
                if (!operationstack.isEmpty())
                {
                    while ((operationstack.get() == '*') || (operationstack.get() == '/') || (operationstack.get() == '+') || (operationstack.get() == '-'))
                    {
                        outstack.push(operationstack.get());
                        operationstack.pop();
                        if (operationstack.isEmpty())
                            break;
                    }
                }
            }
            operationstack.push(infix[i]);
        }
    }
    int new_len = outstack.size_s();
    char* transl = new char[new_len];
    int j = 0;
    while (!outstack.isEmpty())
    {
        transl[j++] = outstack.get();
    }
    std::string postfix = std::string(transl);
    infix = postfix;
    delete[] transl;
    return infix;
}
