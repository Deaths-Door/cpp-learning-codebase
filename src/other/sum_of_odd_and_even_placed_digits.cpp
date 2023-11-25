#include <iostream>
using namespace std;

int main(){
    //Input
    int n;
    cin>>n;
    //Count Digits
    int ogn = n;
    int digits = 0;
    while(ogn != 0){
        digits++;
        ogn /= 10;
    }
    //Number in Array
    int a[digits];
    for(int x = digits - 1;x >= 0;x--){
        int r = n %10;
        a[x] = r;
        n /= 10;
    }
    //Odd and Even Sum
    int esum = 0,osum = 0;
    for(int x = 0;x < digits;x++){
        if(a[x] %2 == 0){
            esum += a[x];
        }
        else{
            osum += a[x];
        }
    }
    //Print
    cout<<"Odd Sum -- "<<osum<<endl;
    cout<<"Even Sum -- "<<esum<<endl;
    return 0;
}
