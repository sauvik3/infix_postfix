// Copyright 2025 Sauvik Roy

#include <gtest/gtest.h>

#include "calc.hpp"

namespace tokenizer_tests {

TEST(CalcTest, PositiveNumbers) { EXPECT_EQ(calc::eval("(2) + 3"), 5); }

TEST(CalcTest, NegativeNumbers) { EXPECT_EQ(calc::eval("-2 + (-3)"), -5); }

TEST(CalcTest, MixedNumbers) { EXPECT_EQ(calc::eval("(-2 + 3)"), 1); }

TEST(CalcTest, BracketAssoc) { EXPECT_EQ(calc::eval("(2)-3"), -1); }

TEST(CalcTest, Expression1) { EXPECT_EQ(calc::eval("(-.2)-(+.8)"), -1); }

TEST(CalcTest, Expression2) { EXPECT_EQ(calc::eval("-.25-00.75"), -1); }

TEST(CalcTest, Expression3) { EXPECT_EQ(calc::eval("2-(-inv(0.5))"), 0); }
}   // namespace tokenizer_tests
