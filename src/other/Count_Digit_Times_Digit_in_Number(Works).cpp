#include<iostream>
using namespace std;

int main(){
    long int n,fn,tf = 0;
    cin>>n>>fn;
    while(n > 0){
        int r = n %10;
        if(r == fn){
            tf++;
        }
        n /= 10;
    }
    cout<<tf;
	return 0;
}
