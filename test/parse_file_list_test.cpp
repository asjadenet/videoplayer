#include <parse_file_list.h>
#include "gtest/gtest.h"

TEST(ParseFileListTest, Simple)
{
    std::string json = "{\"id\":1,\"jsonrpc\":\"2.0\",\"result\":{\"files\":[{\"file\":\"I:\\\\videos\\\\video 4.mp4\",\"filetype\":\"file\",\"label\":\"video 4.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video five.mp4\",\"filetype\":\"file\",\"label\":\"video five.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video one.mp4\",\"filetype\":\"file\",\"label\":\"video one.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video three.mp4\",\"filetype\":\"file\",\"label\":\"video three.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video two.mp4\",\"filetype\":\"file\",\"label\":\"video two.mp4\",\"type\":\"unknown\"}],\"limits\":{\"end\":5,\"start\":0,\"total\":5}}}";
    auto files = parse_file_list(json);
    EXPECT_EQ(5, files.size());
    EXPECT_EQ("I:/videos/video 4.mp4", files[0]);
    EXPECT_EQ("I:/videos/video two.mp4", files[4]);
}


TEST(ParseFileListTest, BadFormat)
{
    try {
        std::string json = "{\"id\":1,\"jsonrpc\":\"2.0\",\"res9ult\":{\"files\":[{\"file\":\"I:\\\\videos\\\\video 4.mp4\",\"filetype\":\"file\",\"label\":\"video 4.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video five.mp4\",\"filetype\":\"file\",\"label\":\"video five.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video one.mp4\",\"filetype\":\"file\",\"label\":\"video one.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video three.mp4\",\"filetype\":\"file\",\"label\":\"video three.mp4\",\"type\":\"unknown\"},{\"file\":\"I:\\\\videos\\\\video two.mp4\",\"filetype\":\"file\",\"label\":\"video two.mp4\",\"type\":\"unknown\"}],\"limits\":{\"end\":5,\"start\":0,\"total\":5}}}";
        parse_file_list(json);
        FAIL() << "Expected std::invalid_argument";
    }
    catch ( const std::invalid_argument& e )
    {
        ASSERT_STREQ("result member is missing", e.what());
    }
}