#include "get_play_request_json.h"
std::string get_play_request_json(const std::string& file_name)
{
    return "/jsonrpc?request={\"jsonrpc\":\"2.0\",\"id\":\"1\",\"method\":\"Player.Open\",\"params\":{\"item\":{\"file\":\"" + file_name + "\"}}}";
}