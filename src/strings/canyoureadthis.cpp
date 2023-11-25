#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    for(int x = 0;x < s1.length();x++){
        cout<<s1[x];
        if(isupper(s1[x + 1])){
            cout<<endl;
        }
    }
    return 0;
}
