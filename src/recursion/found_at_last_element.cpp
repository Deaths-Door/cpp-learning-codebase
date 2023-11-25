#include <iostream>
using namespace std;

void find(int a[],int n,int target){
    if(n == 0){
        return;
    }
    if(a[n] == target){
        cout<<n;
        return;
    }
    return find(a,n - 1,target);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    int target;
    cin>>target;
    find(a,n - 1,target);
    return 0;
}
