#include <HttpGet.h>
#include <iostream>
#include <Config.h>
#include <parse_file_list.h>
#include "http_get_video_files.h"
std::vector<std::string> http_get_video_files(const std::string& video_dir, HttpConf& httpConf)
{
    auto result = HttpGet::execute("/jsonrpc?request={\"jsonrpc\":\"2.0\",\"method\":\"Files.GetDirectory\",\"params\":{\"directory\":\""+video_dir+"\",\"media\":\"video\"},\"id\":1}", httpConf);
//    std::cout << result.header << std::endl;
//    std::cout << result.body << std::endl;
    auto files = parse_file_list(result.body);
    return files;
}