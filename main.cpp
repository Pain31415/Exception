#include "DynamicStack.h"

int main() {
    DynamicStack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Integer Stack:\n";
    std::cout << intStack << "\n";
    std::cout << "Stack Size: " << intStack.size() << "\n";
    std::cout << "Top Element: " << intStack.topElement() << "\n\n";

    DynamicStack<double> doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);

    std::cout << "Double Stack:\n";
    std::cout << doubleStack << "\n";
    std::cout << "Stack Size: " << doubleStack.size() << "\n";
    std::cout << "Top Element: " << doubleStack.topElement() << "\n";

    return 0;
}