#include <iostream>
#include <cstring>
using namespace std;

int main(){
  	char s1[100],ans;
  	int max = -1,freq[256] = {0};
  	gets(s1);
  	int l = strlen(s1);
  	for(int x = 0;x < l;x++){
        freq[s1[x]]++;
  	}
  	for(int x = 0;x < l;x++){
        if(max < freq[s1[x]]){
            max = freq[s1[x]];
            ans = s1[x];
        }
  	}
  	cout<<ans;
  	return 0;
}
