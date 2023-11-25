#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int cal(int x){
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, x) / sqrt(5));
}

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

string fib(string s1){
    string b;
    //46 is limit for long long int
    if(stoi(s1) <= 46){
        //46
        b = to_string(cal(stoi(s1)));
        return b;
    }
    //45
    string a = to_string(cal(45));
    //Calculating ahead
    string phi = to_string((1 + sqrt(5)) / 2);
    string ans = multiply(phi,s1);
    return ans;
}

int main(){
    string s1;
    cin>>s1;
    cout<<fib(s1);
    return 0;
}
