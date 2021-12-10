#include <iostream>
#include <fstream>
#include "StackCalc.h"


int main(int argc, char** argv) {
    std::ifstream input;
    SC::StackCalc calc;
    try {
        if (argc > 1) {
            input.open(argv[1]);
            calc.execute(input);
        } else {
            calc.execute(std::cin);
        }
    }
    catch (std::invalid_argument &err) {
        std::cerr << err.what();
        return 1;
    }
    return 0;
}
