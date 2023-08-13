#include <limits>

//TODO include this in the evalutor program for solve maths and in convertors with Standard Form
bool isOutOfRangeForDouble(double n){
    return n < std::numeric_limits<double>::min() || n > std::numeric_limits<double>::max();
}