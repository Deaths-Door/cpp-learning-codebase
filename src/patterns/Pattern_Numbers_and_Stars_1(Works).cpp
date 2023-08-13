#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int x = 0;x < n;x++){
        int pn = 1;
        for(int y = n;y >= 1;y--){
            if(x < y){
                cout<<pn++<<" ";
            }
        }
        for(int y = 1;y <= (2 * x  -1);y++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
