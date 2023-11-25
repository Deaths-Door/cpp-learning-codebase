#include <iostream>
using namespace std;

int main(){
    int dn,r,i = 1,ocn = 0;
    cin>>dn;
    while(dn != 0){
        r = dn %8;
        dn /= 8;
        ocn += r * i;
        i *= 10;
    }
    cout<<ocn;
    return 0;
}
