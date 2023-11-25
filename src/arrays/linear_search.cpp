#include<iostream>
using namespace std;

int linear_search(int a[],int n,int target){
	for(int x = 0;x < n;x++){
		if(a[x] == target){
			return x;
		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	int a[n - 1];
	for(int x = 0;x < n;x++){
		cin>>a[x];
	}
	int target;
	cin>>target;

	cout<<linear_search(a,n,target);
	return 0;
}
