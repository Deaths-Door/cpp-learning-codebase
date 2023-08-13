#include<iostream>
using namespace std;


int multiply(int x, int ans[], int l){
	int carry = 0;
	for (int y = 0;y < l;y++){
		int prod = ans[y] * x + carry;
		ans[y] = prod % 10;
		carry = prod/10;
	}
	while (carry){
		ans[l] = carry%10;
		carry = carry/10;
		l++;
	}
	return l;
}

int main(){
    int n;
    cin>>n;
    int ans[1200];
	ans[0] = 1;
	int l = 1;
	for (int x = 2;x <= n;x++){
		l = multiply(x, ans, l);
	}
	for (int x = l - 1;x >= 0;x--){
		cout << ans[x];
	}
	return 0;
}

