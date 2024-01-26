#include <iostream>
#include <string>
#include <stdexcept>

class RangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Overflow of the long long range";
    }
};

class FormatException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid number format";
    }
};

long long computeValue(const std::string& input) {
    try {
        size_t pos;
        long long result = std::stoll(input, &pos);
        if (pos < input.size()) {
            throw FormatException();
        }
        return result;
    }
    catch (const std::out_of_range& e) {
        throw RangeException();
    }
    catch (const std::invalid_argument& e) {
        throw FormatException();
    }
}

int main() {
    while (true) {
        std::string input;
        std::cout << "Enter a number (type 'q' to quit): ";
        std::cin >> input;

        if (input == "q") {
            std::cout << "Program terminated." << std::endl;
            break;
        }

        try {
            long long result = computeValue(input);
            std::cout << "Result: " << result << std::endl;
        }
        catch (const RangeException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (const FormatException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}