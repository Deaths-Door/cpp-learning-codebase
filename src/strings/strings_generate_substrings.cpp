#include <iostream>
#include <string>
using namespace std;

int main() {
    //Input
    int l;
    cin>>l;
    cin.ignore();
    string s1;
    getline(cin,s1);
    for(int x = 1;x <= l;x++){
        for(int len = 0;len <= l - x;len++){
            int e = x + len;
            string subs1 = s1.substr(len,e - len);
            cout<<subs1<<endl;
        }
    }
    return 0;
}
