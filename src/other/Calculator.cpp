#include <iostream>

double add(double x,double y){
    return x + y;
}

double minus(double x,double y){
    return x - y;
}

double multiply(double x,double y){
    return x * y;
}

double divide(double x,double y){
    return x / y;
}

int main(){
    while (true){
        std::cout << "Please enter one of the following \n + for addition \n - for substraction \n * for multiplication \n / for division \n e fpr escape" << std::endl;

        double x,y;
        char op;

        std::cout << "Enter Operator : ";
        std::cin >> op;

        if(op == 'e') break;

        std::cout <<"Enter number : ";
        std::cin >> x;

        std::cout << "Enter number : ";
        std::cin >> y;


        double z;
        switch (op){
            case '+': z = add(x,y); break;
            case '-': z = minus(x,y); break;
            case '*': z = multiply(x,y); break;
            case '/': z = divide(x,y); break;
            default: throw std::invalid_argument("Invalid Operator"); break;
        }
        std::cout << "Answer : " << z << std::endl;    
    }
    
    return 0;
}