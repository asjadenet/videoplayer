//
// Created by tiit on 09.04.2016.
//

#ifndef MYGREATPROJECT_HTTPGET_H
#define MYGREATPROJECT_HTTPGET_H
#include <iosfwd>
#include <vector>
#include <string>
#include "HttpGetResult.h"
#include "HttpConf.h"

class HttpGet {
public:
    static HttpGetResult execute(const std::string& host, const std::string& port, const std::string& url_path, unsigned int timeout);
    static HttpGetResult execute(const std::string& url_path, HttpConf& httpConf);
};


#endif //MYGREATPROJECT_HTTPGET_H
