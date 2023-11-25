#include <iostream>
#include <stack>
using namespace std;

bool check(string input){
    stack<char> stack;

    for(auto& it : input){
        if(it == '(') stack.push(it);
        else if(it == ')') stack.pop();
    }

    return stack.empty();
}

int main(){
    string input;
    getline(cin,input);
    cout << boolalpha << check(input);
    return 0;
}