#include <iostream>
#include <deque>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <unordered_map>

//TODO add simiplfy algebra

bool isNum(const std::string& str) {
  std::string::const_iterator it = str.begin();
  while (it != str.end() && std::isdigit(*it)) ++it;
  if (it != str.end() && *it == '.') {
    ++it;
    while (it != str.end() && std::isdigit(*it)) ++it;
  }
  if (it != str.end() && (*it == 'e' || *it == 'E')) {
    ++it;
    if (it != str.end() && (*it == '+' || *it == '-')) ++it;
    while (it != str.end() && std::isdigit(*it)) ++it;
  }
  return !str.empty() && it == str.end();
}

bool isSingleTerm(const std::string& str) {
    bool hasNumber = false;
    bool hasVar = false;
    for (char c : str) {
        if (c >= '0' && c <= '9') hasNumber = true;
        else if (c == '.') { /*  do nothing */ }
        else if (c >= 'a' && c <= 'z') {
            if (hasVar) return false;
            hasVar = true;
        }
        else return false;
    }
    return hasNumber || hasVar;
}

inline std::string performOp(const std::string ch,
                             std::function<std::string()> add,
                             std::function<std::string()> minus,
                             std::function<std::string()> times,
                             std::function<std::string()> divide,
                             std::function<std::string()> pow){
    if(ch == "+") return add();
    else if(ch == "-") return minus();
    else if(ch == "*") return times();
    else if(ch == "/") return divide();
    else if(ch == "^") return pow();
    else throw std::invalid_argument("Invalid Input :" + ch);
}

std::pair<std::string, std::string> getNumAlgebraSubString(const std::string& s){
    auto it = std::find_if(s.begin(), s.end(), [](char ch){ return !std::isdigit(ch) && ch != '.';});
    return std::make_pair(s.substr(0, std::distance(s.begin(), it)), s.substr(std::distance(s.begin(), it)));
}

std::string combineVars(const std::string& var1, const std::string& var2){
    std::unordered_map<char,double> vars;

    for(const auto& it : var1) ++vars[it];
    for(const auto& it : var2) ++vars[it];

    std::string result = "";

    for(const auto& pair : vars){
        auto key = pair.first;
        auto value = pair.second;
        result += key;
        if(value > 1) result += "^" + std::to_string(value);
    }

    return result;
}
std::string algebraDivideVars(const std::string& var1, const std::string& var2){
    std::unordered_map<char,double> vars;

    for(auto it = var1.begin();it != var1.end();++it){
        char ch = *it;
        if(*it++ == '^'){
            std::string num = "";
            //while num
            while(isdigit(*++it) || *it == '.'){
                num += *it;
            }
            vars[ch] += stod(num);
        }
        else vars[ch]++;
    }

    for(auto it = var2.begin();it != var2.end();++it){
        char ch = *it;
        if(*++it == '^'){
            std::string num = "";
            //while num
            while(isdigit(*++it) || *it == '.'){
                num += *it;
            }
            vars[ch] -= stod(num);
        }
        else vars[ch]--;
    }

    //convert to string
    std::string result = "";

    for(auto& pair : vars){
        auto key = pair.first;
        auto value = pair.second;
        
        //cancelled out
        if(value == 0) continue;

        //default power
        if(value == 1) result += key;
        else result += key + "^" + std::to_string(value);
    }

    return result;
}

std::string calc(std::stack<std::string>* stack,std::string op){
    std::string term1 = stack->top();
    stack->pop();
    std::string term2 = stack->top();
    stack->pop();

    //Both are nums
    if(isNum(term1) && isNum(term2)){
        std::cout << "Both Nums : " << term1 << " : " << term2 << std::endl;

        return performOp(op,
                [&term1,&term2](){ return std::to_string(stod(term1) + stod(term2));},
                [&term1,&term2](){ return std::to_string(stod(term1) - stod(term2));},
                [&term1,&term2](){ return std::to_string(stod(term1) * stod(term2));},
                [&term1,&term2](){ return std::to_string(stod(term2) / stod(term1));},
                [&term1,&term2](){ return std::to_string(pow(stod(term1),stod(term2)));});
    }
    //Either are multi-term alegbra
    else  if(!isSingleTerm(term1) || !isSingleTerm(term2)) {
        throw std::invalid_argument("Invalid Input :" + term1 + " ..." + term2);

        auto s1 =  tokenize(term1);
    }

    //Both alebra singleTerm or either singleTerm + num
    else {
        //Swap so term1 == alebra and term2 == num
        if(isNum(term1)) std::swap(term1,term2);

        return performOp(op,
            // add
            [&term1,&term2](){
                std::pair<std::string,std::string> pair1 = getNumAlgebraSubString(term1);
                std::pair<std::string,std::string> pair2 = getNumAlgebraSubString(term2);

                //For Testing
                std::cout << "Algebra T1: " << pair1.first << " : " << pair1.second  << std::endl;
                std::cout << "Algebra T2: " << pair2.first << " : " << pair2.second  << std::endl;

                //have same vars
                if(pair1.second == pair2.second) return std::to_string(stod(pair1.first) + stod(pair2.first)) + pair1.second;
                else return term1 + "+" + term2;
            },
            // minus
            [&term1,&term2](){
                std::pair<std::string,std::string> pair1 = getNumAlgebraSubString(term1);
                std::pair<std::string,std::string> pair2 = getNumAlgebraSubString(term2);

                //For Testing
                std::cout << "Algebra T1: " << pair1.first << " : " << pair1.second  << std::endl;
                std::cout << "Algebra T2: " << pair2.first << " : " << pair2.second  << std::endl;

                //have same vars
                if(pair1.second == pair2.second) return std::to_string(stod(pair1.first) - stod(pair2.first)) + pair1.second;
                else return term1 + "-" + term2;
            },
            // times
            [&term1,&term2](){
                std::pair<std::string,std::string> pair1 = getNumAlgebraSubString(term1);
                std::pair<std::string,std::string> pair2 = getNumAlgebraSubString(term2);

                //For Testing
                std::cout << "Algebra T1: " << pair1.first << " : " << pair1.second  << std::endl;
                std::cout << "Algebra T2: " << pair2.first << " : " << pair2.second  << std::endl;

                return std::to_string(stod(pair1.first) * stod(pair2.first)) + combineVars(pair1.second,pair2.second);
            },
            //Divide
            [&term1,&term2](){
                std::pair<std::string,std::string> pair1 = getNumAlgebraSubString(term1);
                std::pair<std::string,std::string> pair2 = getNumAlgebraSubString(term2);

                return std::to_string(stod(pair2.first) / stod(pair1.first)) + algebraDivideVars(pair1.second,pair2.second);
            },
            //Power
            [&term1,&term2](){  return term1 + "^" + term2; }
        );
    }

    //No conditions are made so wrong input
    throw std::invalid_argument("Invalid Input :" + term1 + " ..." + term2);
}

//Input is already 'tokenized' and in prefix form
std::string evalute(const std::deque<std::string>& prefix){
    std::stack<std::string> stack;

    for(auto& it : prefix){
        if(it == "+" || it  == "-" || it == "*" || it == "/" || it == "^") stack.push(calc(&stack, it));
        else  stack.push(it);
        std::cout << "Stack Top : " << stack.top() << std::endl;
    }

    std::cout  << "Final Stack Top : " << stack.top() << std::endl << " ------------- " << std::endl;

    return stack.top();
}