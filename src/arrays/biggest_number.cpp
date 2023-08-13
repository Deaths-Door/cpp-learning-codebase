#include <iostream>
#include <algorithm>

int main(){
    int size;

    std::cout << "Input array size : ";
    std::cin >> size;
    std::cout << std::endl;

    std::cout << "Input Elements ..." << std::endl;
    
    int biggest = 0;
    int input;

    for(int x = 0;x < size;x++){
        std::cin >> input;
        if (input < biggest) continue;
        biggest = input;
    }

    std::cout <<  "Biggest Number : " << biggest << std::endl;

    return 0;
}