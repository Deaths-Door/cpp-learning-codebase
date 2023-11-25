#include <iostream>
#include <string>
using namespace std;

void star(string s1,int x,int l){
    if(x == l){
        return;
    }
    cout<<s1[x];
    if(s1[x] == s1[x + 1]){
        cout<<"*";
    }
    star(s1,x + 1,l);
}

int main(){
    string s1;
    getline(cin,s1);
    star(s1,0,s1.length());
    return 0;
}
