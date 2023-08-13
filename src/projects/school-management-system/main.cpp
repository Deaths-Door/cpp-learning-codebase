#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "StudentData.hpp"
/*
    subject - %
*/

const std::string FILE_NAME = "data.csv";

int main(){
    int studentID;
    std::cout << "Enter Student ID : ";
    std::cin >> studentID;

    std::ifstream file(FILE_NAME);
    std::string content = "";

    while(std::getline(file,content)){
        deathsdoor::StudentData sd(content);
        if(sd.id != studentID) continue;

        std::cout << "sd.id = " << sd.id << std::endl;
        std::cout << "sd.name = " << sd.name << std::endl;
        std::cout << "sd.geburtsdatum = " << sd.geburtsdatum << std::endl;
    }
    return 0;
}