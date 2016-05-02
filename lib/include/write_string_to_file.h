//
// Created by tiit on 13.04.2016.
//

#ifndef MYGREATPROJECT_WRITE_STRING_TO_FILE_H
#define MYGREATPROJECT_WRITE_STRING_TO_FILE_H

#include <string>
#include <boost/filesystem/path.hpp>
void write_string_to_file(const boost::filesystem::path &file_name, const std::string& text);
void create_dir_if_not_exists(const boost::filesystem::path &file_name);
#endif //MYGREATPROJECT_WRITE_STRING_TO_FILE_H
