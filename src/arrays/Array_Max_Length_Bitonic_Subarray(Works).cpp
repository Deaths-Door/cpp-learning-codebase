#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t > 0){
        int n;
        cin>>n;
        int a[n];
        for(int x = 0;x < n;x++){
            cin>>a[x];
        }
        int add[n];
        add[0] = 1;
        int sub[n];
        sub[n - 1] = 1;
        for(int x = 1;x < n;x++){
            add[x] = (a[x] >= a[x - 1]) ?
                      add[x - 1] + 1 : 1;
        }
        for(int x = n - 2;x >= 0;x--){
            sub[x] = (a[x] >= a[x + 1]) ?
                      sub[x + 1] + 1 : 1;
        }
        int max = add[0] + sub[0] - 1;
        for(int x = 1;x < n;x++){
            if(add[x] + sub[x] - 1 > max){
                max = add[x] + sub[x] - 1;
            }
        }
        cout<<max<endl;
        t--;
    }
    return 0;
}
