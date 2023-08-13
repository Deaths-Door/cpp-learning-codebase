#include <iostream>
using namespace std;

int subarray(int a[],int s,int e,int n,int good){
    //Base Case
    if(e == n){
        return good;
    }
    //Set end point and start from 0
    else if(s > e){
        subarray(a,0,e + 1,n,good);
    }
    //See if good subarray
    else{
        int sum = 0;
        for(int x = s;x <= e;x++){
            sum += a[x];
        }
        if(sum %n == 0){
            subarray(a,s + 1,e,n,good + 1);
        }
        else{
            subarray(a,s + 1,e,n,good);
        }

    }
}

int main(){
    //Testcase;
    int t;
    cin>>t;

    while(t--){
        //Input
        int n;
        cin>>n;
        int a[n - 1];
        for(int x = 0;x < n;x++){
            cin>>a[x];
        }

        //Find out good subarray = sum of subarray %n == 0
        cout<<subarray(a,0,0,n,0)<<endl;
    }
    return 0;
}
