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

  Token prevToken = std::make_pair("?", Operator::UNKOWN);
  while (searchStart != expression.cend()) {
    std::regex re = std::regex{calc::operandRegex};
    std::smatch match;
    // Operand
    // Can't have an operand following a right-parenthesis
    if (prevToken.second != Operator::R_PAR &&
        regex_search(searchStart, expression.cend(), match, re)) {
      searchStart = match.suffix().first;
      result.push_back(std::make_pair(match.str(0), Operator::OPERAND));
      prevToken = std::make_pair(match.str(0), Operator::OPERAND);
    }

    // Operator
    bool noMatch = true;
    for (const auto &[re_op_str, re_op_type] : calc::operatorRegexMap) {
      std::regex re = std::regex{re_op_str};
      if (regex_search(searchStart, expression.cend(), match, re)) {
        searchStart = match.suffix().first;
        if (re_op_type == Operator::SUBTRACT) {
          // Minus following an operand or right-parenthesis
          if ((prevToken.second != Operator::OPERAND &&
              prevToken.second != Operator::R_PAR) ||
              prevToken.second == Operator::UNKOWN) {
            result.push_back(std::make_pair(match.str(0), Operator::NEGATIVE));
          } else {
            result.push_back(std::make_pair(match.str(0), re_op_type));
          }
        } else {
          result.push_back(std::make_pair(match.str(0), re_op_type));
        }
        noMatch = false;
        prevToken = std::make_pair(match.str(0), re_op_type);
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
