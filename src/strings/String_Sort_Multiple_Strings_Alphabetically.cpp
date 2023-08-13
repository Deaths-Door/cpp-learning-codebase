#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string s1[1000];
    cin>>n;
    cin.ignore();
    for(int x = 0;x < n;x++){
        getline(cin,s1[x]);
    }
    sort(s1,s1 + n);
    for(int x = 0;x < n;x++){
        cout<<s1[x]<<endl;
    }
	return 0;
}
