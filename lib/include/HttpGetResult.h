//
// Created by tiit on 09.04.2016.
//

#ifndef MYGREATPROJECT_HTTPGETRESULT_H
#define MYGREATPROJECT_HTTPGETRESULT_H

#include <string>

class HttpGetResult {
public:
    int status_code;
    std::string body;
    std::string header;
};


#endif //MYGREATPROJECT_HTTPGETRESULT_H
