#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sn;
    int ans = 0;
    for(int x = 0;x < n;x++){
        cin>>sn;
        ans = ans ^ sn;
    }
    cout<<ans;
    return 0;
}
