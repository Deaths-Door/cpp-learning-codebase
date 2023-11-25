#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n - 1];
	for(int x = 0;x < n;x++){
		cin>>a[x];
	}
	//Sort
	int key,y;
	for(int x = 1;x < n;x++){
		key = a[x];
		y = x - 1;
		while(y >= 0 and a[y] > key){
			a[y + 1] = a[y];
			y = y - 1;
		}
		a[y + 1] = key;
	}
	//Print
	for(int x = 0;x < n;x++){
		cout<<a[x]<<" ";
	}
	return 0;
}
