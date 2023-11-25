#include <iostream>
#include <cmath>
using namespace std;

int main(){
	//Log x with base n
	int x,n;
	cin>>x>>n;
	double ans =  log(x) / log(n);
	cout<<ans;
	return 0;
}
