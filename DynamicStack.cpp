#include "DynamicStack.h"

template <typename T>
void DynamicStack<T>::push(const T& value) {
    try {
        if (isEmpty()) {
            stack = new T[1];
            capacity = 1;
        }
        else if (top + 1 == capacity) {
            T* newStack = new T[2 * capacity];
            if (newStack == nullptr) {
                throw std::bad_alloc();
            }
            for (int i = 0; i <= top; ++i) {
                newStack[i] = stack[i];
            }
            delete[] stack;
            stack = newStack;
            capacity *= 2;
        }
        stack[++top] = value;
    }
    catch (const std::bad_alloc& e) {
        throw std::runtime_error("Memory allocation failed");
    }
}

template <typename T>
T DynamicStack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return stack[top--];
}

template <typename T>
void DynamicStack<T>::clear() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is already empty");
    }
    delete[] stack;
    stack = nullptr;
    top = -1;
    capacity = 0;
}

template <typename T>
T DynamicStack<T>::topElement() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return stack[top];
}

template <typename T>
T& DynamicStack<T>::operator[](int index) {
    if (index < 0 || index > top) {
        throw std::out_of_range("Index out of range");
    }
    return stack[index];
}