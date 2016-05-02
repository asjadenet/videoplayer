#include <string>
#include "get_stop_request_json.h"
std::string get_stop_request_json()
{
    return "/jsonrpc?request={\"jsonrpc\":\"2.0\",\"method\":\"Player.Stop\",\"params\":{\"playerid\":1},\"id\":1}";
}