#include<iostream>
using namespace std;

int main(){
	int a,b,sum = 0;
	cin>>a>>b;
	sum = a;
	while(b != 1){
		sum = sum * a;
		b--;
	}
	cout<<sum;
	return 0;
}
