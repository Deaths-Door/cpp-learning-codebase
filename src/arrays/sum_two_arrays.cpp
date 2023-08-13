#include <iostream>

int input_sum_of_array(){
    int size;

    std::cout << "Input array size : ";
    std::cin >> size;
    std::cout << std::endl;

    std::cout << "Input Elements ..." << std::endl;

    int sum = 0;
    int input;

    for(int x = 0;x < size;x++){
        std::cin >> input;
        sum += input;
    }

    return sum;
}

int main(){
    int size_1 = input_sum_of_array();
    int size_2 = input_sum_of_array();

    std::cout << "Sum of array is : " << size_1 + size_2 << std::endl;

    return 0;
}
