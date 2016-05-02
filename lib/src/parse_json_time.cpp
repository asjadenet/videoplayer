#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include <iostream>
#include <vector>
#include <boost/algorithm/string/replace.hpp>
#include <PlayerTime.h>
#include <map>

using namespace rapidjson;
using namespace std;

std::map<std::string, PlayerTime>  parse_json_time(const std::string& json)
{
    map<string, PlayerTime> m;
    PlayerTime result;
    result.milliseconds = 0;
    result.hours = 0;
    result.minutes = 0;
    result.seconds = 0;
    if(json=="")
        return m;

    StringStream ss(json.c_str());
    Document d;
    d.ParseStream(ss);

    if(!d.HasMember("result"))
    {
        throw std::invalid_argument("result member is missing");
    }
    Value& time = d["result"]["time"];
    result.milliseconds = time["milliseconds"].GetInt();
    result.seconds = time["seconds"].GetInt();
    result.minutes = time["minutes"].GetInt();
    result.hours = time["hours"].GetInt();
    m.insert(std::pair<string, PlayerTime>("time", result));

    PlayerTime result2;
    time = d["result"]["totaltime"];
    result2.milliseconds = time["milliseconds"].GetInt();
    result2.seconds = time["seconds"].GetInt();
    result2.minutes = time["minutes"].GetInt();
    result2.hours = time["hours"].GetInt();
    m.insert(std::pair<string, PlayerTime>("totaltime", result2));

    return m;
}