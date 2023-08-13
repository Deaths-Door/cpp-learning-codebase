#include <iostream>

int generateRandomNum(int minValue,int maxValue){
    srand(time(0));
    return rand() % (maxValue - minValue + 1);
}

int main(){
    std::cout << generateRandomNum(1,6);
    return 0;
}