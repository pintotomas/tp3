#include "servidor/server_Server.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "helpers/helper_functions.h"

#define NUMBERS_LENGTH 3
#define ARGC 3
#define SUCCESS 0
#define ERROR 1

//Devuelve true si el archivo contiene solo lineas
//cuyo contenido son numeros de 3 digitos sin repetir
//El archivo stream quedara apuntando al inicio del archivo
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
	stream.clear();
	stream.seekg(0, std::ios::beg);
    return true;
}
//PRE: El archivo contiene el formato valido
//Devuelve los numeros en el archivo 
std::vector<int> parse_numbers(std::ifstream& stream) {
    std::vector<int> numbers;
    std::string str; 
	while (std::getline(stream, str)) {
		numbers.push_back(stoi(str));
	}
    return numbers;
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
    std::vector<int> numbers = parse_numbers(numbers_file);
    Server server(port, numbers);
    server.run();
    return SUCCESS;
}
