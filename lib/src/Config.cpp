#include <boost/filesystem/path.hpp>
#include <file_exists.h>
#include "Config.h"

void Config::read(const std::string& config_dir, const std::string& app_name, bool ignoreFileExists) {
    config_file = get_config_file_full_name(config_dir, app_name);
    fileExists = file_exists(config_file);
    if(ignoreFileExists && !fileExists)
        return;
    auto json = read_string_from_file(config_file);
    if(json=="")
        return;
    setting = parse_json_settings(json);
    Config::httpConf.host = setting["kodiHostIp"];
    Config::httpConf.port = setting["port"];
    Config::httpConf.timeout = (uint_fast32_t) std::stoi(Config::setting["httpTimeOutMs"]);
}

