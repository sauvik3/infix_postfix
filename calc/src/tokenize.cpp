// Copyright 2025 Sauvik Roy

#include <algorithm>
#include <cctype>
#include <regex>
#include <string>
#include <utility>
#include <vector>

#include "tokenize.hpp"

namespace calc {
std::vector<Token> tokenize(const std::string &expInput) {
  std::vector<Token> result;

  std::string expression = expInput;
  expression.erase(remove_if(expression.begin(), expression.end(), ::isspace),
                   expression.end());

  std::transform(expression.begin(), expression.end(), expression.begin(),
                 ::tolower);

  std::string::const_iterator searchStart(expression.cbegin());

  while (searchStart != expression.cend()) {
    std::regex re = std::regex{calc::operandRegex};
    std::smatch match;
    // Operand
    if (regex_search(searchStart, expression.cend(), match, re)) {
      searchStart = match.suffix().first;
      result.push_back(std::make_pair(match.str(0), Operator::OPERAND));
    }

    // Operator
    bool noMatch = true;
    for (const auto &re_op : calc::operatorRegexMap) {
      std::regex re = std::regex{re_op.first};
      if (regex_search(searchStart, expression.cend(), match, re)) {
        searchStart = match.suffix().first;
        result.push_back(std::make_pair(match.str(0), re_op.second));
        noMatch = false;
        break;
      }
    }
    if (noMatch) {
      break;
    }
  }

  return result;
}
}   // namespace calc
