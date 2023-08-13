#include <iostream>
#include <stack>
using namespace std;

string toBinary(int input){
    stack<int> stack;
    int n = input;
    
    while(n > 0){
        stack.push(n%2);
        n /=2;
    }

    string ans = "";
    while(!stack.empty()){
        ans += to_string(stack.top());
        stack.pop();
    }

    return ans;
}

int main(){
    int input;
    cin>>input;

    cout << toBinary(input);

    return 0;
}