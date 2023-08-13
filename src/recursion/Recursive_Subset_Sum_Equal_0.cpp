#include <iostream>
using namespace std;

bool subset(int a,int n,int vidx,int sum){
    if(vidx == n){
        return 0;
    }
    subset(a,n,vidx + 1,sum + a[vidx]);
    if(sum == 0){
        return 1;
    }
}

int main(){
    int n;
    cin>>n;
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    cout<<subset(a,n - 1,0,0);
    return 0;
}


