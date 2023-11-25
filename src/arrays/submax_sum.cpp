#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t > 0){
        int n;
        cin>>n;
        int a[n];
        int cs = 0;
        int ms = 0;
        for(int x = 0;x < n;x++){
            cin>>a[x];
        }
        for(int x = 0;x < n;x++){
            cs = cs + a[x];
            if(cs < 0){
                cs = 0;
            }
            ms = max(cs,ms);
        }
        cout<<ms<<endl;
        t--;
    }
    return 0;
}
