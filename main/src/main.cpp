#include "calc.hpp"
#include <iostream>
#include <string>

int main() {
    std::string expression;
    std::cout << "Input Expression: ";
    std::getline(std::cin, expression);
    std::cout << "Result: " << calc::eval(expression);
    return 0;
}
