#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int x = 0;x < n;x++){
        for(int y = 0;y < n;y++){
            //Middle Row
            if(x == n /2){
                cout<<"* ";
            }
            //Top Half
            else if(x < n /2){
                if(y < n /2){
                    if(y == 0){
                        cout<<"*";
                    }
                    else{
                        cout<<" "<<" ";
                    }
                }
                else if(y == n /2){
                    cout<<" *";
                }
                else{
                    if(x == 0){
                        cout<<" *";
                    }
                }
            }
            else{
                if(y == n/2 or y == n - 1){
                    cout<<"* ";
                }
                else if(x == n - 1){
                    if(y <= n/2 or y == n - 1){
                        cout<<"* ";
                    }
                    else{
                        cout<<" "<<" ";
                    }
                }
                else{
                    cout<<" "<<" ";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
