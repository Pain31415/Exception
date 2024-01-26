#include <iostream>
#include <fstream>
#include <stdexcept>

class MyException : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Error";
    }
};

class MathException : public MyException {
public:
    const char* what() const noexcept override {
        return "Math error";
    }
};

class MemoryException : public MyException {
public:
    const char* what() const noexcept override {
        return "Memory error";
    }
};

class FileException : public MyException {
public:
    const char* what() const noexcept override {
        return "File error";
    }
};

double divide(double a, double b) {
    if (b == 0) {
        throw MathException();
    }
    return a / b;
}

void allocateMemory(int size) {
    int* ptr = new int[size];
    if (ptr == nullptr) {
        throw MemoryException();
    }
    delete[] ptr;
}

void openFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileException();
    }
    std::cout << "File opened successfully!" << std::endl;
    file.close();
}

int main() {
    try {
        double result = divide(10.0, 0.0);
    }
    catch (const MathException& e) {
        std::cerr << "Error: " << e.what() << " - Division by zero" << std::endl;
    }

    try {
        allocateMemory(-1);
    }
    catch (const MemoryException& e) {
        std::cerr << "Error: " << e.what() << " - Incorrect memory size" << std::endl;
    }

    try {
        openFile("nonexistent.txt");
    }
    catch (const FileException& e) {
        std::cerr << "Error: " << e.what() << " - File not found" << std::endl;
    }

    return 0;
}