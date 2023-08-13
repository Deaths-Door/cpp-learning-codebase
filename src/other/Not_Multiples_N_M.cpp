#include <iostream>
using namespace std;

int main (){
    int t,n,m,z;
    cin>>t;
    while(t--){
        cin>>n>>m>>z;
        int nn = 0;
        for(int x = 1;x <= z;x++){
            if(x %m == 0 and x %n == 0){
                nn++;
             }
        }
        cout<<nn;
    }
    return 0;
}


