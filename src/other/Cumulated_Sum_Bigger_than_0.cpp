#include <iostream>
using namespace std;

int main(){
	int sum = 0,n;
	do{
		cin>>n;
		sum += n;
		if(sum >= 0){
           cout<<n;
		}
	}while(sum >= 0);
	return 0;
}
