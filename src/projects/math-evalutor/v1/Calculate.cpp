#include <string>
#include <deque>
#include <numeric>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\Math-Parser\v1\Tokenize.cpp>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\Math-Parser\v1\InfixToProfixConvertor.cpp>
#include <C:\Users\Aarav Aditya Shah\Documents\GitHub\Math-Parser\v1\Evalute.cpp>

//Maybe useless
bool hasNestedBrackets(const std::string s) {
    int brackets = 0;

    for (char c : s) {
        if (c == '(') brackets++;
        if (c == ')') {
            if (brackets == 0) return true;
            brackets--;
        }
    }
    return brackets != 0;
}

std::string concatenate(const std::deque<std::string>& data){
    return accumulate(data.begin(), data.end(), std::string{},[](const std::string& a, const std::string& b) { return a + b + " "; });
}

std::string calculate(const std::string equation){
    std::deque<std::string> tokens = tokenize(equation);

    for(auto& it : tokens){
        //No brackets
        if(it.find('(') == std::string::npos) return evalute(infixProfixConvertor(concatenate(tokens)));
         //it = evalute(infixProfixConvertor(concatenate(tokens)));
        else {
            if(hasNestedBrackets(it)) it = calculate(it);

            //give it expressions ohne brackets
            it = evalute(infixProfixConvertor(it.substr(1,it.size() - 2)));
        }

    }
    return tokens[0];
}