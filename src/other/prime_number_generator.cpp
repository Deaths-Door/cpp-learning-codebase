#include <iostream>
using namespace std;

int main(){
    int t,s,e,prime;
    cin>>t;
    while(t--){
        cin>>s>>e;
        for(int x = s;x <= e;x++){
            if(x == 1 or x == 0){
                continue;
            }
            prime = 1;
            for(int y = 2;y <= x /2;y++){
                if(x %y == 0){
                    prime = 0;
                    break;
                }
            }
            if(prime == 1){
                cout<<x<<", ";
            }
        }
    }
    return 0;
}
