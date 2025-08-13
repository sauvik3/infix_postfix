// Copyright 2025 Sauvik Roy

#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>

#include "tokenize.hpp"
#include "tokens.hpp"

namespace tokenizer_tests {

TEST(TokenizerTest, TokPositiveDouble) {
  std::vector<calc::Token> expect = {
      std::make_pair("1.0", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("1.0"), expect);
}

TEST(TokenizerTest, TokNegativeDouble) {
  std::vector<calc::Token> expect = {
      std::make_pair("-1.0", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("-1.0"), expect);
}

TEST(TokenizerTest, TokPositiveInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("1", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("1"), expect);
}

TEST(TokenizerTest, TokNegativeInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("-1", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("-1"), expect);
}

TEST(TokenizerTest, TokSignedPositiveInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("+1", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("+1"), expect);
}

TEST(TokenizerTest, TokLeadZeroPositiveInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("01", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("01"), expect);
}

TEST(TokenizerTest, TokLeadZeroNegativeInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("-01", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("-01"), expect);
}

TEST(TokenizerTest, TokLeadZeroPositiveDouble) {
  std::vector<calc::Token> expect = {
      std::make_pair("01.0", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("01.0"), expect);
}

TEST(TokenizerTest, TokLeadZeroNegativeDouble) {
  std::vector<calc::Token> expect = {
      std::make_pair("-01.0", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("-01.0"), expect);
}

TEST(TokenizerTest, TokTrailDecPositiveInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("1.", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("1."), expect);
}

TEST(TokenizerTest, TokTrailDecNegativeInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("-1.", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("-1."), expect);
}

TEST(TokenizerTest, TokLeadDecNegativeInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("-.1", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("-.1"), expect);
}

TEST(TokenizerTest, TokLeadDecSignedPositiveInteger) {
  std::vector<calc::Token> expect = {
      std::make_pair("+.1", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("+.1"), expect);
}

TEST(TokenizerTest, TokOperatorAdd) {
  std::vector<calc::Token> expect = {std::make_pair("+", calc::Operator::ADD)};
  EXPECT_EQ(calc::tokenize("+"), expect);
}

TEST(TokenizerTest, TokOperatorSubtract) {
  std::vector<calc::Token> expect = {
      std::make_pair("-", calc::Operator::SUBTRACT)};
  EXPECT_EQ(calc::tokenize("-"), expect);
}

TEST(TokenizerTest, TokOperatorMultiply) {
  std::vector<calc::Token> expect = {
      std::make_pair("*", calc::Operator::MULTIPLY)};
  EXPECT_EQ(calc::tokenize("*"), expect);
}

TEST(TokenizerTest, TokOperatorDivide) {
  std::vector<calc::Token> expect = {
      std::make_pair("/", calc::Operator::DIVIDE)};
  EXPECT_EQ(calc::tokenize("/"), expect);
}

TEST(TokenizerTest, TokOperatorInverse) {
  std::vector<calc::Token> expect = {
      std::make_pair("inv", calc::Operator::INVERSE)};
  EXPECT_EQ(calc::tokenize("inv"), expect);
}

TEST(TokenizerTest, TokOperatorPower) {
  std::vector<calc::Token> expect = {
      std::make_pair("^", calc::Operator::POWER)};
  EXPECT_EQ(calc::tokenize("^"), expect);
}

TEST(TokenizerTest, TokOperatorSqrt) {
  std::vector<calc::Token> expect = {
      std::make_pair("sqrt", calc::Operator::SQRT)};
  EXPECT_EQ(calc::tokenize("sqrt"), expect);
}

TEST(TokenizerTest, TokOperatorAbs) {
  std::vector<calc::Token> expect = {
      std::make_pair("abs", calc::Operator::ABS)};
  EXPECT_EQ(calc::tokenize("abs"), expect);
}

TEST(TokenizerTest, TokOperatorSin) {
  std::vector<calc::Token> expect = {
      std::make_pair("sin", calc::Operator::SIN)};
  EXPECT_EQ(calc::tokenize("sin"), expect);
}

TEST(TokenizerTest, TokOperatorCos) {
  std::vector<calc::Token> expect = {
      std::make_pair("cos", calc::Operator::COS)};
  EXPECT_EQ(calc::tokenize("cos"), expect);
}

TEST(TokenizerTest, TokOperatorTan) {
  std::vector<calc::Token> expect = {
      std::make_pair("tan", calc::Operator::TAN)};
  EXPECT_EQ(calc::tokenize("tan"), expect);
}

TEST(TokenizerTest, TokOperatorLog) {
  std::vector<calc::Token> expect = {
      std::make_pair("log", calc::Operator::LOG)};
  EXPECT_EQ(calc::tokenize("log"), expect);
}

TEST(TokenizerTest, TokOperatorLn) {
  std::vector<calc::Token> expect = {
      std::make_pair("ln", calc::Operator::LN)};
  EXPECT_EQ(calc::tokenize("ln"), expect);
}

TEST(TokenizerTest, TokLeftPar) {
  std::vector<calc::Token> expect = {
      std::make_pair("(", calc::Operator::L_PAR)};
  EXPECT_EQ(calc::tokenize("("), expect);
}

TEST(TokenizerTest, TokRightPar) {
  std::vector<calc::Token> expect = {
      std::make_pair(")", calc::Operator::R_PAR)};
  EXPECT_EQ(calc::tokenize(")"), expect);
}

TEST(TokenizerTest, TokUnaryMinus) {
  std::vector<calc::Token> expect = {
      std::make_pair("2", calc::Operator::OPERAND),
      std::make_pair("-", calc::Operator::SUBTRACT),
      std::make_pair("1", calc::Operator::OPERAND),
      std::make_pair("/", calc::Operator::DIVIDE),
      std::make_pair("-", calc::Operator::NEGATIVE),
      std::make_pair("(", calc::Operator::L_PAR),
      std::make_pair("-3", calc::Operator::OPERAND),
      std::make_pair("+", calc::Operator::ADD),
      std::make_pair("1.5", calc::Operator::OPERAND),
      std::make_pair(")", calc::Operator::R_PAR),
      std::make_pair("^", calc::Operator::POWER),
      std::make_pair("2", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("2-1/-(-3+1.5)^2"), expect);
}

TEST(TokenizerTest, TokPowerWithUnaryMinus) {
  std::vector<calc::Token> expect = {
      std::make_pair("16", calc::Operator::OPERAND),
      std::make_pair("/", calc::Operator::DIVIDE),
      std::make_pair("-2", calc::Operator::OPERAND),
      std::make_pair("^", calc::Operator::POWER),
      std::make_pair("4", calc::Operator::OPERAND)};
  EXPECT_EQ(calc::tokenize("16/-2^4"), expect);
}
}   // namespace tokenizer_tests
