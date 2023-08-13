#include<iostream>
using namespace std;

int main(){
   int n,f1 = 1,f2 = 1;
   cin>>n;
   cout<<"0"<<endl<<"1"<<endl<<"1"<<endl;
   for(int x = 4;;x++ ){
       int ans = f1 + f2;
       f1 = f2;
       f2 = ans;
       if(ans <= n){
          cout<<ans<<endl;
       }
       else{
          break;
       }
   }

   return 0;
}
