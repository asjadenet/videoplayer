#include <string>
#include "get_pause_request_json.h"

std::string get_pause_request_json() {
    return "/jsonrpc?request={\"jsonrpc\":\"2.0\",\"method\":\"Player.PlayPause\",\"params\":{\"playerid\":1},\"id\":1}";
}

