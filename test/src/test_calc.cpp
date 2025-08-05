// Copyright 2025 Sauvik Roy

#include <gtest/gtest.h>

#include "calc.hpp"

TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(calc::eval("2, 3"), 5);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(calc::eval("-2, -3"), 5);
}

TEST(AddTest, MixedNumbers) {
    EXPECT_EQ(calc::eval("-2, 3"), 5);
}
