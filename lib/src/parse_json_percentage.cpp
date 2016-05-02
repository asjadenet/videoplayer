#include "rapidjson/document.h"     // rapidjson's DOM-style API


#include <iostream>
#include <vector>
#include <boost/algorithm/string/replace.hpp>
#include "parse_json_percentage.h"

using namespace rapidjson;
using namespace std;

double parse_json_percentage(const std::string& json)
{
    if(json=="")
        return 0;

    StringStream ss(json.c_str());
    Document d;
    d.ParseStream(ss);

    if(!d.HasMember("result"))
    {
        throw std::invalid_argument("result member is missing");
    }
    return d["result"]["percentage"].GetDouble();
}