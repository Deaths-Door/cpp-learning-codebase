#include <iostream>
using namespace std;

int main(){
    int n,sum = 1;
    cin>>n;
    for(int x = 0;x < n;x++){
        for(int spc = 1; spc <= n - x; spc++){
            cout <<"  ";
        }
        for(int y = 0;y <= x;y++){
            if (y == 0 or x == 0){
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
