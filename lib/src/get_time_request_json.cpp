#include <string>
#include "get_time_request_json.h"

std::string get_time_request_json() {
    return "/jsonrpc?request={\"jsonrpc\":\"2.0\",\"method\":\"Player.GetProperties\",\"params\":{\"playerid\":1,\"properties\":[\"time\",\"totaltime\"]},\"id\":\"1\"}";
}

