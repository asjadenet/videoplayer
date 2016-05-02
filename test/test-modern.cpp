#include "modern.h"
#include "gtest/gtest.h"

TEST(modernTest, SimpleModern)
{
int actual = modern(1, 2);
EXPECT_EQ(120, actual);
}

TEST(modernTest, NextModern)
{
    int actual = modern(2, 3);
    EXPECT_EQ(168, actual);
}