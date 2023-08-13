/*
Sale Tax = $95000
State Tax = 4%
Kanton Tax = 2%
*/
#include <iostream>

double STATE_TAX = 0.04;
double KANTON_TAX = 0.02;

int main(){
    double n;
    std::cin >> n;    

    double st = n * STATE_TAX;
    double kt = n * KANTON_TAX;

    std::cout << "Total Tax: " << n - kt - st<< std::endl;
    std::cout << "Tax: " << kt << std::endl;

    return 0;
}