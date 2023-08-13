#include <iostream>
#include <cmath>
using namespace std;
int main() {
    //Testcases
    int t;
    cin>>t;
    while(t--){
        //No. of Soldiers
        int n;
        cin>>n;
        //Cordinates
        int cords[n - 1];
        for(int x = 0;x < n;x++){
            cin>>cords[x];
        }
        //Bombs
        int bombs[n - 1];
        for(int x = 0;x < n;x++){
            cin>>bombs[x];
        }
        //Calculate
        int cost = 0;
        for(int x = 0;x < n;x++){
            for(int y = x + 1;y < n;y++){
                cost += abs(cords[x] - cords[y]) * bombs[y];
            //    cout<<cords[x]<<" - "<<cords[y]<<" * "<<bombs[y]<<endl;
            //    cout<<cost<<endl;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
