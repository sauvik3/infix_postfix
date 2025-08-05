// Copyright 2025 Sauvik Roy
#pragma once

#include <map>
#include <string>
#include <utility>

namespace calc {
enum Operator {
  OPERAND = 0,
  ADD = 1,
  SUBTRACT = 2,
  MULTIPLY = 3,
  DIVIDE = 4,
  INVERSE = 5
};
static const std::map<std::string, enum Operator> operatorRegexMap = {
    std::make_pair("^\\+", Operator::ADD),
    std::make_pair("^\\-", Operator::SUBTRACT),
    std::make_pair("^\\*", Operator::MULTIPLY),
    std::make_pair("^/", Operator::DIVIDE),
    std::make_pair("^inv", Operator::INVERSE),
};
static const char operandRegex[] = "^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?";
}   // namespace calc
