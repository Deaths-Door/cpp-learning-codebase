#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int spc = ((4 * 2) - 1) - 2;
    for(int x = 1;x <= n;x++){
        for(int y = 1;y <= x;y++){
            if(y == n and x == n){
                break;
            }
            cout<<y<<" ";
        }
        for(int y = 1;y <= spc;y++){
            cout<<"  ";
        }
        for(int y = x;y >= 1;y--){
            cout<<y<<" ";
        }
        spc -= 2;
        cout<<endl;
    }
    return 0;
}
