#include <iostream>
using namespace std;

int main(){
    int rwn;
    cin>>rwn;
    for(int x = 2;x <= rwn + 1;x++){
        if(x == 2){
            for(int spc = 0;spc <= rwn - x;spc++){
                cout<<" ";
            }
            for(int y = 0;y <= rwn - 1;y++){
                cout<<"*";
            }
            cout<<endl;
        }
        else if(x == rwn + 1){
            for(int spc = 0;spc <= rwn - x;spc++){
                cout<<" ";
            }
            for(int y = 0;y <= rwn - 1;y++){
                cout<<"*";
            }
            cout<<endl;
        }
        else{
            for(int spc = 0;spc <= rwn - x;spc++){
                cout<<" ";
            }
            cout<<"*";
            for(int y = 3;y <= rwn;y++){
                cout<<" ";
            }
            cout<<"*"<<endl;;
        }
    }
    return 0;
}
