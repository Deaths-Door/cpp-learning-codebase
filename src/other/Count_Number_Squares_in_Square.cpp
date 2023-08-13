#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t,n;
    cin>>n;
    while(t--){
        int sq = 0;
        cin>>n;
        while(n > 0){
            sq += pow(n,2);
            n--;
        }
        cout<<sq<<endl;
    }
    return 0;
}
