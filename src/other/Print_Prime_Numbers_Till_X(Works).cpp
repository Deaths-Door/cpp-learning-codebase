#include <iostream>
using namespace std;

int main (){
    int n;
    cin>>n;
    cout<<"2";
    for(int x = 3;x <= n;x++){
        int p = 0;
        for(int y = 2;y < x;y++){
            if(x %y == 0){
                p = 1;
            }
        }
        if(p == 0){
            cout<<", "<<x;
        }
    }
    return 0;
}
