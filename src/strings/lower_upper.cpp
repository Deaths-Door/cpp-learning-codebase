#include <iostream>
#include <string>
using namespace std;

int main(){
    char ch;
    cin>>ch;
    if(ch >= 65 and ch <= 90){
        cout<<"UPPERCASE";
    }
    else if(ch >= 97 and ch <= 122){
        cout<<"lowercase";
    }
    else{
        cout<<"Invalid";
    }
    return 0;
}
