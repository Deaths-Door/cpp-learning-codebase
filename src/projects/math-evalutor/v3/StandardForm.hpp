#pragma once
#ifndef STANDARDFORM_HPP
#define STANDARDFORM_HPP

#include <string>
#include <cmath>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\NodeType.hpp>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.hpp>
/*
To Create .O file run this command :
    cd "C:\MinGW\bin"
    g++ -c "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.cpp" -o "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.o"

To Link with its test file :
    g++ "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\headertest\standardfromtest.cpp" "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.o" -o standardfromtest
*/
namespace deathsdoor::math {
    constexpr const double tolerance = 1e-6;
    //TODO put everything in hpp file
    class StandardForm : public deathsdoor::nodes::TreeNode<deathsdoor::math::NodeType> {
        private:
            double num = 1;
            int power = 1;
            bool isInValidRange() const noexcept{
                return (num >= 1 && num <= 10) || (num >= -10 && num <= -1);
            }
        public :
            StandardForm(const double& n) noexcept : TreeNode(NodeType::StandardFormNumber){
                this->setNum(n);
            }
            StandardForm(const double& n,const int& pow) noexcept: TreeNode(NodeType::StandardFormNumber){
                if(isInValidRange()){
                    setPower(pow);
                    setNum(n);
                }
                else{
                    setNum(n);
                    setPower(pow);
                }
            }
            StandardForm(const std::string& s): TreeNode(NodeType::StandardFormNumber){
                try {
                    //valid number so no string manipulation
                    setNum(std::stod(s));
                }
                catch(const std::out_of_range& exception){
                    size_t pos = s.find('e');
                    //String is doesnt contain an e in it so eg : 2*10^3 or some invalid number
                    if(pos == std::string::npos){
                        pos = s.find('^');
                        if(pos == std::string::npos) throw std::invalid_argument("Invalid Number given :" + s);
                        num = stod(s.substr(0,pos - 2));
                        power = stoi(s.substr(pos +1,s.length() - 1));
                    }
                    //string contains an e in it so eg : its 2e10
                    else{
                        num = stod(s.substr(0, pos));
                        power = stoi(s.substr(pos + 1));
                    }
                }
            }

            void setNum(const double& num) noexcept{
                this->num = num;

                if (isInValidRange()) return;

                double absNumber = std::abs(num);
                int logZehn = std::ceil(std::log10(absNumber));
                this->num /= std::pow(10, logZehn);
                this->power = logZehn;

                if (this->num < 0) this->num = -this->num;

                if(this->num > 0 && this->num < 1) {
                    this->num *= 10;
                    this->power -= 1;
                }
            }
            double getNum() const noexcept{
                return this->num;
            }

            void setPower(const int& power) noexcept{
                this->power = power;
            }
            int getPower() const noexcept{
                return this->power;
            }

            std::string toScientificNotation() const noexcept{
                return std::to_string(num) + "e" + std::to_string(power);
            }
            std::string toEngineeringNotation() const noexcept{
                return std::to_string(num) + "*10^" + std::to_string(power);
            }
            std::string toAppropriateFormat() const noexcept {
                return this->toScientificNotation();
              //  return this->power > 4 ? this->toScientificNotation() : std::to_string(this->toDouble());
            }
            double toDouble() const {
                return std::stod(this->toScientificNotation());
            }

            friend std::ostream& operator<<(std::ostream& os, const StandardForm& sf) noexcept{
                os << sf.toAppropriateFormat();
                return os;
            }

            StandardForm operator+(const StandardForm& other) const noexcept{
                int max_power = std::max(power, other.power);
                return StandardForm(num * std::pow(10, power - max_power) + other.num * std::pow(10, other.power - max_power), max_power);
            }
            StandardForm operator+(const double& other) const noexcept{
                return (*this +  StandardForm(other));
            }
            void operator+=(const StandardForm& other) noexcept{
                *this = *this + other;
            }
            void operator+=(const double& other) noexcept{
                *this = *this + other;
            }

