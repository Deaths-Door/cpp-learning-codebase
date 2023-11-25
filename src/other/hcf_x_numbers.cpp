#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    int hcf = a[0],x = 1;
    while(x < n){
        if(a[x] %hcf== 0){
            x++;
        }
        else{
            hcf = a[x] %hcf;
        }
    }
    cout<<hcf;
	return 0;
}
