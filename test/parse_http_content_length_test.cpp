#include "gtest/gtest.h"
#include "parse_http_content_length.h"

TEST(parseContentLengthTest, simple)
{
    auto actual = parse_http_content_length("Connection: close\r\n"
                                                    "Content-Type: application/json\r\n"
                                                    "Content-Length: 924\r\n"
                                                    "Cache-Control: private, max-age=0, no-cache\r\n"
                                                    "Accept-Ranges: none\r\n"
                                                    "Date: Mon, 11 Apr 2016 06:04:35 GMT\r\n\r\n");
    EXPECT_EQ(924, actual);
}