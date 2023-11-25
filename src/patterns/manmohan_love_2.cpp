#include <iostream>
using namespace std;

int main(){
    //Rows
    int n;
    cin>>n;
    //Print
    cout<<"1"<<endl;
    for(int x = 1;x < n;x++){
        for(int y = 0;y <= x;y++){
            if(y != 0 and  y != x){
                cout<<"0";
            }
            else{
                cout<<x;
            }
        }
        cout<<endl;
    }
    return 0;
}


