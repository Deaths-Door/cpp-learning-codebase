#include <iostream>
using namespace std;

bool palindrome(int a[],int s,int e){
    if(s == e){
        return true;
    }
    if(a[s] != a[e]){
        return false;
    }

    if(s < e + 1){
        return palindrome(a,s + 1,e - 1);
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    if(palindrome(a,0,n - 1)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}

