#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int x = 1;x <= n;x++){
        int z = 1;
        for(int y = 1;y <= n;y++){
            if(x >= y){
                cout<<z;
                z++;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}