            StandardForm operator-(const StandardForm& other) const noexcept{
                int min = std::min(power,other.power);
                return  StandardForm(num * std::pow(10,power - min) - other.num * std::pow(10,other.power - min),min);
            }
            StandardForm operator-(const double& other) const noexcept{
                return (*this -  StandardForm(other));
            }
            StandardForm operator-() const noexcept{
                return StandardForm(-this->num,this->power);
            }
            void operator-=(const StandardForm& other) noexcept{
                *this = *this - other;
            }
            void operator-=(const double& other) noexcept{
                *this = *this - other;
            }

            StandardForm operator*(const StandardForm& other) const noexcept{
                return  StandardForm(num * other.num,power + other.power);
            }
            StandardForm operator*(const double& other) const noexcept{
                return *this *  StandardForm(other);
            }
            void operator*=(const StandardForm& other) noexcept{
                *this = *this * other;
            }
            void operator*=(const double& other) noexcept{
                *this = *this * other;
            }

            StandardForm operator/(const StandardForm& other) const noexcept{
                return  StandardForm(num / other.num,power - other.power);
            }
            StandardForm operator/(const double& other) const noexcept{
                return *this / StandardForm(other);
            }
            void operator/=(const StandardForm& other) noexcept{
                *this = *this / other;
            }
            void operator/=(const double& other) noexcept{
                *this = *this / other;
            }

            StandardForm operator^(const StandardForm& other) const noexcept{
                return StandardForm(std::pow(num, other.num), power * other.power);
            }
            StandardForm operator^(const double& other) const noexcept{
                return *this ^  StandardForm(other);
            }
            void operator^=(const StandardForm& other) noexcept{
                *this = *this ^ other;
            }
            void operator^=(const double& other) noexcept{
                *this = *this ^ StandardForm(other);
            }
            
            bool operator==(const StandardForm& other) const noexcept{
                return (num == other.num) && (power == other.power);
            }
            bool operator==(const double& other) const noexcept{
                return *this ==  StandardForm(other);
            }

            bool operator!=(const StandardForm& other) const noexcept{
                return !(*this == other);
            }
            bool operator!=(const double& other) const noexcept{
                return *this != StandardForm(other);
            }

            bool operator>(const StandardForm& other) const noexcept{
                return (power != other.power) ? power > other.power : num > other.num;
            }
            bool operator>(const double& other) const noexcept{
                return *this > StandardForm(other);
            }

            bool operator<(const StandardForm& other) const noexcept{
                return (power != other.power) ? power < other.power : num < other.num;
            }
            bool operator<(const double& other) const noexcept{
                return *this < StandardForm(other);
            }

            bool operator<=(const StandardForm& other) const noexcept{
                return (power != other.power) ? num <= other.num : power <= other.power;
            }
            bool operator<=(const double& other) const noexcept{
                return *this <= StandardForm(other);
            }

            bool operator>=(const StandardForm& other) const noexcept{
                return (power != other.power) ? num >= other.num : power >= other.power;
            }
            bool operator>=(const double& other) const noexcept{
                return *this >= StandardForm(other);
            }

            //TODO remove error : returning reference to temporary [-Wreturn-local-addr]
            const StandardForm& min(const StandardForm& other) const noexcept;
            const StandardForm& min(const double& other) const noexcept;
            //TODO remove error : returning reference to temporary [-Wreturn-local-addr]
            const StandardForm& max(const StandardForm& other) const noexcept;
            const StandardForm& max(const double& other) const noexcept;

            StandardForm abs() const noexcept;

            StandardForm sqrt() const noexcept;
            StandardForm cbrt() const noexcept;
            StandardForm root(const double& root) const noexcept;

            StandardForm log(const StandardForm& other) const noexcept;
            StandardForm log(const double& other) const noexcept;
            StandardForm log10() const noexcept;

            StandardForm sin() const noexcept;
            StandardForm cos() const noexcept;
            StandardForm tan() const noexcept;

            double asin() const;
            double acos() const;
            double atan() const;
    };
 //   #include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.cpp>
}
#endif //STANDARDFORM_HPP
