#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}

string convert(string input){
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

int main(){
    string input;
    getline(cin,input);
    cout<<convert(input);
    return 0;
}