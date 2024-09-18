#include "validator.hpp"
bool Validator::isDecimalDigit(char character) {
        return (character >= '0' && character <= '9') || character == '.';
    }

   bool Validator::isHexadecimalDigit(char character) {
        return (character >= '0' && character <= '9') || (character >= 'a' && character <= 'f') || 
               (character >= 'A' && character <= 'F') || character == '.';
    }

    bool Validator::isDecimal(const char* str) {
        int i = 0;
        if (str[i] == '-' || str[i] == '+') i++;
        if (str[i] == '\0') return false;

        bool hasDecimalPoint = false;
        while (str[i] != '\0') {
            if (str[i] == '.') {
                if (hasDecimalPoint) return false; 
                hasDecimalPoint = true;
            }
            if (!Validator::isDecimalDigit(str[i])) return false;
            i++;
        }
        return true;
    }

    bool Validator::isHexadecimal(const char* str) {
        if (strlen(str) < 3 || str[0] != '0' || (str[1] != 'x' && str[1] != 'X')) return false;

        for (int i = 2; str[i] != '\0'; i++) {
            if (!isHexadecimalDigit(str[i])) return false;
        }
        return true;
    }

    bool Validator::isValidNumber(const char* str) {
        return Validator::isDecimal(str) || Validator::isHexadecimal(str);
    }