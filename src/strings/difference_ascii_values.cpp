#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    cout<<s1[0];
    for(int x = 1;x < s1.length();x++){
        cout<<(int)s1[x] - (int)s1[x - 1];
        cout<<s1[x];
    }
    return 0;
}

