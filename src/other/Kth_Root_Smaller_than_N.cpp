#include<iostream>
using namespace std;

int main(){
    long long int t,n,k;
    while(t--){
        cin>>n>>k;
        int ans = 0;
        for(int x = 1;ans <= n;x++){
            int tmp_ans = (x ^ k);
            if(tmp_ans > ans and tmp_ans <= n){
                ans = tmp_ans;
            }
            if(tmp_ans > n){
                break;
            }
        }
        cout<<ans;
    }
	return 0;
}
