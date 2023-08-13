#pragma once
#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\MathParser\v4\NodeType.hpp>
#include "C:\Users\Aarav Aditya Shah\Documents\GitHub\All-My-Code\C++\Node\headerfiles\TreeNode.hpp"

//TODO add function to perfrmo operation between terms
namespace deathsdoor::math {
    class Operator : public deathsdoor::nodes::TreeNode<deathsdoor::math::NodeType> {
        public:
            //TODO maybe add sqrt opeartion to enum
            enum class Operation {
                ADD,
                SUBTRACT,
                MULTIPLY,
                DIVIDE,
                POWER
            };
        private: 
            Operation _operation;
            static Operation asOperationFromChar(const char ch) {
                switch(ch){
                    case '+' : return Operation::ADD;
                    case '-' : return Operation::SUBTRACT;
                    case '*' : return Operation::MULTIPLY;
                    case '/' : return Operation::DIVIDE;
                    case '^' : return Operation::POWER;
                }
                throw std::invalid_argument("Invalid Operation given " + ch);
            }
        public:
            Operator(const Operation& operation) noexcept: TreeNode(NodeType::Operator),_operation(operation) {}
            Operator(const char ch) : TreeNode(NodeType::Operator) {
                this->_operation = asOperationFromChar(ch);
            }

            Operation getOperation() const noexcept{
                return this->_operation;
            }

            friend std::ostream& operator<<(std::ostream& os, const Operator::Operation& operation) noexcept{
                switch(operation){
                    case Operator::Operation::ADD: os << "+"; break;
                    case Operator::Operation::SUBTRACT: os << "-"; break;
                    case Operator::Operation::MULTIPLY: os << "*"; break;
                    case Operator::Operation::DIVIDE: os << "/"; break;
                    case Operator::Operation::POWER: os << "^"; break;
                }
                return os;
            }
            
            friend std::ostream& operator<<(std::ostream& os, const Operator& operation) noexcept{
                os << operation._operation;
                return os;
            }
    };
}
#endif //OPERATOR_HPP