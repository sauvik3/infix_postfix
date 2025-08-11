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
}   // namespace tokenizer_tests
