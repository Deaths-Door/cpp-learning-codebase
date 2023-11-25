#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n){
	for(int x = 2;x <= sqrt(n);x++){
		if(n %x == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	prime(n) ? cout<<"Prime" :
		       cout<<"Not Prime";

	return 0;
}
