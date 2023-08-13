#pragma once
#ifndef UNITS_CONVERTOR_HPP
#define UNITS_CONVERTOR_HPP

#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\StandardForm.hpp"

namespace deathsdoor::math {
    enum Measurements{
        LENGTH,
        TIME,
        MASS,
        AREA,
        Volume,
    };
    
    template<typename T,enable_if_t = Measurements>
    class UnitConvertor{

    };
}

#endif //UNITS_CONVERTOR_HPP

int main(){
    deathsdoor::math::UnitConvertor<int>()
}