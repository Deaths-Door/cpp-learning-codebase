#include<iostream>
using namespace std;

int nth(int n){
    if(n <= 1){
        return n;
    }
    return nth(n - 1) + nth(n - 2);
}

int main (){
	int n;
	cin>>n;
	cout<<nth(n);
	return 0;
}

