#include <iostream>

double fahrToCelius(double n){
    return (5 * (n - 32)) / 9;
}

int main(){
    double n;
    std::cout << "Enter Fahrenheit: ";
    std::cin >> n;

    std::cout << "In Celius: " << fahrToCelius(n) << "°"<< std::endl;

    return 0;
}