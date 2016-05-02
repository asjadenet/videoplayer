//
// Created by tiit on 14.04.2016.
//

#ifndef MYGREATPROJECT_CONFIG_H
#define MYGREATPROJECT_CONFIG_H

#include <string>
#include <map>
#include "parse_json_settings.h"
#include "read_string_from_file.h"
#include "get_config_file_full_name.h"
#include "HttpConf.h"

using std::map;
using std::string;

class Config {
public:
    static std::string config_file;
    static map<string, string> setting;
    static void read(const std::string& config_dir, const std::string& app_name, bool ignoreFileExists = false);
    static bool fileExists;
    static HttpConf httpConf;
};


#endif //MYGREATPROJECT_CONFIG_H
