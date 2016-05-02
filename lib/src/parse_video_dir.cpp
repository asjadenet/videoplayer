#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON


#include <iostream>
#include <vector>
#include <boost/algorithm/string/replace.hpp>
#include "parse_video_dir.h"

using namespace rapidjson;
using namespace std;

std::string parse_video_dir(const std::string& json) {
    if (json == "")
        return "";

    StringStream ss(json.c_str());
    Document d;
    d.ParseStream(ss);

    if (!d.HasMember("result")) {
        throw std::invalid_argument("result member is missing");
    }
    Value &files_json = d["result"]["sources"];
    if(!files_json.IsArray())
    {
        throw std::invalid_argument("files array is missing");
    }
    rapidjson::SizeType i = 0;
    std::string file = files_json[i]["file"].GetString();
    boost::replace_all(file, "\\", "/");
    return file;
}

