#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    for(int x = 0;x < s1.length();x++){
        if(x != s1.length() - 1){
            cout<<s1[x];
            int ans = (int)s1[x] - (int)s1[x + 1];
            cout<<ans;
        }
    }
    cout<<s1[s1.length()];
    return 0;
}

