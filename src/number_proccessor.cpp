  #include "number_proccessor.hpp"
  void NumberProcessor::addNumber(const char* str) {
        if (Validator::isDecimal(str)) {
            numbers.push_back(Converter::cstringToDouble(str));
        } else if (Validator::isHexadecimal(str)) {
            numbers.push_back(Converter::hexToDouble(str));
        } else {
            throw std::invalid_argument(std::string(str) + " is not a valid number");
        }
    }
double NumberProcessor::getSum() {
        double sum = 0;
        for (const auto& num : numbers) {
            sum += num;
        }
        return sum;
    }


