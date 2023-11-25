#include <iostream>
using namespace std;

int  main(){
    int n;
    int p;
    cin>>n>>p;
    float ans = 0;
    float dp = 1.0;
    for(int times = 0;times <= p;times++){
        while(ans * ans  <= n){
            ans = ans + dp;
        }
        ans = ans - dp;
        dp /= 10;
    }
    cout<<ans;
    return 0;
}
