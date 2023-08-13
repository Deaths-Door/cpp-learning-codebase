#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    int ans = 0;
    for(int D = 5;n/D >= 1;D = D * 5){
        ans += n/D;
    }
    cout<<ans;
	return 0;
}
