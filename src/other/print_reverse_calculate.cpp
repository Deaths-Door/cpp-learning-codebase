#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num;
    while(n > 0){
        num = n %10;
        n /= 10;
        cout<<num;
    }
	return 0;
}

