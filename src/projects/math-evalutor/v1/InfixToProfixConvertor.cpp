#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

//TODO does work correctly i think

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    throw std::invalid_argument("Invalid Operator : " + ch);
}

//Maybe give it deque instead of converting to string
std::deque<std::string> infixProfixConvertor(const std::string input){
    std::stack<char> stack;
    std::deque<std::string> posfix;
    std::string token;

    for(auto& it:input){
        //ignore whitespace
        if(it == ' ') continue;

        if (it == '+' || it == '-' || it == '*' || it == '/' || it == '^') {
            if(!token.empty()){
                posfix.push_back(token);
                token.clear();
            }
            while (!stack.empty() && precedence(stack.top()) >= precedence(it)) {
                posfix.push_back(std::string(1, stack.top()));
                stack.pop();
            }
            stack.push(it);
        }
        else token += it;
    }

    if(!token.empty()){
        posfix.push_back(token);
        token.clear();
    }

    while (!stack.empty()) {
        posfix.push_back(std::string(1, stack.top()));
        stack.pop();
    }
    return posfix;
}