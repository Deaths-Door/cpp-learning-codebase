#include <iostream>
using namespace std;

int Find(int a[], int s, int e, int target){
	while (s <= e){
		int mid = s + (e - s) / 2;
		if(a[mid] == target){
			return mid;
		}
		if (a[mid] < target)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return -1;
}

int main(void){
    int n,target;
    cin>>n;
	int a[n];
	for(int x = 0;x < n;x++){
        cin>>a[x];
	}
	cin>>target;
	int index = Find(a,0,n - 1,target);
	if(index != -1){
        cout<<index;
	}
	else{
        cout<<"-1";
	}
	return 0;
}
