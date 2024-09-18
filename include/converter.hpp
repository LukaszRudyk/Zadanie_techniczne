/**
 * @file converter.hpp
 * @brief
 * @version 1.0.0
 *
 * class to test if passed input is decimal or hexadecimal number 
 * 
 * 
 *
 */

#ifndef CONVERTER_HPP_
#define CONVERTER_HPP_


#include <cstring>
#include <iostream>
#include <vector>
#include <string>

class Converter{

public:
    static double cstringToDouble(const char* str);
    static double hexToDouble(const char* str);
    static void doubleToCstring(double number,char* str, int precision);


};
#endif