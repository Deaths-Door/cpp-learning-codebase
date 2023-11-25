#include <iostream>
#include <string>
using namespace std;

string expand(string s1){
	//Expanded string
	string expanded = "";
	//Number of 0s
	int zeros = s1.length() - 1;
	for(int x = 0;x < s1.length();x++){
	    if(s1[x] == '0'){
	        zeros--;
	        continue;
	    }
	    //Add number
		expanded.append(s1,x,1);
		//Add 0s
		expanded.append(zeros,'0');
		//Add plus
		if(x != s1.length() - 1 and (x + 1) != s1.length() - 1){
		    expanded.append({' ','+',' '});
		}
		zeros--;
	}
	return expanded;
}

int main(){
	//Input
	string s1;
	cin>>s1;
	cout<<expand(s1);
}
