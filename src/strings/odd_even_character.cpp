#include <iostream>
#include <string>
using namespace std;

/*
Take as input S, a string.
Write a function that replaces
every even character with the
character having just higher
ASCII code and every odd character
with the character having just
lower ASCII code. Print the value returned.
*/

int main() {
    string s1;
    getline(cin,s1);
    for(int x = 0;x < s1.length();x++){
        char ch = s1[x];
        if(x %2 == 0){
            ch += 1;
        }
        else{
            ch -= 1;
        }
        cout<<ch;
    }
    return 0;
}
