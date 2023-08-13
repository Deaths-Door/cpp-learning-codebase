#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const std::string types[4] = { "Name","Gender","Check In Data","Check Out Data"};
const std::string DataFile = "data.csv";

int main(){
    int roomNumber;
    std::cout << "Enter Room Number : ";
    std::cin >> roomNumber;

    std::ifstream file(DataFile);
    std::string fileData= "";
    while(std::getline(file,fileData)){
        int index = fileData.find(',');
        if(std::stoi(fileData.substr(0,index)) != roomNumber) continue;
        std::stringstream ss(fileData.substr(index + 1,fileData.length() - 1));
        std::string word;
        index = 0;
        while(!ss.eof()){
            std::getline(ss,word,',');
            std::cout<<types[index]<<": "<<word<<std::endl;
            index++;
        }
        return 0;
    }
    file.close();

    std::ofstream writeToFile;
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
    return 0;
}