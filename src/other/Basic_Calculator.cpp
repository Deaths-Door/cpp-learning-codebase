#include <iostream>
using namespace std;

int main(){
    char ch = ' ';
    while(true){
        int n1,n2;
        cin>>ch>>n1>>n2;
        switch(ch){
            case '+' :
                cout<<n1 + n2<<endl;
                break;
            case '-' :
                cout<<n1 - n2<<endl;
                break;
            case '*' :
                cout<<n1 * n2<<endl;
                break;
            case '/' :
                cout<<n1 /n2<<endl;
                break;
            case '%' :
                cout<<n1 %n2<<endl;
                break;
            default :
                cout<<"Invalid operation. Try again."<<endl;
                break;
        }
    }
    return 0;
}

