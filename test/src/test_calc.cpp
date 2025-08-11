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

TEST(CalcTest, Expression3) { EXPECT_EQ(calc::eval("2-(-inv(0.5))"), 4); }

TEST(CalcTest, Expression4) { EXPECT_EQ(calc::eval("1/-inv(.25)"), -0.25); }

TEST(CalcTest, Expression5) { EXPECT_EQ(calc::eval("1*(-(3-1))"), -2); }

TEST(CalcTest, Expression6) {
  EXPECT_NEAR(calc::eval("-.2+005.-(1/(3+-inv(2.0--7.5)))*5."), 3.07273, 1e-5);
}
}   // namespace tokenizer_tests
