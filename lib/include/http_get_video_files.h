//
// Created by tiit on 09.04.2016.
//

#ifndef MYGREATPROJECT_HTTP_GET_VIDEO_FILES_H
#define MYGREATPROJECT_HTTP_GET_VIDEO_FILES_H

#include <string>
#include <vector>
#include "HttpConf.h"

std::vector<std::string> http_get_video_files(const std::string& video_dir, HttpConf& httpConf);

#endif //MYGREATPROJECT_HTTP_GET_VIDEO_FILES_H
