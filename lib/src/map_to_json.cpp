#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include "map_to_json.h"

using namespace rapidjson;

std::string map_to_json(map<string, string> m) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();

    for(auto const &item : m) {
        writer.String(item.first.c_str() );
        writer.String(item.second.c_str());
    }

    writer.EndObject();
    return string( s.GetString() );
}

