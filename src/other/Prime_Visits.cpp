#include <iostream>
using namespace std;

int prime(int primes[],int max_num,int z){
    bool num;
    for(int x = 0 ;x < max_num;x++){
        if(x == 1 or x == 0){
            continue;
        }
        num = true;
        for(int y = 2;y < x;x++){
            if(x %y  == 0){
                num = false;
            }
        }
        if(num == true){
            primes[z] = x;
        }
    }
    for(int x = 0;x < 100;x++){
        cout<<primes[x]<<endl;
    }
    return primes,max_num;
}

int main (){
    int primes[1000000];
    int max_num = 100;
    prime(primes,max_num,0);

    /*int t;
    cin>>t;
    while(t > 0){
        int n;
        cin>>n;

        t--;
    }*/
    return 0;
}

