#include <iostream>

#include "math/calculator.h"

int main() {
    math::Calculator calc;

    std::cout << "C++ CI/CD Learning Project\n";
    std::cout << "==========================\n";
    std::cout << "3 + 4 = " << calc.add(3, 4) << "\n";
    std::cout << "10 - 3 = " << calc.subtract(10, 3) << "\n";
    std::cout << "6 * 7 = " << calc.multiply(6, 7) << "\n";
    std::cout << "22 / 7 = " << calc.divide(22, 7) << "\n";

    return 0;
}
