// Copyright 2025 Sauvik Roy

#include <cstdlib>
#include <stack>
#include <string>
#include <vector>

#include "calc.hpp"
#include "tokenize.hpp"
#include "tokens.hpp"

namespace calc {
std::stack<Token> infixToPostfix(const std::vector<Token> &tokens) {
  std::stack<Token> postfix;

  for (const auto &token : tokens) {
    if (token.second == Operator::OPERAND) {
      postfix.push(token);
    }
  }

  return postfix;
}

double eval(const std::string &expression) {
  double res = 0.0;
  std::vector<Token> tokens = calc::tokenize(expression);

  std::stack<Token> postfix = calc::infixToPostfix(tokens);

  while (!postfix.empty()) {
    auto token = postfix.top();
    if (token.second == Operator::OPERAND) {
      res += std::atof(token.first.c_str());
    }
    postfix.pop();
  }

  return res;
}
}   // namespace calc
