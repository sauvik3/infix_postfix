#include "tokenize.hpp"
#include "tokens.hpp"
#include <algorithm>
#include <cctype>
#include <regex>
#include <string>
#include <vector>

namespace calc {
std::vector<std::string> tokenize(const std::string &expInput) {
  std::vector<std::string> result;

  std::string expression = expInput;
  expression.erase(remove_if(expression.begin(), expression.end(), isspace),
                   expression.end());

  std::string::const_iterator searchStart(expression.cbegin());

  while (searchStart != expression.cend()) {
    std::regex re = std::regex{calc::operandRegex};
    std::smatch match;
    // Operand
    if (regex_search(searchStart, expression.cend(), match, re)) {
      searchStart = match.suffix().first;
      result.push_back(match.str(0));
    }

    // Operator
    bool noMatch = true;
    for (const auto &re_op : calc::operatorRegexMap) {
      std::regex re = std::regex{re_op.first};
      if (regex_search(searchStart, expression.cend(), match, re)) {
        searchStart = match.suffix().first;
        result.push_back(match.str(0));
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
