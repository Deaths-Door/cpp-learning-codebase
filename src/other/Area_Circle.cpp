#include <iostream>
#include <cmath>

double diameterToArea(double d){
    return std::pow((d/2),2) * M_PI;
}

int main(){
    double d;
    std::cout << "Enter Diameter: ";
    std::cin >> d;

    std::cout << "Area: " << diameterToArea(d);    
    return 0;
}