#include "HttpConf.h"
void HttpConf::init(std::string host_arg, std::string port_arg, uint_fast32_t timeout_arg) {
    host = host_arg;
    port = port_arg;
    timeout = timeout_arg;
}