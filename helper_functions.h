#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#define DIGITS 10
#define ASCII_DIGITS_START 48
#include <string>
#include <algorithm>
#include <inttypes.h>
//PRE: str is a string of numbers
const bool contains_unique_numbers(const std::string &str);

const bool is_digits(const std::string &str);
//Devuelve true si se puede transformar str a uint16_t
const bool str_to_uint16(const char *str);
#endif //HELPERFUNCTIONS_H
