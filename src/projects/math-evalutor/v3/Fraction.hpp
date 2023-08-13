#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <cmath>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\NodeType.hpp>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.hpp>

namespace deathsdoor::math{
    class Fraction : public deathsdoor::nodes::TreeNode<deathsdoor::math::NodeType> {
        private :
            int _numerator;
            int _denominator = 1;
        public:
            Fraction(const int numerator) noexcept : TreeNode(NodeType::Fraction), _numerator(numerator) {}
            Fraction(const int numerator,const int denominator) noexcept : TreeNode(NodeType::Fraction), _numerator(numerator), _denominator(denominator){}

            void setNumerator(const int nominator) noexcept{
                this->_numerator = nominator;
            }
            int getNumerator() const noexcept{
                return this->_numerator;
            }

            void setDenominator(const int denominator) noexcept{
                this->_denominator = denominator;
            }
            int getDenominator() const noexcept{
                return this->_denominator;
            }

            void asInverse() noexcept{
                std::swap(_numerator, _denominator);
            }
            double asDouble() noexcept{
                return this->_numerator / this->_denominator;
            }

            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) noexcept {
                os << fraction.getNumerator() << "/" << fraction.getDenominator();
                return os;
            }

            Fraction operator+(const Fraction& other) const noexcept{
                return this->_denominator == other._denominator ? 
                    Fraction(this->_numerator + other._numerator,this->_denominator) : 
                    Fraction(this->_numerator * other._denominator + other._numerator * this->_denominator,this->_denominator * other._denominator);
            }
            Fraction operator-(const Fraction& other) const noexcept{
                return this->_denominator == other._denominator ? 
                    Fraction(this->_numerator + other._numerator,this->_denominator) : 
                    Fraction(this->_numerator * other._denominator - other._numerator * this->_denominator,this->_denominator * other._denominator);
            }
            Fraction operator*(const Fraction& other) const noexcept{
                return Fraction(this->_numerator * other._numerator,this->_denominator * other._denominator);
            }
            Fraction operator/(const Fraction& other) const noexcept{
                Fraction fr(other._numerator,other._denominator);
                fr.asInverse();
                return *this * fr;
            }
            Fraction operator^(const Fraction& other) const noexcept{
                return Fraction( std::pow(this->_numerator, other._numerator),std::pow(this->_denominator, other._numerator));
            }
    
    };
}
#endif //FRACTION_HPP