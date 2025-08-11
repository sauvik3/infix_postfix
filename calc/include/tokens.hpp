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
  NEGATIVE = 3,
  ADD = 4,
  SUBTRACT = 5,
  MULTIPLY = 6,
  DIVIDE = 7,
  INVERSE = 8
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
static const char operandRegex[] = R"(^[+-]?(?:\d+(?:\.\d*)?|\.\d+))";

static const std::map<enum Operator, int> operatorPrecedence = {
    std::make_pair(Operator::ADD, 4),
    std::make_pair(Operator::SUBTRACT, 4),
    std::make_pair(Operator::MULTIPLY, 3),
    std::make_pair(Operator::DIVIDE, 3),
    std::make_pair(Operator::NEGATIVE, 2),
    std::make_pair(Operator::INVERSE, 1),
    std::make_pair(Operator::L_PAR, 0),
    std::make_pair(Operator::R_PAR, 0),
};

}   // namespace calc
