#include <iostream>
using namespace std;

int main() {
    int s,e,steps;
    cin>>s>>e>>steps;
    int paddf = s;
    while(paddf <= e){
        int ans = (5 * (paddf - 32))/9;
        cout<<paddf<<" "<<(int)ans<<endl;
        paddf += steps;
    }
    return 0;
}
