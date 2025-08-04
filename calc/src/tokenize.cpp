#include "tokenize.hpp"
#include "tokens.hpp"
#include <regex>
#include <string>
#include <vector>

namespace calc {
std::vector<std::string> tokenize(const std::string &expression) {
  const std::regex re = std::regex{calc::operandRegex};
  std::smatch match;
  std::vector<std::string> result;

  std::string::const_iterator searchStart(expression.cbegin());

  while (regex_search(searchStart, expression.cend(), match, re)) {
    result.push_back(match.str(0));
    searchStart = match.suffix().first;
  }
  return result;
}
}   // namespace calc
