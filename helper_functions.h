#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#define DIGITS 10
#define ASCII_DIGITS_START 48
#include <string>
#include <algorithm>
#include <inttypes.h>
//PRE: str is a string of numbers
bool contains_unique_numbers(const std::string &str);

bool is_digits(const std::string &str);
//returns true if str can be represented in uint16
bool str_to_uint16(const char *str);
#endif //HELPERFUNCTIONS_H
