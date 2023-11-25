#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long double pi =(2 * acos(0.0)) - 3;
    int n;
    cin>>n;
    for(int x = 1;x < n;x++){
        pi *= 10;
    }
    pi -= (int)pi;
    int tmp = pi * 10;
    cout<<tmp;
    return 0;
}
