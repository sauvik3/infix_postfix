#pragma once

#include <map>
#include <string>
#include <utility>

namespace calc {
enum Operator { ADD = 0, SUBTRACT = 1, MULTIPLY = 2, DIVIDE = 3 };
static const std::map<std::string, enum Operator> operatorRegexMap = {
    std::make_pair("^\\+", Operator::ADD),
    std::make_pair("^\\-", Operator::SUBTRACT),
    std::make_pair("^\\*", Operator::MULTIPLY),
    std::make_pair("^/", Operator::DIVIDE),
};
static const char operandRegex[] = "^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?";
}   // namespace calc
