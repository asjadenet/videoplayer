#include "gtest/gtest.h"
#include "get_play_request_json.h"

TEST(playRequestTest, simple)
{
    auto actual = get_play_request_json("proov.mp4");
    EXPECT_EQ("/jsonrpc?request={\"jsonrpc\":\"2.0\",\"id\":\"1\",\"method\":\"Player.Open\",\"params\":{\"item\":{\"file\":\"proov.mp4\"}}}", actual);
}