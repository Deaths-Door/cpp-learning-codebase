#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s1;
        getline(cin,s1);
        for(int x = 0;x < s1.length();x++){
            if(s1[x] == 'p' and s1[x + 1] == 'i'){
                cout<<"3.14";
                x++;
                continue;
            }
            cout<<s1[x];
        }
    }
	return 0;
}
