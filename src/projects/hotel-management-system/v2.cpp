#include <iostream>
#include <string>
#include <fstream>

/*
    1 - mangage room 
    2 - check in
    5 - invoice
*/

const std::string DataFile = "data.csv";
const int RoomLimit = 100;
const std::string types[4] = { "Name","Gender","Check In Data","Check Out Data"};

int main(){ 
    std::cout << "1 : Check In\n2 : Avaible Rooms\n3 : Customer Search\n4 : Invoice\n5 : Exit\n";
    int input;
    std::cin >> input;

    std::ifstream file(DataFile);
    std::ofstream writeToFile;
    std::string line = "";

    int roomNumber;
    bool isAvalible = true;

    switch(input){
        case 1 : 
            std::cout << "Enter room number : ";
            std::cin>>roomNumber;
            if(roomNumber > RoomLimit){ 
                std::cout << "Sorry we only have 100 rooms\n";
                break;
            }
            for(int x = 0; std::getline(file,line); x++){
                if(roomNumber != x) continue;
                isAvalible = false;
                break;
            }
            writeToFile.open(DataFile,std::ios::app);
            writeToFile << roomNumber << ",";
            for(int x = 0;x < 4;x++){
                std::cout << types[x] << ": ";
                std::string input;
                std::cin >> input;
                writeToFile << input << ",";
            }
            writeToFile << std::endl;
            writeToFile.close();
            break;
        case 2 : 
            std::cout << "Avaliable Rooms :\n"; 
            while(std::getline(file,line)) std::cout << line.substr(0,line.find(',')) << std::endl;
            break;
        case 3 : 
            std::cout << "Enter room number : ";
            std::cin>>roomNumber;
            if(roomNumber > RoomLimit){ 
                std::cout << "Sorry we only have 100 rooms\n";
                break; 
            }
            for(int x = 0; std::getline(file,line); x++){
                if(x != roomNumber) continue;
                int position = 0;
                for(int y = 0;(position == line.find(',')) != std::string::npos;y++) {
                    std::cout << types[y] << line.substr(0,position) << std::endl;
                    line.erase(0,position + 1);
                }
            }
            break;
        case 4 : break;
        case 5 : 
            std::cout << "Tschüss";
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
    file.close();
    return 0;
}