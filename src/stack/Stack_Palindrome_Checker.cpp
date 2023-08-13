#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string input){
    stack<char> stack;
    for(auto& it:input){
        stack.push(it)
    }
    for(auto& it:input){
        if(it != stack.pop()) return false
    }
    return true;
}

int main(){

    //Input
    string input;
    getline(cin,input);
    
    //Check
    check(input) ? cout<<"True" : cout<<"False";
    return 0;
}