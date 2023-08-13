#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main(){
    char s1[1000];
    cin.getline(s1,1000);
    string
     res1= "",res2 = "";
     for(int x = 0;x < strlen(s1);x++){
        char ch = s1[x];
        if(ch != 'x'){
            res1 += ch;
        }
        else{
            res2 += ch;
        }
    }
    cout<<res1 + res2;
    return 0;
}
