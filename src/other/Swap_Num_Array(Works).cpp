#include <iostream>
using namespace std;

int main(){
	int n,a[1000],sw1,sw2,i1,i2;
	cin>>n;
	for(int x = 0; x <n;x++){
		cin>>a[x];
	}
	cin>>sw1>>sw2;
	for(int x = 0;x < n;x++){
		if(a[x] == sw1){
			i1 = x;
		}
		if(a[x] == sw2){
			i2 = x;
		}
	}
	swap(a[i1],a[i2]);
	for(int x = 0;x < n;x++){
		cout<<a[x]<<" ";
	}
	return 0;
}
