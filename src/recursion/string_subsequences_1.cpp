#include <iostream>
#include <string>
using namespace std;

void subseqs(string s1,int x,int l,string curr){
    if(x == l){
        return;
    }
    if(curr != ""){
        cout<<curr<<endl;
    }
    for(int i = x + 1;i < l;i++){
        curr += s1[i];
        subseqs(s1,i,l,curr);
        curr.erase(curr.length() - 1);
    }
}

int main(){
    string s1;
    getline(cin,s1);
    subseqs(s1,-1,s1.length(),"");
    return 0;
}

