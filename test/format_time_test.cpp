#include <parse_file_list.h>
#include <format_time.h>
#include "gtest/gtest.h"

TEST(FormatTimeTest, Simple1)
{
    PlayerTime playerTime;
    playerTime.seconds=10;
    playerTime.hours=11;
    playerTime.minutes=12;
    auto actual = format_time(playerTime);
    EXPECT_EQ("11:12:10", actual);
}


TEST(FormatTimeTest, Simple2)
{
    PlayerTime playerTime;
    playerTime.seconds=20;
    playerTime.hours=21;
    playerTime.minutes=22;
    auto actual = format_time(playerTime);
    EXPECT_EQ("21:22:20", actual);
}

TEST(FormatTimeTest, Simple0)
{
    PlayerTime playerTime;
    playerTime.seconds=3;
    playerTime.hours=1;
    playerTime.minutes=2;
    auto actual = format_time(playerTime);
    EXPECT_EQ("01:02:03", actual);
}