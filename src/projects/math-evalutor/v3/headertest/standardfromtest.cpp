#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.hpp"
int main(){
    using namespace deathsdoor::math;
    StandardForm sf(12);
    std::cout << sf << std::endl;
    std::cout << "2e5 + 2e10 = "<< StandardForm(2,5) + StandardForm(2,10) << std::endl;
    std::cout << "2e10 - 2e5 = "<< StandardForm(2,10) - StandardForm(2,5) << std::endl;
    std::cout << "2e10 * 2e5 = "<< StandardForm(2,10) * StandardForm(2,5) << std::endl;
    std::cout << "2e10 / 2e5 = "<< StandardForm(2,10) / StandardForm(2,5) << std::endl;
    std::cout << "2e10 ^ 2e5 = "<< (StandardForm(2,10) ^ StandardForm(2,5)) << std::endl;
    std::cout << std::boolalpha << "2e10 == 2e5 = "<< (StandardForm(2,10) == StandardForm(2,5)) << std::endl;

    return 0;
}