#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Multiply
string multiply(string n,string to){
    int ln = n.length();
    int lto = to.length();

    //Reverse Order
    vector<int> product(ln + lto,0);
    //Positions in product
    int xn = 0;
    int xto = 0;

    //Right to left
    for(int x = ln - 1;x >= 0;x--){

        int carry = 0;
        int num1 = n[x] - '0';
        xto = 0;

        for(int y = lto - 1;y >= 0;y--){
            //Current number
            int num2 = to[y] - '0';

            //Multiply num1[x] and num2[y] and add ans to last product
            int sum = num1 * num2 + product[xn + xto] + carry;

            // Next Carry
            carry = sum/10;

            // Store result
            product[xn + xto] = sum % 10;
            xto++;
        }
         //Last carry
        if(carry > 0){
            product[xn + xto] += carry;
        }
        xn++;
    }
    //To string
    int lproduct = product.size() - 1;
    //Removing 0s
    while(lproduct >= 0 and product[lproduct] == 0){
        lproduct--;
    }
    string ans = "";
    while(lproduct >= 0){
        ans += to_string(product[lproduct--]);
    }
    return ans;
}

//Add
string add(string n,string plus){
    //n = str1
    //plus = str2
    if(n.length() > plus.length()){
        swap(n,plus);
    }
    //Sum
    string sum = "";
    int ln = n.length();
    int lplus = plus.length();

    //Reverse
    reverse(n.begin(),n.end());
    reverse(plus.begin(),plus.end());

    int carry = 0;
	for(int x = 0;x < ln;x++){
		//Sum of digits + carry
		int total = ((n[x] - '0') + (plus[x] - '0') + carry);
		sum.push_back(total %10 + '0');
		//Next digit carry
		carry = total /10;
	}
	//Remaining Digits (larger number)
	for(int x = ln;x < lplus;x++){
		int total = ((plus[x] - '0') + carry);
		sum.push_back(total %10 + '0');
		carry = total /10;
	}
	//Remaining Carry
	if(carry){
		sum.push_back(carry + '0');
	}
	//Reversing Ans string
	reverse(sum.begin(),sum.end());
    return sum;
}

bool smaller(string n,string minus){
    if(n.length() < minus.length()){
        return true;
    }
    if(minus.length() < n.length()){
        return false;
    }
    for(int x = 0;x < n.length();x++){
        if(n[x] < minus[x]){
            return true;
        }
        else if(n[x] > minus[x]){
            return false;
        }
    }
    return false;
}

string subtract(string n,string minus){
    //n not smaller
    if(smaller(n,minus)){
        swap(n,minus);
    }
    string ans = "";
    int ln = n.length();
    int lminus = minus.length();
    int diff = ln - lminus;
    //take away
    int takeaway = 0;
    for(int x = lminus - 1;x >=  0;x--){
        //Minus
        int sub = (n[x + diff] - '0') - (minus[x] - '0') - takeaway;
        if(sub < 0){
            sub = sub + 10;
            takeaway = 1;
        }
        else{
            takeaway = 0;
        }
        ans.push_back(sub + '0');
    }
    //Remaing Digits
    for(int x = ln - lminus - 1;x >= 0;x--){
        if(n[x] == 0 and takeaway){
            ans.push_back('9');
            continue;
        }
        int sub = (n[x] - '0') - takeaway;
        if(x > 0 or sub > 0){
            ans.push_back(sub + '0');
        }
        takeaway = 0;
    }
    //reverse
    reverse(ans.begin(),ans.end());
    return ans;
}

string solve(string x){
    /*  3x^2-x+10
        4x^3 + 2x^2 -5x +4
        This simplifes to 4x ^ 3 + 5x ^ 2 -6x + 14
    */
    //sum
    string sum;
    //4x ^ 3
    string a = multiply(x,x);
    a = multiply(a,x);
    a = multiply(a,"4");

    //5x ^ 2
    string b = multiply(x,x);
    b = multiply(b,"5");

    //4x ^ 3 + 5x ^ 2x
    sum = add(a,b);

    //add
    sum =  add(sum,"14");

    // - 6x
    string c = multiply(x,"6");
    sum = subtract(sum,c);

    return sum;
}

int main(){
    string x;
    cin>>x;
    //Solve
    cout<<solve(x);
    return 0;
}
