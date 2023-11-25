#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin>>n;
    int dn = 0,i = 0,r;
    while(n != 0){
        r = n %10;
        n /= 10;
        dn += r * pow(2,i);
        i++;
    }
    cout<<dn;
}
