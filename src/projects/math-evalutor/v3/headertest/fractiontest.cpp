#include <iostream>
#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\Fraction.hpp"

int main(){
    using namespace deathsdoor::math;
    Fraction f1(3,4);
    Fraction f2(5,3);
    std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
    std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;
    std::cout << "f1 ^ f2 = " << (f1 ^ f2) << std::endl;
    return 0;
}
