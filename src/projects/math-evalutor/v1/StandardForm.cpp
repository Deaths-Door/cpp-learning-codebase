#include <string>
#include <cmath>
#include <sstream>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\Math-Parser\.vscode\headerFiles\StandardForm.h>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\Math-Parser\v1\Extensions.cpp>


class StandardForm{
    private: 
        inline std::string toString() const {  return std::to_string(num) + "e" + std::to_string(power);}
        friend std::ostream& operator<<(std::ostream& os, const StandardForm& sf) {
            os << sf.toString();
            return os;
        }
    
    public: double num = 1; int power = 1;
    StandardForm(){}
    StandardForm(double n, int pow){ num = n;  power = pow; }
    StandardForm(const std::string s){
        auto pos = s.find('e');
        if(pos == std::string::npos) toStandardForm(s);
        else{
            num =  stod(s.substr(0,pos)) ;
            power = stoi(s.substr(pos + 1));
        } 
    }
    
    StandardForm operator+ (const StandardForm& other){
        StandardForm ans = StandardForm();
        int min = std::min(power,other.power);
        ans.num = num * std::pow(10,power - min) +other.num * std::pow(10,other.power - min);
        ans.power = min;
        return ans;
    }
    StandardForm operator+ (const double& other){
        StandardForm ans = StandardForm();
        auto t = toStandardForm(std::to_string(other));
        int min = std::min(power,t.power);
        ans.num = num * std::pow(10,power - min) + t.num * std::pow(10,t.power - min);
        ans.power = min;
        return ans;
    }
    StandardForm operator- (const StandardForm& other){
        StandardForm ans = StandardForm();
        int min = std::min(power,other.power);
        ans.num = num * std::pow(10,power - min) - other.num * std::pow(10,other.power - min);
        ans.power = min;
        return ans;
    }
    StandardForm operator- (const double& other){
        StandardForm ans = StandardForm();
        auto t = toStandardForm(std::to_string(other));
        int min = std::min(power,t.power);
        ans.num = num * std::pow(10,power - min) - t.num * std::pow(10,t.power - min);
        ans.power = min;
        return ans;
    }
    StandardForm operator* (const StandardForm& other){
        return StandardForm(num * other.num,power + other.power).toString();
    }
    StandardForm operator* (const double& other){
        return StandardForm(num * other,power + log10(other));
    }
    StandardForm operator/ (const StandardForm& other){
        return StandardForm(num / other.num,power - other.power).toString();
    }
    StandardForm operator/ (const double& other){
        return StandardForm(num / other,power - log10(other));
    }

    StandardForm toStandardForm(const std::string& s) {
        std::stringstream stream;
        stream << std::scientific << std::stold(s);
        std::string s1;
        stream >> s1;
        return StandardForm(s1);
    }
};