//
// Created by tiit on 09.04.2016.
//


#include <boost/filesystem/path.hpp>
#include <iostream>
#include <boost/algorithm/string/replace.hpp>
#include "get_file_names_from_path.h"

std::vector<std::string> get_file_names_from_path(const std::vector<std::string> files_with_path) {
    std::vector<std::string> result;
    for(auto file:files_with_path)
    {
        boost::filesystem::path p(file);
        result.push_back(p.filename().string());
    }
    return result;
}
