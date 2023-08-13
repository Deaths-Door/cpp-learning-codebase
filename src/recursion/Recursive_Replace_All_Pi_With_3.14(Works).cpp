#include <iostream>
#include <string>
using namespace std;

void pi(string s1,int x,int l){
    if(x == l){
        return;
    }
    if(s1[x] == 'p' and s1[x + 1] == 'i'){
        cout<<"3.14";
        x += 1;
    }
    else{
        cout<<s1[x];
    }
    pi(s1,x + 1,l);
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t > 0){
        string s1;
        getline(cin,s1);
        pi(s1,0,s1.length());
        cout<<endl;
        t--;
    }
    return 0;
}

