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
    sort(a,a + n);
    int l = 0;
    int h = n - 1;
    while(l < h){
        if(a[l] + a[h] == target){
            cout<<a[l]<<" and "<<a[h]<<endl;
        }
        if(a[l] + a[h] > target){
            h--;
        }
        else{
            l++;
        }
    }
    return 0;

}


