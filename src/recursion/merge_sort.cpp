#include<iostream>
using namespace std;

/*void swapping(int &a, int &b) {
   int tmp;
   tmp = a;
   a = b;
   b = tmp;
}*/

void merge(int *array,int s,int mid,int e) {
   int x,y,k;
   int ns = mid - s + 1;
   int ne = e - mid;
   int sa[ns], ea[ne];
   for(x = 0;x < ns;x++){
      sa[x] = array[s + x];
   }
   for(y = 0;y < ne;y++){
      ea[y] = array[mid + 1 + y];
   }
   x = 0;
   y = 0;
   k = s;
   while(x < ns && y < ne) {
      if(sa[x] <= ea[y]) {
         array[k] = sa[x];
         x++;
      }else{
         array[k] = ea[y];
         y++;
      }
      k++;
   }
   while(x < ns) {
      array[k] = sa[x];
      x++;
      k++;
   }
   while(y < ne){
      array[k] = ea[y];
      y++;
      k++;
   }
}
void mergeSort(int *array,int s,int e) {
   int mid;
   if(s < e) {
      int mid = s + (e - s)/2;
      mergeSort(array, s, mid);
      mergeSort(array, mid + 1,e);
      merge(array, s,mid,e);
   }
}
int main(){
   int n;
   cin >> n;
   int arr[n];
   for(int x = 0;x < n;x++) {
       cin>>arr[x];
   }
   mergeSort(arr, 0, n-1);
   for(int x = 0;x < n;x++){
       cout<<arr[x]<<" ";
   }
}
