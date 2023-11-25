#include <iostream>
using namespace std;

int count(int n){
	// base case
	if (n == 0)
		return 0;
	else
		// if last bit set add 1 else add 0
		return (n & 1) + count(n >> 1);
}

int main(){
	//Testcases
	int t;
	cin>>t;
	while(t--){
		//Input
		int n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
