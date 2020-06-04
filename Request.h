#ifndef REQUEST_H
#define REQUEST_H
#define HELP_COMMAND "AYUDA"
#define GIVEUP_COMMAND "RENDIRSE"
#include "helper_functions.h"
#include <memory.h>
#include <arpa/inet.h>
#include <string>
#include <memory>
class Request {
 public:
    explicit Request(const std::string req);
    ~Request();
    /* Devuelve un char seguido de un uint_16t 
    (si el primer char es una 'n') casteado a unsigned char*
    */
	const unsigned char* get_request() const;
	/*
	Devuelve la cantidad de bytes del request devuelto
	por get_request()
	*/
	const std::size_t get_size() const;

 private:
	std::unique_ptr<unsigned char[]> request;
 	std::size_t request_size;
 };
#endif //REQUEST_H
