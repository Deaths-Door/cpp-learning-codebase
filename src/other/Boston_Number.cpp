#include <iostream>
using namespace std;

int main(){
    //Input
    int n;
    cin>>n;
	//Sum of Digits
	int n1 = n;
	int sum = 0;
	while(n1 > 0){
	    sum += n1 %10;
	    n1 = n1 /10;
	}
	//Prime Factors
    int c = 2;
    int psum = 0;
	while(n > 1){
		if(n%c==0){
		    psum = psum + c;
	    	n = n /c;
		}
		else{
		    c++;
		}
	}
	//Boston Number
	(psum == sum) ? cout<<true :
	                cout<<false;
    return 0;

}
