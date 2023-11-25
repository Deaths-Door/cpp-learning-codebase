#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int rw = 0;rw < m;rw++){
        for(int cl = 0;cl < n;cl++){
            cin>>a[rw][cl];
        }
    }
    int srw = 1;
    int scl = 0;
    int erw = m - 1;
    int ecl = n - 1;
    cout<<a[srw - 1][0]<<", ";
    while(srw < m and scl < n){
        for(int x = srw;x < m;x++){
            cout<<a[x][scl]<<", ";
        }
        scl++;
        for(int x = scl;x < n;x++){
            cout<<a[m - 1][x]<<", ";
        }
        m--;
        if(srw < m){
            for(int x = m - 1;x >= srw;x--){
                cout<<a[scl][x]<<", ";
            }
            scl++;
        }
    }
    cout<<"END";
	return 0;
}

