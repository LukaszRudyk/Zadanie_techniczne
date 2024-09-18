#include "converter.hpp"
  
 
double  Converter::cstringToDouble(const char* str) {
        double result = 0.0;
        double divisor = 1.0;
        bool isNegative = false;
        bool afterDecimal = false;

        if (*str == '-') {
            isNegative = true;
            str++;
        }

        while (*str) {
            if (*str == '.') {
                afterDecimal = true;
            } else if (*str >= '0' && *str <= '9') {
                if (afterDecimal) {
                    divisor *= 10.0;
                    result = result + (*str - '0') / divisor;
                } else {
                    result = result * 10.0 + (*str - '0');
                }
            } else {
                break;
            }
            str++;
        }
        return isNegative ? -result : result;
    }

double Converter::hexToDouble(const char* str) {
    double result = 0.0;
    bool afterDecimal = false;
    double divisor = 1.0;

    str += 2; 

    while (*str) {
        if (*str == '.') {
            afterDecimal = true;
        } else {
            int value = 0;
            if (*str >= '0' && *str <= '9') {
                value = *str - '0';
            } else if (*str >= 'a' && *str <= 'f') {
                value = *str - 'a' + 10;
            } else if (*str >= 'A' && *str <= 'F') {
                value = *str - 'A' + 10;
            }

            if (afterDecimal) {
                divisor *= 16.0;
                result += value / divisor;
            } else {
                result = result * 16 + value;
            }
        }
        str++;
    }
    return result;
}
 void Converter::doubleToCstring(double num, char* str, int precision) {
    int index = 0;
    if (num < 0) {
        str[index++] = '-';
        num = -num;
    }
    int intPart = static_cast<int>(num);
    double fractionPart = num - intPart;
    if (intPart == 0) {
        str[index++] = '0';
    } else {
        int divisor = 1;
        while (intPart / divisor >= 10) {
            divisor *= 10;
        }

        while (divisor > 0) {
            int digit = intPart / divisor;
            str[index++] = '0' + digit;
            intPart %= divisor;
            divisor /= 10;
        }
    }
    if (precision > 0) {
        str[index++] = '.';
        for (int i = 0; i < precision; ++i) {
            fractionPart *= 10;
            int fractionDigit = static_cast<int>(fractionPart);
            str[index++] = '0' + fractionDigit;
            fractionPart -= fractionDigit;
        }
        if (fractionPart >= 0.5) {
            int i = index - 1;
            while (i >= 0 && str[i] == '9') {
                str[i--] = '0';
            }
            if (i >= 0 && str[i] != '.') {
                str[i]++;
            } else {
                for (int j = index; j > 0; --j) {
                    str[j] = str[j - 1];
                }
                str[0] = '1';
                index++;
            }
        }
    }

    str[index] = '\0';
}
