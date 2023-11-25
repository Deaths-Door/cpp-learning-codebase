#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/*
        a

        (31)8 = (3 × 8^1) + (1 × 8^0) = (25)10
        (314)8 = (3 × 8^2) + (1 × 8^1) + (4 × 8^0) = (204)10

        https://www.rapidtables.com/convert/number/base-converter.html

*/

int main(){
    //Input
    //Source Base,Destintation Base,Number
    int sb,db,n;
    cin>>sb>>db>>n;

    //(a)
    int d = 0;
    for(int x = 0;n > 0;x++){
        d += (n %10) * pow(sb,x);
        n = n/10;
    }
    //To Base
    int q,r;
    q =  d/db;
    r = d %db;
    int binary = r;
    while(q > 0){
        r = q %db;
        q = q /db;
        binary = binary * 10 + r;
    }
    //Reverse number
    string s1 = to_string(binary);
    reverse(s1.begin(),s1.end());
    binary = stoi(s1);
    cout<<binary;
    return 0;
}
