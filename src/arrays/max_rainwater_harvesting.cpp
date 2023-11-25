#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    int stored = 0;
    for(int x = 1;x < n - 1;x++){
        int l = a[x];
        for(int y = 0;y < x;y++){
            l =  max(l,a[y]);
        }
        int r = a[x];
        for(int y = x + 1;y < n;y++){
            r = max(r,a[y]);
        }
        stored = stored + (min(l,r) - a[x]);
    }
    cout<<stored;
    return 0;
}
