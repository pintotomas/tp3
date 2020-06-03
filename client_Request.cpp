#include "Request.h"
#include <iostream>
Request::Request(const std::string req) {
	//request = nullptr;
	request_size = 1;
    if (is_digits(req)) {
    	request_size = 3;
        request = std::unique_ptr<unsigned char[]>{ new unsigned char[3] };

        int myInt(std::stoi(req));
        uint16_t myInt16 = htons(static_cast<uint16_t>(myInt));
        memcpy(&request[0], "n", 1);
        memcpy(&request[1], &myInt16, 2);
    } else if (req.compare(HELP_COMMAND) == 0) {
        request = std::unique_ptr<unsigned char[]>{ new unsigned char[1] };

        memcpy(&request[0], "h", 1);
    } else if (req.compare(GIVEUP_COMMAND) == 0) {
        request = std::unique_ptr<unsigned char[]>{ new unsigned char[1] };
    	memcpy(&request[0], "s", 1);
	}
 }

Request::~Request() {
}
const unsigned char* Request::get_request() const {
    return request.get();
}
const std::size_t Request::get_size() const {
	return request_size;
}
