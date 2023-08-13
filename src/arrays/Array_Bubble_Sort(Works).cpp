#include<iostream>
using namespace std;

int main(){
	//Input
	int n;
	cin>>n;
	int a[n - 1];
	for(int x = 0;x < n;x++){
		cin>>a[x];
	}
	for(int x = 0;x < n - 1;x++){
		for(int y = 0;y < n - x - 1;y++){
			if(a[y] > a[y + 1]){
				swap(a[y],a[y + 1]);
			}
		}
	}
	for(int x = 0;x < n;x++){
		cout<<a[x]<<endl;
	}
	return 0;
}
