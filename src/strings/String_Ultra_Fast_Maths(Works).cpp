#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        //Input
        string is1;
        getline(cin,is1);
        int pos = is1.find(" ");
        string s1;
        s1.append(is1,pos + 1);
        is1.erase(pos + 1);
        string s2 = is1;
        //Solve
        string ans;
        for(int x = 0;x < s1.length();x++){
            if(s1[x] == s2[x]){
                ans.append("0");
            }
            else{
                ans.append("1");
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
