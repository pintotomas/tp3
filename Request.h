#ifndef REQUEST_H
#define REQUEST_H
#define HELP_COMMAND "AYUDA"
#define GIVEUP_COMMAND "RENDIRSE"
#define NUMBER_COMMAND_LENGTH 3
#include "helper_functions.h"
#include <memory.h>

class Request {
 public:
    Request(std::string req);
    ~Request();
	unsigned char* get_request();
	unsigned int get_size();

 private:
 	unsigned char* request;
 	unsigned int request_size;

 };
#endif //REQUEST_H
