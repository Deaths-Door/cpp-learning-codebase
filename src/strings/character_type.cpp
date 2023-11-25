#include <iostream>
#include <string>
using namespace std;

int main(){
    char ch;
    cin>>ch;
    char l = 'a';
    char U = 'A';
    for(int x = 0;x < 26;x++){
        if(ch == l){
            cout<<"L";
            return 0;
        }
        if(ch == U){
            cout<<"U";
            return 0;
        }
        l += 1;
        U += 1;
    }
    cout<<"I";
    return 0;
}
