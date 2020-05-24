#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#define DIGITS 10
#define ASCII_DIGITS_START 48
#include <string>
#include <algorithm>
//PRE: str is a string of numbers
bool contains_unique_numbers(const std::string &str);

bool is_digits(const std::string &str);

#endif //HELPERFUNCTIONS_H
