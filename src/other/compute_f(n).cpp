#include<iostream>
using namespace std;

int main(){
	//Testcase
    long long int t;
    cin>>t;
    while(t--){
		//Input
		long long int n;
        cin>>n;
		//Solve
		long long int temp;
		if(n %2 == 0){
			temp = n/2;
			cout<<temp<<endl;
		}
		else{
			temp = -((n + 1)/2);
			cout<<temp<<endl;
		}

    }
	return 0;
}
