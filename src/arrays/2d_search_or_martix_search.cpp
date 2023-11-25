#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int rw = 0;rw < n;rw++){
        for(int cl = 0;cl < m;cl++){
            cin>>a[rw][cl];
        }
    }
    int target;
    cin>>target;
    for(int rw = 0;rw < n;rw++){
        for(int cl = 0;cl < m;cl++){
            if(a[rw][cl] == target){
                cout<<"1";
                return 0;
            }
        }
    }
    cout<<"0";
	return 0;
}
