#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int a[], int l, int h){
	int pivot = a[h];
	int i = (l - 1);
	for (int j = l; j <= h- 1; j++){
		if (a[j] <= pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[h]);
	return (i + 1);
}

void quickSort(int a[], int l, int h){
	if (l < h){
		int pi = partition(a, l, h);
		quickSort(a, l, pi - 1);
		quickSort(a, pi + 1, h);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int x = 0;x < n;x++){
        cin>>a[x];
	}
	quickSort(a,0,n - 1);
	for(int x = 0;x < n;x++){
        cout<<a[x]<<" ";
	}
	return 0;
}

