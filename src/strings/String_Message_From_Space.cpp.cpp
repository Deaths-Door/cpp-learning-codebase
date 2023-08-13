#include <iostream>
#include <string>
using namespace std;

string s1;

bool brackets(int* x,int* pos,int* nested){
	if(s1[*x] == '['){
	    //Nested Bracket
	    while(s1[*x] == '['){
	        *nested = *nested + 1;
	        *x++;
	    }
	    if(*nested > 0){
	        //Start at og x value
	       *x = *x - *nested;
	        return true;
	    }
	    //Start at og x value
	    *x = *x - *nested;

	    //End of bracket
		while(s1[*x] != ']' and nested > 0){
		    *nested = *nested - 1;
			*pos = *pos + 1;
			*x++;
		}
		return true;
	}
	return false;
}


int number(int x,int pos){
	string n = "";
	//Ascci value of 0 - 9
	while((int)s1[x] >= 48 and (int)s1[x] <= 57){
		//Add x digit to n
		n.append(s1,x,1);
	}

	//Int value of string
	return stoi(n);
}

string decrypt(string s1){
	string decrypted = "";
	for(int x = 0;x < s1.length();x++){
		//Pos for ]
		int pos;

		//Check for brackets
		int nested = 0;
		bool found = brackets(&x,&pos,&nested);
		x = x + nested;

		//Number
		int n = number(x,pos);

		//Character start and end
		int s = x + to_string(n).length() + 1;
		int e = pos - 1;

		//From s to e - s = character
		string chs = "";
		chs.append(s1,s,e - s);

		//Insert decrypted msg
		decrypted.insert(n,chs);

		//change x + by n,chs,nested,1(end)
		x = x + to_string(n).length() + chs.length() + nested + 1;

	}
	return decrypted;
}

int main(){
	cin>>s1;
	cout<<decrypt(s1);
}
