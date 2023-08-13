#pragma once
#ifndef VARIABLES_HPP
#define VARIABLES_HPP

#include <string>
#include <map>
#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\NodeType.hpp"
#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.hpp"

namespace deathsdoor::math {
    class Variables : public deathsdoor::nodes::TreeNode<deathsdoor::math::NodeType>{
        public: using mapType =  std::map<char,int>;
        private : mapType _variables;
        Variables(const mapType& variables) noexcept : TreeNode(NodeType::Variable),_variables(variables){}
  /*      Variables(const std::string& string) : TreeNode(NodeType::Variable){
            if(string.empty()) return;
            for(std::string::const_iterator it = string.begin(); it != string.end(); ++it){
                if(!std::isalpha(*it)) throw std::invalid_argument("This isnt a valid variable expression :" + string + " but its mainly the part :" +  string.substr(std::distance(string.begin(),it)));

                //if no power stated 
                if(std::isalpha(*(it + 1))){
                    this->_variables[*it] = this->contains(*it) ? 1 : this->_variables[*it] + 1;
                    continue;
                }

                if(*(it + 1) != '^') throw std::invalid_argument("This isnt a valid variable expression :" + string + " but hauptsachlichteil :" +  string.substr(std::distance(string.begin(),it)) + "as it doesn't contain a ^ in it");


                if(*(it + 2) == '0'){
                    this->_variables[*it] = this->contains(*it) ? 0 : this->_variables[*it] + 1;
                    continue;
                }
                if(*(it + 2) == '1' &&  !isdigit(*(it + 2))){
                    this->_variables[*it] = this->contains(*it) ? 1 :  this->_variables[*it] + 1;
                    continue;
                }

                if(*(it + 2) != '('){
                    std::string::const_iterator newIterator = it + 2;
                    while(isdigit(*newIterator)){
                        newIterator++;
                    }
                    this->_variables[*it] = this->contains(*it) ? 1 :  this->_variables[*it] + std::stoi(string.substr(std::distance(string.begin(), it) + 2, newIterator - (it + 2)));
                    it = newIterator - 1;
                    continue;
                }
            
                size_t endPos = string.find(')', std::distance(string.begin(),it + 2) + 1);
                if (endPos == std::string::npos) throw std::invalid_argument("This isn't a valid variable expression: " + string);
                this->_variables[*it] = this->contains(*it) ? 1 :  this->_variables[*it] + 1;
                it = string.begin() + endPos;
            }
        }
*/
        
        mapType getAll() const noexcept{
            return this->_variables;
        }

        std::string asString() const noexcept{
            std::string s = "";
            for(const math::Variables::mapType::const_iterator::value_type& pair : this->_variables){
                s += pair.first;
                if(pair.second > 1.0) s += "^" + std::to_string(pair.second);               
            }
            return s;
        }

        bool containsVariables() const noexcept{
            return !this->_variables.empty();
        }

        bool contains(const char ch) const noexcept{
            return this->_variables.find(ch) != this->_variables.end();
        }

        friend std::ostream& operator<<(std::ostream& os, const Variables& variable){
            os << variable.asString();
            return os;
        }
        bool operator==(const Variables& other) const noexcept{
            return this->_variables == other._variables;
        }
        bool operator!=(const Variables& other) const noexcept{
            return !(*this == other);
        }
    };
}
#endif //VARIABLES_HPP