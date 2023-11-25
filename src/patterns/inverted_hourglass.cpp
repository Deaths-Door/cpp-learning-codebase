#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //Top
    for(int x = 1;x <= n;x++){
        int y,k = 0;
        for(y = n;y >= n - x + 1;y--){
            cout<<y<<" ";
        }
        for(int z = 0;z <= (n - x) * 2;z++){
            cout<<"  ";
        }
        y += 1;
        while(y <= n){
            cout<<y++<<" ";
        }
        cout<<endl;
    }
    //Mid
    for(int x = n;x >= 0;x--){
        cout<<x<<" ";
    }
    for(int x = 1;x <= n;x++){
        cout<<x<<" ";
    }
    cout<<endl;
    //Bottom
    int spc = 1;
    for(int x = n;x >= 1;x--){
        int y = n;
        for(int z = 1;z <= x;z++){
            cout<<y--<<" ";
        }
        for(int z = 1;z <= spc;z++){
            cout<<"  ";
        }
        y++;
        for(int z = 1;z <= x;z++){
            cout<<y++<<" ";
        }
        spc += 2;
        cout<<endl;
    }
    return 0;
}
