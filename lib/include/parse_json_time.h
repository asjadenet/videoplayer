//
// Created by tiit on 18.04.2016.
//

#ifndef MYGREATPROJECT_PARSE_JSON_TIME_H
#define MYGREATPROJECT_PARSE_JSON_TIME_H

#include "PlayerTime.h"
#include <string>
#include <map>

std::map<std::string, PlayerTime>  parse_json_time(const std::string& json);
#endif //MYGREATPROJECT_PARSE_JSON_TIME_H
