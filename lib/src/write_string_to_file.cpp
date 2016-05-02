//
// Created by tiit on 13.04.2016.
//

#include <fstream>
#include <iostream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include "write_string_to_file.h"


void write_string_to_file(const boost::filesystem::path &file_name, const std::string& text)
{
    create_dir_if_not_exists(file_name);
    std::ofstream outfile(file_name.string());
    if(!outfile.is_open()) {
        std::cerr << "Couldn't open " << file_name << std::endl;
        return;
    }
    outfile << text << std::endl;
    outfile.close();
}

void create_dir_if_not_exists(const boost::filesystem::path &file_name) {
    boost::filesystem::path file_name_path (file_name);
    boost::filesystem::path dir = file_name_path.parent_path();
    if(!(exists(dir))) {
        create_directory(dir);
    }
}