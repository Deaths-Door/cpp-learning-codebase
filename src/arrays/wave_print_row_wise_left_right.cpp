#include <iostream>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int col = 0;col < m;col++){
        for(int rw = 0;rw < n;rw++){
            cin>>a[rw][col];
        }
    }
    for(int col = 0;col < m;col++){
        if(col %2 == 0){
            for(int rw = 0;rw < n;rw++){
                cout<<a[rw][col]<<" ";
            }
        }
        else{
            for(int rw = m - 1;rw >= 0;rw--){
                cout<<a[rw][col]<<" ";
            }
        }
    }
    return 0;
}
