#include <iostream>
#include <string>
using namespace std;

string lsort(string s1,int l,int x){
    if(x == l){
        return s1;
    }
    if(s1[x] < s1[x + 1]){

        swap(s1[x],s1[x + 1]);
    }
    return lsort(s1,l,x + 1);
}

int main(){
    string s1;
    getline(cin,s1);
    cout<<lsort(s1,s1.length(),0);
    return 0;
}
