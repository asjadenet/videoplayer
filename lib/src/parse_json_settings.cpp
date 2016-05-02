#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON


#include <iostream>
#include <vector>
#include <boost/algorithm/string/replace.hpp>

#include "parse_json_settings.h"

using namespace rapidjson;
using namespace std;


map<string, string> parse_json_settings(string json)
{
    map<string, string> m;
    StringStream ss(json.c_str());
    Document d;
    d.ParseStream(ss);
    assert(d.IsObject());

    for(rapidjson::Value::ConstMemberIterator it=d.MemberBegin(); it != d.MemberEnd(); it++) {
        std::string value = it->value.GetString();
        std::string name = it->name.GetString();
        m.insert(std::pair<string, string>(name, value));
    }
    return m;
}