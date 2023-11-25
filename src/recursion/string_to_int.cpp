#include <iostream>
#include <cmath>
using namespace std;

int stringToInt(string s1){
    if (s1.length() == 1)
        return (s1[0] - '0');
    double y = stringToInt(s1.substr(1));
    double x = s1[0] - '0';
    x = x * pow(10, s1.length() - 1) + y;
    return int(x);
}

int main(){
    string s1;
    getline(cin,s1);
    cout<<stringToInt(s1);
}
