#include <iostream>
#include <stack>
#include <Stack_Infix_Postfix_Convertor.cpp>
using namespace std;

int calc(char ch,int n1,int n2){
    if(ch == '+') return n1 + n2;
    else if(ch == '-') return n1 - n2;
    else if(ch == '*') return n1 * n2;
    else if(ch == '/') return n1 / n2;
}

int evalute(string profix){
    stack<int> stack;
    for(auto& it:profix){
        if(it == '+' || it  == '-' || it == '*' || it == '/') {
            //get the 2 nums
            int n1 = stack.top();
            stack.pop()

            int n2 = stack.top();
            stack.pop()

            //do operation
            int ans = calc(it,n1,n2);
            stack.push(ans);
        }
        else stack.push(stoi(it));
    }
    return stack.top();
}

int main(){
    string input;
    getline(cin,input);
    string profix = convert(input);    
    cout<<evalute(profix);
    return 0;
}