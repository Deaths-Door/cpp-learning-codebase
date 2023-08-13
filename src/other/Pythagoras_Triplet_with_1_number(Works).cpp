#include <iostream>
using namespace std;

int main(){
    /* 1LL is short for type 1 of long long

    The ints are not promoted to long long
    before multiplication, they remain ints and
    their product as well. Then the product is cast
    to long long, but we are late now as overflow has
    already occurred

    Using 1LL promotes to long long b4 multiplication
    */
	long long int n;
	cin>>n;
	if (n == 1 || n == 2)
		cout<<"No Pythagoras Triplet exists";

	else if (n % 2 == 0){
		// Calculating for even case
		long long int yz = 1LL * n * n / 4;
		cout<<n<<" "<<yz - 1<<" "<<yz + 1;
	}
	else{
		// Calculating for odd case
		long long int yz = 1LL * n * n + 1;
		cout<<n<<" "<<yz / 2 - 1<<" "<<yz / 2;
	}
	return 0;
}
