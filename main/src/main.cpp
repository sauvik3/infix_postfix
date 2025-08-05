// Copyright 2025 Sauvik Roy

#include <iostream>
#include <string>

#include "calc.hpp"

int main() {
    std::string expression;
    std::cout << "Input Expression: ";
    std::getline(std::cin, expression);
    std::cout << "Postfix: ";
    const double result = calc::eval(expression);
    std::cout << std::endl;
    std::cout << "Result: " << result;
    return 0;
}
