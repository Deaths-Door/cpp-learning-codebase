#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int pn;
    //up
    for(int x = 1;x <= (n/2);x++){
        pn = 1;
        //increasing
        for(int y = (n/2);y >= 1;y--){
            if(x <= y){
                cout<<"  ";
            }
            else{
                cout<<pn<<" ";
                pn++;
            }
        }
        //decreasing
        for(int y = 1;y <= x;y++){
            cout<<pn<<" ";
            pn--;
        }
        cout<<endl;
    }
    //mid
    pn = 1;
    for(int x = 1;x <= n;x++){
        cout<<pn<<" ";
        if(x <= (n/2)){
            pn++;
        }
        else{
            pn--;
        }
    }
    cout<<endl;

    for(int x = 1;x <= (n/2);x++){
        pn = 1;
        for(int y = 1;y <= (n/2);y++){
            if(x >= y){
                cout<<"  ";
            }
            else{
                cout<<pn<<" ";
                pn++;
            }
        }
        for(int y = (n/2);y >= 0;y--){
            if(x <= y){
                cout<<pn<<" ";
                pn--;
            }
        }
        cout<<endl;
    }

   /*
    //Down
    for(int x = 1;x <= (n /2);x++){
        for(int y = 1;y <= (n /2);y++){
            if(x >= y){
                cout<<"  ";
            }
            else{
                cout<<pn<<" ";
            }
        }
        for(int y = (n /2);y >= 0;y--){
            if(x <= y){
                cout<<pn<<" ";
            }
        }
        cout<<endl;
    }*/
	return 0;
}

