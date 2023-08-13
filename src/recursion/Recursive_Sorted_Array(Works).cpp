#include <iostream>
using namespace std;

bool sorted(int a[],int n){
    if(n == 0 or n == 1){
        return true;
    }
    if(a[n] < a[n - 1]){
        return false;
    }
    return sorted(a,n - 1);
}

int main(){
    int n;
    cin>>n;
    int a[n - 1];
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    (sorted(a,n) == true) ? cout<<"true" :
                            cout<<"false";
	return 0;
}
