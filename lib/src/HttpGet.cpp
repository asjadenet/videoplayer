#include <ostream>
#include <iostream>
#include <sstream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <parse_http_content_length.h>
#include <Config.h>
#include "HttpGet.h"


HttpGetResult HttpGet::execute(const std::string& host, const std::string& port, const std::string& url_path, unsigned int timeout) {
    HttpGetResult result;
    try {
        using namespace boost::asio::ip;

        std::string url_path_converted(url_path);
        boost::replace_all(url_path_converted, " ", "%20");

        tcp::iostream request_stream;
        if (timeout > 0) {
            request_stream.expires_from_now(boost::posix_time::milliseconds(timeout));
        }
        request_stream.connect(host, port);
        if (!request_stream) {
            result.status_code = -1;
        }
        request_stream << "GET " << url_path_converted << " HTTP/1.0\r\n";
        request_stream << "Host: " << host << "\r\n";
        request_stream << "Accept: */*\r\n";
        request_stream << "Cache-Control: no-cache\r\n";
        request_stream << "Connection: close\r\n\r\n";
        request_stream.flush();
        std::string line1;
        std::getline(request_stream, line1);
        if (!request_stream) {
            result.status_code = -2;
        }
        std::stringstream response_stream(line1);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);
        if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
            result.status_code = -1;
        }

        result.status_code = (int) status_code;

        std::string header;
        std::ostringstream header_stream;
        while (std::getline(request_stream, header) && header != "\r") {
            header_stream << header << "\n";
        }
        result.header = header_stream.str();
//        std::getline(request_stream, body, '}'); -- saab lugeda teatud märgini
        int content_length = parse_http_content_length(result.header);
        std::string body((unsigned int) content_length, ' ');
        request_stream.read(&body[0], content_length);
        result.body = body;
        return result;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        result.status_code = -3;
        return result;
    }
}

HttpGetResult HttpGet::execute(const std::string& url_path, HttpConf &httpConf) {
    return execute(httpConf.host, httpConf.port, url_path, httpConf.timeout);
}







