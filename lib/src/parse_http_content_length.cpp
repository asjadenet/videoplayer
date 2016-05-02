//
// Created by tiit on 11.04.2016.
//
#include <sstream>
#include "parse_http_content_length.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

int parse_http_content_length(const std::string& header_str) {
    std::istringstream resp(header_str);
    std::string header;
    std::string::size_type index;
    int result = 0;
    while (std::getline(resp, header) && header != "\r") {
        index = header.find(':', 0);
        if(index != std::string::npos) {
            std::string value =  boost::algorithm::trim_copy(header.substr(index + 1));
            std::string name = boost::algorithm::trim_copy(header.substr(0, index));
            if(name == "Content-Length")
            {
                result = std::stoi(value);
                break;
            }
        }
    }

    return result;
}

