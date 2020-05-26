#include "helper_functions.h"
#include <iostream>

const bool contains_unique_numbers(const std::string &str) {
    bool numbers[DIGITS] = { 0 }; 
    for (unsigned int i = 0; i < str.length(); i++) { 
    	int n = (int) str[i] - ASCII_DIGITS_START;
        if (numbers[n] == true) 
            return false; 
        numbers[n] = true; 
    } 
    return true; 
}

const bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

const bool str_to_uint16(const char *str)
{
  char *end;
  errno = 0;
  intmax_t val = strtoimax(str, &end, 10);
  if (errno == ERANGE || val < 0 || val > UINT16_MAX ||
   end == str || *end != '\0')
    return false;
  return true;
}
