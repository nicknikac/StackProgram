#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H

#include <stack>
#include <iostream>
#include <stdexcept>
using namespace std;

class SpecialStack {
private:
    stack<int> s;

public:
    void push(int value);
    void pop();
    void popEven();
    void popOdd();
    int peek() const;
    bool empty() const;
    void printStack() const;
};

#endif
