#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    int l = s1.length();
    for(int x = 0;x < l;x++){
        int y;
        int times = 1;
        char ch = s1[x];
        cout<<s1[x];
        while(s1[x + 1] == ch){
            times++;
            x++;
        }
        cout<<times;
    }
    return 0;
}


