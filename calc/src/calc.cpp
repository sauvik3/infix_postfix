#include "calc.hpp"
#include "tokenize.hpp"
#include "tokens.hpp"
#include <cstdlib>
#include <regex>
#include <vector>
#include <string>


namespace calc {
int eval(const std::string &expression) {
  int res = 0;
  std::vector<std::string> tokens = calc::tokenize(expression);

  const std::regex pattern = std::regex{calc::operandRegex};
  for (const auto &token : tokens) {
    if (std::regex_match(token, pattern)) {
      res += std::atoi(token.c_str());
    }
  }
  return res;
}
}   // namespace calc
