#include <string>
#include <cmath>

//Quadratic formula
class Quadractic{
    public:
        double root1;
        double root2;
        std::string type;
        Quadractic(const std::string s,const double r1 = 2,const double r2 = NULL){
            root1 = r1;
            root2 = r2;
            type = s;
        }
};

Quadractic solveQuadractic(double a,double b,double c){
    double squared_numbers = (b * b - (4 * a * c));
    double positive = (-b + sqrt(squared_numbers)) / (2 * a);
    double negative = (-b - sqrt(squared_numbers)) / (2 * a);
    if(squared_numbers == 0) return Quadractic("Real and Distinct",positive,negative);
    else if(squared_numbers > 0)
        return (positive < negative) ?
            Quadractic("Real and Equal",positive,negative) :
            Quadractic("Real and Equal",negative,positive);
    else Quadractic("Imaginary");
}
