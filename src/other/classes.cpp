#include <iostream>
#include <string>

class Car {
    private:
        std::string company;
        std::string model;
        std::string fuelType;
        double mileage;
        double price;
    public:
        Car(std::string company,std::string modal, std::string fuelType,double mileage,double price){

        }
        ~Car(){

        }
}; 

class Base{
    public:
        virtual void idk(){
            std::cout << "BASE FUN " << std::endl;
        }
        ~Base(){
            std::cout << "BASE DECONSTRUCTOR " << std::endl;
        }
};

class Dervied: Base{
    public:
        virtual void idk(){
            std::cout << "DERVIVED FUN " << std::endl;
        }
        ~Dervied(){
            std::cout << "BASE DECONSTRUCTOR " << std::endl;
        }
};

int main() {
    auto *b = new Base();
    auto *d = new Dervied();
    b->idk();
    d->idk();
    return 0;
}