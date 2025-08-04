#include <gtest/gtest.h>
#include "add.hpp"

TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add::add(2, 3), 5);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add::add(-2, -3), -5);
}

TEST(AddTest, MixedNumbers) {
    EXPECT_EQ(add::add(-2, 3), 1);
}
