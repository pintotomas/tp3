#include "Request.h"

Request::Request(std::string req) {
	request = nullptr;
	request_size = 1;
    if ((req.length() == NUMBER_COMMAND_LENGTH) && is_digits(req)) {
    	request_size = 3;
        request = new unsigned char[3];
        int myInt(std::stoi(req));
        uint16_t myInt16 = static_cast<uint16_t>(myInt);
        memcpy(&request[0], "n", 1);
        memcpy(&request[1], &myInt16, 2);
    }
    else if (req.compare(HELP_COMMAND) == 0) {
        request = new unsigned char[1];
        memcpy(&request[0], "h", 1);
    }
    else if (req.compare(GIVEUP_COMMAND) == 0) {
    	request = new unsigned char[1];
    	memcpy(&request[0], "s", 1);
	}
 }

Request::~Request() {
	delete[] request;
}
unsigned char* Request::get_request() {
	return request;
}
std::size_t Request::get_size() {
	return request_size;
}