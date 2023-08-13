#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
	int a[n][n];
    for(int x = 0;x < n;x++){
        for(int y = 0;y < n;y++){
            cin>>a[x][y];
        }
    }
    //Transpose
    for (int x = 0;x < n;x++){
		for (int y = x;y < n;y++){
			swap(a[x][y],a[y][x]);
        }
    }
    //Reverse Col
    for (int x = 0;x < n;x++){
        int k = n - 1;
		for (int y = 0;y < k;y++){
			swap(a[y][x],a[k][x]);
            k--;
        }
    }
    for (int x = 0;x < n;x++) {
		for (int y = 0;y < n;y++){
			cout<<a[x][y]<<" ";
        }
		cout<<endl;
	}
	return 0;
}
