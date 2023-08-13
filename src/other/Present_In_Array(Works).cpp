#include <iostream>
using namespace std;

int main(){
	int n,a[1000],key;
	cin>>n;
	for(int x = 0;x < n;x++){
		cin>>a[x];
	}
	cin>>key;
	for(int x = 0;x < n;x++){
		if(a[x] == key){
			cout<<"true";
			return 0;
		}
	}
	cout<<"false";
	return 0;
}
