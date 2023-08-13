#pragma once
#ifndef STUDENT_DATA_HPP
#define STUDENT_DATA_HPP

#include <string>
#include <map>

namespace deathsdoor {
    class StudentData {
        public:
            int id;
            std::string name;
            std::string geburtsdatum;
            std::map<std::string,std::string> subjectsWithPercents;

            StudentData(std::string string) noexcept {
                int index = string.find(',');

                this->id = std::stoi(string.substr(0,index));
                string.erase(0,index + 1);

                index = string.find(',');
                this->name = string.substr(0,index);
                string.erase(0,index + 1);

                index = string.find(',');
                this->geburtsdatum = string.substr(0,index);
                string.erase(0,index + 1);

                for(auto& it = string.begin() + 1;it != string.end() - 1;++it){
                    auto hyphen = std::find(it, string.end(), '-');
                    auto bracket = std::find(it, hyphen, '(');
                    std::string subject = string.substr(it, bracket - it - 1);
                    std::string percent = string.substr(bracket + 1, hyphen - bracket - 1);
                    this->subjectsWithPercents[subject] = percent;
                }
            }
    };

}

#endif //STUDENT_DATA_HPP