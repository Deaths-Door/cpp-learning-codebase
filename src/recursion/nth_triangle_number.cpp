#include <iostream>
using namespace std;

int triangle(int n,int sum){
    if(n == 1){
        return sum;
    }
    triangle(n - 1,sum + n);
}

int main(){
    int n;
    cin>>n;
    cout<<triangle(n,1);
    return 0;
}
