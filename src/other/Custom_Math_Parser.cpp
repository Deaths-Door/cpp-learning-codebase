#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

string concatenate(const std::vector<std::string>& strings){
    return accumulate(strings.begin(), strings.end(), std::string{},[](const std::string& a, const std::string& b) { return a + b; });
}

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}

bool hasNestedBrackets(string s){
    stack<char> brackets;

    for(auto& it:s){
        if(it == '(') brackets.push(it);
        if(it == ')') {
            //empty == no open brackets == no nested brackets
            if(brackets.empty()) return true;
            brackets.pop();
        }
    }
    return !brackets.empty();
}

bool balanced(string input){
    stack<char> stack;
    for(auto& it : input){
        if(it == '(') stack.push(it);
        else if(it == ')') stack.pop();
    }
    return stack.empty();
}

double calc(char ch,double n1,double n2){
    if(ch == '+') return n1 + n2;
    else if(ch == '-') return n1 - n2;
    else if(ch == '*') return n1 * n2;
    else if(ch == '/') return n1 / n2;
    else if(ch == '^') return pow(n1,n2);

    return -1;
}

vector<string> tokenize(string s){
    istringstream iss(s);
    vector<string> tokens;
    
    //Open Close brackets
    stack<char> brackets;
    string token;

    //Tokenize it 
    while(iss >> token){
        //Open Bracket ?
        if(token == "("){
            brackets.push('(');
            tokens.push_back(token);
        }

        //Close bracket?
        if(token == ")"){
            brackets.pop();
            tokens.push_back(token);
        }

        //Not in brackets
        if(brackets.empty()) tokens.push_back(token);
        else tokens.back() += token;
    }

    return tokens;
}

string infixProfixConvertor(string input){
    stack<char> stack;
    string posfix ="";

    for(auto& it:input){
        if(it == '+' || it  == '-' || it == '*' || it == '/'){
            while(stack.empty() == false && precedence(stack.top() >= precedence(it)) ){
                posfix += stack.top();
                stack.pop();
            }
            stack.push(it);
        }
        else if(it == '(') stack.push(it);
        else if(it == ')') {
            while(stack.top() != '('){
                posfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else posfix += it;
    }
    while(!stack.empty()){ 
        posfix += stack.top(); 
        stack.pop();
    }

    return posfix;
}

string evaluate(string profix){
    stack<double> stack;

    for(auto& it:profix){
        if(it == '+' || it  == '-' || it == '*' || it == '/') {
            double n1 = stack.top();
            stack.pop();

            double n2 = stack.top();
            stack.pop();

            stack.push(calc(it,n1,n2));
        }
        else stack.push(it - '0');
    }
    return to_string(stack.top());
}

string calculate(string input){s
    vector<string> tokens = tokenize(input);

    //Handle nested brackets
    for(auto& it : tokens){
        if(hasNestedBrackets(it)) it = calculate(it);

        string smth = concatenate(tokens);
        string profix = infixProfixConvertor(smth);
        it = evaluate(profix);
    }
    return tokens[0];
}

int main(){
    string equation = "2 + 3";

    //If brackets are unbalanced throw error
    if(!balanced(equation)) throw runtime_error("Error: Unbalanced brackets in equation.");

    cout<<calculate(equation);

    return 0;
}