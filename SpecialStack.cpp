#include "SpecialStack.h"

void SpecialStack::push(int value) {
    s.push(value);
}

void SpecialStack::pop() {
    if (s.empty()) {
        throw std::runtime_error("Cannot pop. Stack is empty.");
    }
    s.pop();
}

void SpecialStack::popEven() {
    if (s.empty()) {
        throw std::runtime_error("Cannot pop even number. Stack is empty.");
    }

    stack<int> temp;
    bool foundEven = false;

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        if (!foundEven && top % 2 == 0) {
            foundEven = true;
        } else {
            temp.push(top);
        }
    }

    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    if (!foundEven) {
        throw std::runtime_error("No even number found to pop.");
    }
}

void SpecialStack::popOdd() {
    if (s.empty()) {
        throw std::runtime_error("Cannot pop odd number. Stack is empty.");
    }

    stack<int> temp;
    bool foundOdd = false;

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        if (!foundOdd && top % 2 != 0) {
            foundOdd = true;
        } else {
            temp.push(top);
        }
    }

    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    if (!foundOdd) {
        throw std::runtime_error("No odd number found to pop.");
    }
}

int SpecialStack::peek() const {
    if (s.empty()) {
        throw std::runtime_error("Cannot peek. Stack is empty.");
    }
    return s.top();
}

bool SpecialStack::empty() const {
    return s.empty();
}

void SpecialStack::printStack() const {
    if (s.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
}
