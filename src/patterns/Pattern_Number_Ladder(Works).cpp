#include<iostream>
using namespace std;

int main(){
	int n,z = 1;
	cin>>n;
	for(int x = 1;x <= n;x++){
        for(int y = 1;y <= x;y++){
            cout<<z<<" ";
            z++;
        }
        cout<<endl;
	}
	return 0;
}
