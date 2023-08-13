#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

    int n1 = n %2 == 0 ? n - 1 : n;
	while(n1 > 1){
		cout<<n1<<endl;
		n1 = n1 - 2;
	}
	cout<<"1"<<endl;
	for(int x = 2;x <= n;){
		cout<<x<<endl;
		x = x + 2;
	}
	return 0;
}
