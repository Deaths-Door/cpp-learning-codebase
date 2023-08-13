#pragma once
#ifndef NODETYPE_HPP
#define NODETYPE_HPP

namespace deathsdoor::math{
    enum class NodeType{
        Operator,
        Constant,
        StandardFormNumber,
        Fraction,
        Variable,
        AlegbaricTerm,
        AlegbaricExpression,
    };
    inline std::ostream& operator<<(std::ostream& os, const NodeType& node) noexcept{
        switch(node){
            case NodeType::Operator : os << "Operator"; break;
            case NodeType::Constant : os << "Constant"; break; 
            case NodeType::StandardFormNumber : os << "StandardFormNumber"; break; 
            case NodeType::Fraction : os << "Fraction"; break; 
            case NodeType::Variable : os << "Variable"; break; 
            case NodeType::AlegbaricTerm : os << "AlegbaricTerm"; break; 
            case NodeType::AlegbaricExpression : os << "AlegbaricExpression"; break; 
        }
        return os;
    }
}
#endif //NODETYPE_HPP