#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    int target;
    cin>>target;
    int s,e;
    sort(a,a + n);
    for(int x = 0;x < n - 2;x++){
        s = x + 1;
        e = n - 1;
        while(s < e){
            if(a[x] + a[s] + a[e] == target){
                cout<<a[x]<<", "<<a[s]<<" and "<<a[e]<<endl;
                s++;
            }
            else if(a[x] + a[s] + a[e] < target){
                s++;
            }
            else{
                e--;
            }
        }
    }
    return 0;
}
