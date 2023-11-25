#include <iostream>
#include <cstring>
using namespace std;

int main(){
    bool reverse = true;
    char s1[1000];
    char s2[1000];
    gets(s1);
    gets(s2);
    int n = strlen(s1);
    for(int x = 0;x < (n /2);x++){
        swap(s1[x],s1[n - x - 1]);
        if(s2[x] != s1[x]){
            reverse = false;
            break;
        }
    }
    if(reverse == true){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
	return 0;
}
