#include <boost/filesystem/path.hpp>
#include "get_config_file_full_name.h"

namespace fs = boost::filesystem;

std::string get_config_file_full_name(const std::string& data_dir, const std::string& app_name)
{
    std::string result;
    std::string data_dir_string = (std::string)data_dir;
    fs::path full_path_path (data_dir_string);
    fs::path fpath (app_name+".json");
    auto fname_with_path = full_path_path/fpath;
    result = fname_with_path.string();
    return result;
}