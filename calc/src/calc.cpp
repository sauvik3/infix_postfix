// Copyright 2025 Sauvik Roy

#include <cstdlib>
#include <string>
#include <vector>

#include "calc.hpp"
#include "tokenize.hpp"
#include "tokens.hpp"

namespace calc {
double eval(const std::string &expression) {
  double res = 0.0;
  std::vector<Token> tokens = calc::tokenize(expression);

  for (const auto &token : tokens) {
    if (token.second == Operator::OPERAND) {
      res += std::atof(token.first.c_str());
    }
  }
  return res;
}
}   // namespace calc
