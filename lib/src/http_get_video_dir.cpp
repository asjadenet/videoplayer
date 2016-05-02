#include <HttpGet.h>
#include <parse_video_dir.h>
#include <Config.h>
#include "http_get_video_dir.h"

std::string http_get_video_dir(const std::string& host, const std::string& port) {
    auto result = HttpGet::execute(host, port,
                                   "/jsonrpc?request={\"jsonrpc\":\"2.0\",\"method\":\"Files.GetSources\",\"params\":{\"media\":\"video\"},\"id\":1}",
                                   1000);
    return parse_video_dir(result.body);
//    return result.body;
//     return std::to_string(result.status_code);
}

