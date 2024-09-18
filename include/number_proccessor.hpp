/**
 * @file number_proccessor.hpp
 * @brief
 * @version 1.0.0
 *
 * class to proccess all numbers
 * 
 * 
 *
 */

#ifndef NUMBER_PROCCESSOR_HPP_
#define NUMBER_PROCCESSOR_HPP_


#include <cstring>
#include <iostream>
#include <vector>
#include <string>

#include "converter.hpp"
#include "validator.hpp"

class NumberProcessor{
std::vector<double> numbers;

public:
    void addNumber(const char* str);
    double getSum();
};
#endif