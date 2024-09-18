/**
 * @file validator.hpp
 * @brief
 * @version 1.0.0
 *
 * class to test if passed input is decimal or hexadecimal number 
 * 
 * 
 *
 */

#ifndef VALIDATOR_HPP_
#define VALIDATOR_HPP_


#include <cstring>
#include <iostream>
#include <vector>
#include <string>


class Validator {

    public:
        static bool isDecimal(const char* str);
        static bool isHexadecimal(const char* str);
        static bool isValidNumber(const char* str);

    private:
        static bool isDecimalDigit(char character);
        static bool isHexadecimalDigit(char character);
};

#endif                                                                                  