// Copyright 2020 JiJay
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class Type>
class MyStack {
private:
    int num_of_el = 0;
    int size;
    Type* stack;

public:
    explicit MyStack(int size) {
        this->size = size;
        stack = new Type[this->size];
    }
    MyStack(const MyStack& stack_prev) {
        this->size = stack_prev.size;
        this->nun_of_el = stack_prev.num_of_el;
        this->stack = new Type[size];
        int i = 0;
        while (i < size) {
            stack[i] = stack_prev.stack[i];
            i++;
        }
    }
    ~MyStack() {
        delete[] stack;
        size = 0;
        num_of_el = 0;
    }

    Type get() const {
        return stack[num_of_el - 1];
    }

    Type pop() {
        Type temp = stack[num_of_el - 1];
        Type* update_stack = new Type[num_of_el - 1];
        for (int i = 0; i < num_of_el - 1; i++)
            update_stack[i] = stack[i];
        delete[] stack;
        num_of_el--;
        stack = update_stack;
        return temp;
    }

    Type pop_const() {
        Type temp = stack[num_of_el - 1];
        num_of_el--;
        return temp;
    }

    void push(Type element) {
        stack[num_of_el] = element;
        num_of_el++;
    }

    bool isFull() const {
        return num_of_el == size;
    }
    bool isEmpty() const {
        return num_of_el == 0;
    }
    int size_s() {
        return num_of_el;
    }
    void invert() {
        for (int i = 0; i < num_of_el / 2; i++) {
            Type temp = stack[num_of_el - 1 - i];
            stack[num_of_el - 1 - i] = stack[i];
            stack[i] = temp;
        }
    }
};

#endif  // INCLUDE_MYSTACK_H_
