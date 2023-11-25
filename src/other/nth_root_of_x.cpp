#include<iostream>
#include <cmath>
using namespace std;

int main(){
    //Input
	double n,k;
	cin>>n>>k;
    double y = 1.0 / k;
    double ans = pow(n,y);
    cout<<ans<<endl;
	return 0;
}
