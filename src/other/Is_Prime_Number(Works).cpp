#include <iostream>
using namespace std;
int main(){
  int n,p = 0;
  cin>>n;
  for(int x = 2; x <= (n /2); x++){
      if(n % x == 0){
          cout<<"Not Prime";
          p = 1;
          break;
      }
  }
  if (p == 0){
      cout<<"Prime";
  }
  return 0;
}
