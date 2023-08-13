#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int x = 0;x < n;x++){
        for(int y = 0;y < n;y++){
            cin>>a[x][y];
        }
    }
    for(int x = 0;x < n/2;x++){
        for(int y = 0;y < n - x - 1;y++){
            int tmp = a[x][y];
            a[x][y] = a[y][n - x - 1];
            a[y][n - x - 1] = a[n - x - 1][n - y - 1];
            a[n - x - 1][n - y - 1] = a[n - y - 1][x];
            a[n - y - 1][x] = tmp;
        }
    }
    for(int x = 0;x < n;x++){
        for(int y = 0;y < n;y++){
            cout<<a[x][y]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
