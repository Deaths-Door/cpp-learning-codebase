#include <iostream>
#include <string>
#include <deque>

//TODO handle -+ | +- | -- correctly
//TODO when 2(3+4) make it 2 * (3 + 4)

std::string::iterator findCorrespondingBracket(std::string* s, std::string::iterator it) {
    int brackets = 1;
    for (it++; it != s->end(); ++it) {
        if (*it == '(') brackets++;
        else if (*it == ')') brackets--;
        if (brackets == 0) return it;
    }
}

std::deque<std::string> tokenize(std::string s){
    std::deque<std::string> tokens;
    std::string token = "";

    char prevOp = '\0';

    for(auto it = s.begin(); it != s.end();it++){
        // Ignore whitespace
        if (*it == ' ') continue;
        //only operators
        if(*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '^'){

            if(!token.empty()){
                tokens.push_back(token);
                token.clear();
            }

            //if +- or -+ equals -
            if((prevOp == '+' || prevOp == '-') && *it == '-') token += '-';
           else if(prevOp == '-' && *it == '-') token += '+';

            //it isnt + or -
            else token += *it;

            if(!token.empty()){
                tokens.push_back(token);
                token.clear();
            }
        }
        else if(*it == '(') {
            if(!token.empty()){
                tokens.push_back(token);
                token.clear();
            }

            std::string::iterator temp = findCorrespondingBracket(&s,it);
            int length = std::distance(it,temp) + 1;
            token = s.substr(std::distance(s.begin(),it),length);
            it = temp;

            tokens.push_back(token);
            token.clear();
        }
        //if substr from it to the funcname length is == func name

        //anything else (multi-digit nums)
        else token += *it;
        prevOp = *it;
    }

    if(!token.empty()) tokens.push_back(token);


    //For Testing
    std::cout << "Tokens : ";
    for(auto& it:tokens) std::cout<<it<<" : ";
    std::cout<<std::endl;

    return tokens;
}