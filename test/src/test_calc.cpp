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

TEST(CalcTest, Expression7) { EXPECT_EQ(calc::eval("16/-2^4"), 1); }

TEST(CalcTest, Expression8) {
  EXPECT_EQ(calc::eval("abs(sin(-0.5))"), calc::eval("sin(0.5)"));
}

TEST(CalcTest, Expression9) { EXPECT_EQ(calc::eval("sin0.5^2+cos0.5^2"), 1); }

TEST(CalcTest, Expression10) {
  EXPECT_EQ(calc::eval("sin0.5/cos0.5"), calc::eval("tan0.5"));
}

TEST(CalcTest, Expression11) {
  EXPECT_EQ(calc::eval("1+inv(tan0.5^2)"), calc::eval("-inv(-sin0.5^2)"));
}

TEST(CalcTest, Expression12) {
  EXPECT_EQ(calc::eval("sqrt(2^4)"), 4);
}

TEST(CalcTest, Expression13) {
  EXPECT_EQ(calc::eval("log(100)"), 2);
}

TEST(CalcTest, Expression14) {
  EXPECT_EQ(calc::eval("ln(1)"), 0);
}
}   // namespace tokenizer_tests
