#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
	int n,a[1000];
	cin>>n;
	for(int x = 0;x < n;x++){
        cin>>a[x];
	}
	for(int x = 0;x < n - 1;x++){
        int min_i = x;
        for(int y = x + 1;y < n;y++){
            if(a[y] < a[min_i]){
                min_i = y;
            }
            swap(&a[min_i],&a[x]);
        }
	}
	for(int x = 0;x < n;x++){
        cout<<a[x]<<endl;
	}
	return 0;
}
