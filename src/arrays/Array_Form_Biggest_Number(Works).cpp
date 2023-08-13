#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int compare(string a,string b){
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0 ? 1 : 0;
}

int main(){
    int t;
    cin>>t;
    while(t > 0){
        int n;
        cin>>n;
        string a[n];
        for(int x = 0;x < n;x++){
            cin>>a[x];
        }
        sort(a,a + n,compare);
        for(int x = 0;x < n;x++){
            cout<<a[x];
        }
        cout<<endl;
        t--;
    }
	return 0;
}
