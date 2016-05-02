#include <parse_video_dir.h>
#include "gtest/gtest.h"

TEST(ParseVideoDirTest, simple)
{
    auto actual = parse_video_dir("{\"id\":1,\"jsonrpc\":\"2.0\",\"result\":{\"limits\":{\"end\":1,\"start\":0,\"total\":1},\"sources\":[{\"file\":\"I:\\\\videos\\\\\",\"label\":\"videos\"}]}}");
    EXPECT_EQ("I:/videos/", actual);
}

TEST(ParseVideoDirTest, BadArg)
{
    try {
        parse_video_dir("{\"id\":1,\"jsonrpc\":\"2.0\",\"resu3lt\":{\"limits\":{\"end\":1,\"start\":0,\"total\":1},\"sources\":[{\"file\":\"I:\\\\videos\\\\\",\"label\":\"videos\"}]}}");
        FAIL() << "Expected std::invalid_argument";
    }
    catch ( const std::invalid_argument& e )
    {
        ASSERT_STREQ("result member is missing", e.what());
    }
}


