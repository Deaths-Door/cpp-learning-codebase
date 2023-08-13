#include <iostream>
using namespace std;

int main(){
    int n = 5;
    //Up
    for(int x = 0;x < (n * 2 - 1);x++){
        cout<<"*";
    }
    cout<<endl;
    int length = (n * 2)/2 - 1;
    int star = length;
    int spc = 1;
    for(int x = 1;x < length + 1;x++){
        for(int y = 1;y <= star;y++){
            cout<<"*";
        }
        for(int y = 1;y <= spc;y++){
            cout<<" ";
        }
        for(int y = 1;y <= star;y++){
            cout<<"*";
        }
        star--;
        spc += 2;
        cout<<endl;
    }
    //Down
    star = 2;
    spc = (n * 2 - 3) - star;
    for(int x = 1;x < length;x++){
        for(int y = 1;y <= star;y++){
            cout<<"*";
        }
        for(int y = 1;y <= spc;y++){
            cout<<" ";
        }
        for(int y = 1;y <= star;y++){
            cout<<"*";
        }
        star++;
        spc -= 2;
        cout<<endl;
    }
    for(int x = 0;x < (n * 2 - 1);x++){
        cout<<"*";
    }
    return 0;
}
