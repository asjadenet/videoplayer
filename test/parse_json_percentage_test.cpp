#include <parse_json_percentage.h>
#include "gtest/gtest.h"

TEST(ParsePercentageTest, zero)
{
    auto actual = parse_json_percentage("{\"id\":\"1\",\"jsonrpc\":\"2.0\",\"result\":{\"percentage\":0}}");
    EXPECT_EQ(0, actual);
}

TEST(ParsePercentageTest, nonZero)
{
    auto actual = parse_json_percentage("{\"id\":\"1\",\"jsonrpc\":\"2.0\",\"result\":{\"percentage\":5.092235088348389}}");
    EXPECT_EQ(5.092235088348389, actual);
}