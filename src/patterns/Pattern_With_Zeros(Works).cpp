#include <iostream>
using namespace std;

int main(){
    int n,z = 1;
    cin>>n;
    for(int x = 1;x <= n;x++){
        for(int y = 1;y <= x;y++){
            if(y == 1 or y == x){
                cout<<z<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
        z++;
    }
    return 0;
}
