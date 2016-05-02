#include <parse_json_time.h>
#include "gtest/gtest.h"

using std::string;
using std::map;


TEST(ParseTimeTest, BadArg)
{
    try {
        parse_json_time("{\"id\":\"1\",\"jsonrpc\":\"2.0\",\"res2ult\":{\"time\":{\"hours\":0,\"milliseconds\":159,\"minutes\":0,\"seconds\":11},\"totaltime\":{\"hours\":0,\"milliseconds\":480,\"minutes\":15,\"seconds\":38}}}");
        FAIL() << "Expected std::invalid_argument";
    }
    catch ( const std::invalid_argument& e )
    {
        ASSERT_STREQ("result member is missing", e.what());
    }
}

TEST(ParseTimeTest, timeAndTotalTime)
{
    map<string, PlayerTime> actual = parse_json_time("{\"id\":\"1\",\"jsonrpc\":\"2.0\",\"result\":{\"time\":{\"hours\":0,\"milliseconds\":159,\"minutes\":0,\"seconds\":11},\"totaltime\":{\"hours\":0,\"milliseconds\":480,\"minutes\":15,\"seconds\":38}}}");
    PlayerTime time = actual["time"];
    EXPECT_EQ(159, time.milliseconds);
    EXPECT_EQ(11, time.seconds);
    EXPECT_EQ(0, time.minutes);
    EXPECT_EQ(0, time.hours);

    time = actual["totaltime"];
    EXPECT_EQ(480, time.milliseconds);
    EXPECT_EQ(38, time.seconds);
    EXPECT_EQ(15, time.minutes);
    EXPECT_EQ(0, time.hours);
}