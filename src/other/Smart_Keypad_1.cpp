#include <iostream>
#include <string>
using namespace std;

string table[]= {" ",".+@$","abc","def",
                      "ghi","jkl","mno","pqrs",
                      "tuv","wxyz"};

void generate_codes(string s1,int len,int x,int z){
    string s2;
    if(x == len - 1){
        cout<<s2<<endl;
        return;
    }
    for(int y = x;y < len;y++){
        s2 = table[s1[z]];
        swap(s2[x],s2[x]);
        generate_codes(s1,len,x + 1,z);
        swap(s2[x],s2[x]);
    }
}


int main(){
    string s1;
    cin>>s1;
    generate_codes(s1,s1.length(),0,0);
    return 0;
}

