#include<iostream>
using namespace std;

int main(){
    int a[5];
    cin>>a[0];
    int ans = a[0];
    for(int x = 1;x < 5;x++){
        cin>>a[x];
        if(a[x] > ans){
            ans = a[x];
        }
    }
    cout<<ans;
	return 0;
}
