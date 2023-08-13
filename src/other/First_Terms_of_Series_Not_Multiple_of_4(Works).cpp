#include<iostream>
using namespace std;

int main(){
    int n1,y = 1,sum = 0;
    cin>>n1;
    for(int x = 1;x <= n1;x++){
        int ans = (3 * y) + 2;
        if(ans %4 == 0){
            x -= 1;
        }
        else{
            sum += ans;
            cout<<ans<<endl;
        }
        y++;
    }
    cout<<sum;
	return 0;
}

