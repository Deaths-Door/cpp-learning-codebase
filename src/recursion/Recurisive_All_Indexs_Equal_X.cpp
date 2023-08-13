#include <iostream>
using namespace std;

void find(int a[],int n,int target,int x){
    if(x == n){
        return;
    }
    if(a[x] == target){
        cout<<x<<" ";
    }
    return find(a,n,target,x + 1);
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
    find(a,n - 1,target,0);
    return 0;
}
