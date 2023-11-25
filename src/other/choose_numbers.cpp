#include <iostream>
using namespace std;

int main(){
	int n,a[1000];
	cin>>n;
	for(int x = 0;x < n;x++){
		cin>>a[x];
	}

	for(int x = 0;x < n;x++){
		for(int y = 0;y < n;y++){
			for(int z = 0;z < n;z++){
				if(a[y] + a[z] >= a[x]){
					cout<<"YES";
					return 0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
}

