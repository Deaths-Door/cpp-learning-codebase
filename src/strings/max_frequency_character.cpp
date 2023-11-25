#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s1;
    getline(cin,s1);
    char chmax;
    int max = 1;
    for(int x = 0;x < s1.length();x++){
        int times = 1;
        for(int y = 0;y < s1.length();y++){
            if(s1[x] == s1[y]){
                times++;
            }
            if(times >= max){
                chmax = s1[x];
                max = times;
            }
        }
    }
    cout<<chmax;
    return 0;
}

