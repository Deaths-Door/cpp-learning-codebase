#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ogn = n,digits = 0,num[1000];
    for(int x = 0;ogn > 0;x++){
        num[x] = ogn %10;
        ogn /= 10;
        digits++;
    }
    int sum = 0;
    for(int x = 0;x < digits;x++){
        sum = sum + pow(num[x],digits);
    }
    (sum == n) ? cout<<"true" : cout<<"false";
	return 0;
}
