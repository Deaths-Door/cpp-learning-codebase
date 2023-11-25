#include <iostream>
using namespace std;

bool prime(int x){
    static int i = 2;
    // corner cases
    if (x == 0 or x == 1) {
        return false;
    }

    // Checking Prime
    if (x == i)
        return true;

    // base cases
    if (x % i == 0) {
        return false;
    }
    i++;
    return prime(x);

}

int main(){
    //Testcase
    int t;
    cin>>t;
    while(t--){
        //Input
        int n;
        cin>>n;
        //Find the ans
        int times = 0;
        for(int x = 2;times != n;x++){
            if(prime(x) == true){
                times++;
            }
        }
        cout<<times;
    }
    return 0;
}
