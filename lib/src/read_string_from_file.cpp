#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "read_string_from_file.h"

std::string read_string_from_file(const std::string& file_name)
{
    std::ifstream infile(file_name);
    if(!infile.is_open()) {
        std::string errorMessage = std::string("Ei saanud avada faili ")+file_name;
        throw std::runtime_error(errorMessage);
    }

    std::stringstream buffer;
    buffer << infile.rdbuf();
    infile.close();
    return buffer.str();
}