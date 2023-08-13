#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t > 0){
        int n;
        cin>>n;
        //Digits
        int e = 0;
        int o = 0;
        while(n != 0){
            int num = n %10;
            if(num %2 == 0){
                e += num;
            }
            else{
                o += num;
            }
            n /= 10;
        }
        if(e %4 == 0 or o %3 == 0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        t--;
    }
    return 0;
}
