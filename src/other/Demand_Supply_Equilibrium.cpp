#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //Testcase
    int t;
    cin>>t;
    while(t--){
        //Input Line 1 and 2
        int m1,c1,m2,c2;
        cin>>m1>>c1>>m2>>c2;

        //Calculate
        int y = (c1 - (m1 / m2) * c2) / (1 - m1 / m2);
        int x = (c1 - c2) / (m2 - m1);

        //Possible
        if( x >= 0 and y >= 0 and m1 != m2){
            int ans = floor(y + 0.5);
            cout<<ans<<endl;
        }
        else{
            cout<<"-1";
        }

    }
    return 0;
}
