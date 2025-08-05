// Copyright 2025 Sauvik Roy
#pragma once

#include <stack>
#include <string>
#include <vector>

#include "tokenize.hpp"

namespace calc {
int comparePrecedence(const Token &token1, const Token &token2);
std::stack<Token> infixToPostfix(const std::vector<Token> &tokens);
double eval(const std::string &expression);
}   // namespace calc
