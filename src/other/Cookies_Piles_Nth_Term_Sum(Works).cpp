#include <iostream>
using namespace std;

int main(){
    //Testcase
    int t;
    cin>>t;
    while(t--){
        int n,a,d;
        cin>>n>>a>>d;
        int sum = 0;
        //Nth term
        for(int x = 1;x <= n;x++){
            sum += (d * x) + (a - d);
        }
        cout<<sum<<endl;
    }
    return 0;
}
