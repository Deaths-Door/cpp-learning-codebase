#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.hpp"
using namespace deathsdoor::math;

const StandardForm& StandardForm::min(const StandardForm& other) const noexcept{
    return (*this < other) ? *this : other;
}
const StandardForm&StandardForm::min(const double& other) const noexcept{
    return this->min(StandardForm(other));
}

const StandardForm& StandardForm::max(const StandardForm& other) const noexcept{
    return (*this > other) ? *this : other;
}
const StandardForm& StandardForm::max(const double& other) const noexcept{
    return this->max(StandardForm(other));
}
StandardForm StandardForm::abs() const noexcept{
    return StandardForm(std::abs(this->num),this->power);
}

StandardForm StandardForm::sin() const noexcept{
    StandardForm result = StandardForm(this->num,this->power);
    StandardForm term = StandardForm(this->num,this->power);
    int n = 3;
    bool positive = false;
    while (term.abs() > tolerance) {
        result = result + term;
        positive = !positive;
        term = -term ^ 2 / (n * (n - 1));
        n += 2;
    }
    return result;
}
StandardForm StandardForm::cos() const noexcept{
    StandardForm sinSquared =  ((*this) / 2.0) ^ 2;
    return StandardForm(1.0 - 2.0 * sinSquared.num, sinSquared.power);
}
StandardForm StandardForm::tan() const noexcept{
    return this->sin() / this->cos();
}

double StandardForm::asin() const {
    return std::asin(this->toDouble());
}
double StandardForm::acos() const {
    return std::acos(this->toDouble());
}
double StandardForm::atan() const {
    return std::atan(this->toDouble());
}