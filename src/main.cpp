#include <iostream>
#include <vector>
#include <string>

#include "number_proccessor.hpp"


int main(int argc, char* argv[]) {
    if (argc !=3) {
        std::cerr << "Please provide two numbers as arguments." << std::endl;
        return 1;
    }

    NumberProcessor processor;
    
    try {
        for (int i = 1; i < argc; ++i) {
            processor.addNumber(argv[i]);
        }
        double sum = processor.getSum();
        char answer[32];
        Converter::doubleToCstring(sum,answer,2);
        std::cout << "Sum: " << answer  << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
