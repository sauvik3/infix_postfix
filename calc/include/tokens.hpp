// Copyright 2025 Sauvik Roy
#pragma once

#include <map>
#include <string>
#include <utility>

namespace calc {
enum Operator {
  OPERAND = 0,
  L_PAR = 1,
  R_PAR = 2,
  ADD = 3,
  SUBTRACT = 4,
  MULTIPLY = 5,
  DIVIDE = 6,
  INVERSE = 7
};
static const std::map<std::string, enum Operator> operatorRegexMap = {
    std::make_pair("^\\+", Operator::ADD),
    std::make_pair("^\\-", Operator::SUBTRACT),
    std::make_pair("^\\*", Operator::MULTIPLY),
    std::make_pair("^/", Operator::DIVIDE),
    std::make_pair("^inv", Operator::INVERSE),
    std::make_pair("^\\(", Operator::L_PAR),
    std::make_pair("^\\)", Operator::R_PAR),
};
static const char operandRegex[] = "^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?";

static const std::map<enum Operator, int> operatorPrecedence = {
    std::make_pair(Operator::ADD, 2),
    std::make_pair(Operator::SUBTRACT, 2),
    std::make_pair(Operator::MULTIPLY, 1),
    std::make_pair(Operator::DIVIDE, 1),
    std::make_pair(Operator::INVERSE, 1),
    std::make_pair(Operator::L_PAR, 0),
    std::make_pair(Operator::R_PAR, 0),
};

}   // namespace calc
