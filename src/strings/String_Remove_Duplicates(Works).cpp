#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    string ans;
    for(int x = 0;x < s1.length();x++){
        if(s1[x] != s1[x +1]){
            ans += s1[x];
        }
    }
    cout<<ans;
    return 0;
}
\
