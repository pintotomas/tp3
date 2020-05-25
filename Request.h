#ifndef REQUEST_H
#define REQUEST_H
#define HELP_COMMAND "AYUDA"
#define GIVEUP_COMMAND "RENDIRSE"
#include "helper_functions.h"
#include <memory.h>
#include <arpa/inet.h>
#include <string>

class Request {
 public:
    explicit Request(std::string req);
    ~Request();
	unsigned char* get_request();
	std::size_t get_size();

 private:
 	unsigned char* request;
 	std::size_t request_size;
 };
#endif //REQUEST_H
