#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <iostream>
#include <vector>
#include <boost/algorithm/string/replace.hpp>
#include "parse_file_list.h"

using namespace rapidjson;
using namespace std;



std::vector<std::string> parse_file_list(const std::string& json)
{
    std::vector<std::string> result;
    if(json=="")
        return result;

    StringStream ss(json.c_str());
    Document d;
    d.ParseStream(ss);

    if(!d.HasMember("result"))
    {
        throw std::invalid_argument("result member is missing");
    }
//    Value& s = d["result"];
    Value& files_json = d["result"]["files"];
    if(!files_json.IsArray())
    {
        throw std::invalid_argument("files array is missing");
    }
    for (rapidjson::SizeType i = 0; i < files_json.Size(); i++) {
        std::string file = files_json[i]["file"].GetString();
        boost::replace_all(file, "\\", "/");
        result.push_back(file);
    }
    return result;
}


