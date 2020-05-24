#include "server_Server.h"
#include <fstream>
#include <iostream>
#include "helper_functions.h"

#define NUMBERS_LENGTH 3
#define ARGC 3
#define SUCCESS 0
#define ERROR 1

bool valid_file(std::ifstream& stream) {
    if (!stream) {
      std::cerr << "Error: archivo invalido." << std::endl;
      return false;
    }
    std::string str;
	while (std::getline(stream, str)) {
		if ((str.length() != NUMBERS_LENGTH) || (!is_digits(str))) {
			std::cerr << "Error: archivo con números fuera de rango." << std::endl;
			return false;
		}
		if (!contains_unique_numbers(str)) {
			std::cerr << "Error: formato de los números inválidos." << std::endl;
			return false;
		}
	}
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != ARGC) { 
    	std::cerr << "Error: argumentos invalidos." << std::endl;
    	return ERROR;
    }
    std::ifstream numbers_file(argv[2]);
    if (!valid_file(numbers_file)) {
    	return ERROR;
    }
    char *port = argv[1];
    char *numbers_file2 = argv[2];
    Server server(port, numbers_file2);
    server.run();
    return SUCCESS;
}
