#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    //Up
    for(int x = 1;x <= (n /2);x++){
        for(int y = (n /2);y >= 1;y--){
            if(x <= y){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        for(int y = 1;y <= x;y++){
            cout<<"* ";
        }
        cout<<endl;
    }
    //Mid
    for(int x = 1;x <= n;x++){
        cout<<"* ";
    }
    cout<<endl;
    //Down
    for(int x = 1;x <= (n /2);x++){
        for(int y = 1;y <= (n /2);y++){
            if(x >= y){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        for(int y = (n /2);y >= 0;y--){
            if(x <= y){
                cout<<"* ";
            }
        }
        cout<<endl;
    }
	return 0;
}
