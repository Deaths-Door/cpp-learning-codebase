#include <iostream>
#include <string>
using namespace std;

int main(){
    //Grosser String
    string s1;
    getline(cin,s1);
    //Kleiner String
    string s2;
    getline(cin,s2);
    cout<<s1<<endl<<s2;
    //Finding
    for(int x = 0;x < s1.length();x++){
        for(int len = 1;len <= s1.length() - x;len++){
            string subs1 = s1.substr(x,len);

        }
    }
    return 0;
}
