#include <iostream>
using namespace std;

int main(){
    int n,sum = 1;
    cin>>n;
    for(int x = 0; x < n; x++){
        for(int y = 0; y <= x; y++){
            if (y == 0 || x == 0){
                sum = 1;
            }
            else{
                sum = sum * (x - y + 1) /y;
            }
            cout<<sum<<"   ";
        }
        cout<<endl;
    }

    return 0;
}
