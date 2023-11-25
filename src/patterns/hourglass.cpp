#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //Up
    int z1 = n,y;
    for(int x = 1;x <= n;x++){
        for(y = 1;y <= n;y++){
            if(x >= y + 1){
                cout<<"  ";
            }
            else{
               cout<<z1<<" ";
               z1--;
            }
        }
        int z2 = 0;
        for(int y = n;y >= 0;y--){
            if(x <= y + 1){
                cout<<z2<<" ";
                z2++;
            }
        }
        z1 = n - x;
        cout<<endl;
    }
    //Mid
    for(int x = 1;x <= n;x++){
        cout<<"  ";
    }
    cout<<"0"<<endl;
    //Down
    for(int x = 1;x <= n;x++){
        int z3 = n - (n - x);
        for(int y = n;y >= 0;y--){
            if(x <= y - 1){
                cout<<"  ";
            }
            else{
                cout<<z3<<" ";
                z3--;
            }
        }
        for(int y = 1;y <= x;y++){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
