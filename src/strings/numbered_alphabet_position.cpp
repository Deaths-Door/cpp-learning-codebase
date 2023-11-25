#include <iostream>
#include <string>
using namespace std;

int main(){
    //Input
    string s1;
    cin>>s1;
    //Position in alphabet
    //Ascii value - 64
    for(int x = 0;x < s1.length();x++){
        cout<<((int)s1[x] - 64) << " ";
    }
    return 0;
}
