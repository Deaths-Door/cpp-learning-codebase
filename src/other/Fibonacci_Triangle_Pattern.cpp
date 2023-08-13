#include <iostream>
using namespace std;

int main(){
    //Rows
    int n;
    cin>>n;
    //n(n + 1)/2;
    int total = (n * n + n) /2;

    int a = 0,b = 1,c;
    cout<<a<<endl<<b<<endl;
    for(int x = 1;x < total - 1;x++){
        c = a + b;
        cout<<c<<endl;
        a = b;
        b = c;
    }

}
