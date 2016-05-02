//
// Created by tiit on 18.04.2016.
//

#ifndef MYGREATPROJECT_HTTPCONF_H
#define MYGREATPROJECT_HTTPCONF_H

#include <string>

class HttpConf {
public:
    void init(std::string host_arg, std::string port_arg, uint_fast32_t timeout_arg);
    std::string host;
    std::string port;
    uint_fast32_t timeout;
};




#endif //MYGREATPROJECT_HTTPCONF_H
