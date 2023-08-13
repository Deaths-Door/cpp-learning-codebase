#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int x = 1;x <= n;x++){
        for(int spc = 1;spc <= n - x;spc++){
            cout<<" ";
        }
        int pn = x;
        for(int y = 1;y <= x;y++){
            cout<<pn;
            pn++;
        }
        pn -= 2;
        for(int y = 1;y <= x - 1;y++){
            cout<<pn;
            pn--;
        }
        cout<<endl;
    }
    return 0;
}
