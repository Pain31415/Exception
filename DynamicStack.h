#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicStack {
private:
    T* stack;
    int top;
    int capacity;

public:
    DynamicStack();
    ~DynamicStack();
    bool isEmpty() const;
    void push(const T& value);
    T pop();
    int size() const;
    void clear();
    T topElement() const;
    T& operator[](int index);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const DynamicStack<T>& stack);

#endif // DYNAMIC_STACK_H