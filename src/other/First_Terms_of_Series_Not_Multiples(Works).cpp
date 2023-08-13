#include<iostream>
using namespace std;

int main(){
    int n1,n2,y = 1;
    cin>>n1>>n2;
    for(int x = 1;x <= n1;x++){
        int ans = (3 * y) + 2;
        if(ans %n2 == 0){
            x -= 1;
        }
        else{
            cout<<ans<<endl;
        }
        y++;
    }
	return 0;
}
