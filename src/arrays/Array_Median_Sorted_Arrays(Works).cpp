#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n * 2];
    for(int x = 0;x < (n * 2);x++){
        cin>>a[x];
    }
    sort(a,a + (n * 2));
    cout<<a[n - 1];
	return 0;
}
