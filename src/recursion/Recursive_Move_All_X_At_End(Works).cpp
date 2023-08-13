// C++ implementation to Move all occurrence of letter ‘x’
// from the string s to the end using Recursion
#include <bits/stdc++.h>
using namespace std;

// Function to move all 'x' in the end
void moveAtEnd(string s, int i, int l)
{
	if (i >= l)
		return;

	// Store current character
	char curr = s[i];

	// Check if current character is not 'x'
	if (curr != 'x')
		cout << curr;

	// recursive function call
	moveAtEnd(s, i + 1, l);

	// Check if current character is 'x'
	if (curr == 'x')
		cout << curr;

	return;
}

// Driver code
int main(){
	string s = "geekxsforgexxeksxx";

	int l = s.length();

	moveAtEnd(s, 0, l);

	return 0;
}
