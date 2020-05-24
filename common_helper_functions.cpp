#include "helper_functions.h"
#include <iostream>

bool contains_unique_numbers(const std::string &str) {
    bool numbers[DIGITS] = { 0 }; 
    for (unsigned int i = 0; i < str.length(); i++) { 
    	int n = (int) str[i] - ASCII_DIGITS_START;
        if (numbers[n] == true) 
            return false; 
        numbers[n] = true; 
    } 
    return true; 
}

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
