#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b,c,d,x1,x2;
    cin>>a>>b>>c;

    d =(b*b-4*a*c);
    x1 = (-b+sqrt(d))/(2*a);
    x2 = (-b-sqrt(d))/(2*a);

    if(d > 0){
        cout<<"Real and Distinct"<<endl;
        (x1 < x2) ? cout<<x1<<" "<<x2 :
                    cout<<x2<<" "<<x1;
    }
    else if(d==0){
        cout<<"Real and Equal"<<endl;
		cout<<x1<<" "<<x2;
    }
    else{
        cout<<"Imaginary"<<endl;
    }
	return 0;
}
