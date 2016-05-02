#include <parse_video_dir.h>
#include <HttpGet.h>
#include <Config.h>
#include <ostream>
#include <iostream>
#include "http_get_player_percentage.h"

std::string http_get_player_percentage(HttpConf& httpConf)
{
    auto result = HttpGet::execute(httpConf.host, httpConf.port,
                                   "/jsonrpc?request={\"jsonrpc\":\"2.0\",\"method\":\"Player.GetProperties\",\"params\":{\"playerid\":1,\"properties\":[\"percentage\"]},\"id\":\"1\"}",
                                   httpConf.timeout);
//    std::cout << result.body << std::endl;
    return result.body;
}