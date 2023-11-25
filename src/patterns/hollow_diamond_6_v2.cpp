#include <iostream>
using namespace std;

int main (){
    int n;
    cin>>n;
    int star = (n/2);
    int spc = 1;
    for(int y = 1;y <= n;y++){
        cout<<"* ";
    }
    cout<<endl;
    for(int x = 1;x < (n/2)+ 1;x++){
        for(int y = 1;y <= star;y++){
            cout<<"* ";
        }
        for(int y = 1;y <= spc;y++){
            cout<<"  ";
        }
        for(int y = 1;y <= star;y++){
            cout<<"* ";
        }
        star--;
        spc += 2;
        cout<<endl;
    }
    star = 2;
    spc = (n - 2) - star;
    for(int x = 1;x <= (n/2) - 1;x++){
        for(int y = 1;y <= star;y++){
            cout<<"* ";
        }
        for(int y = 1;y <= spc;y++){
            cout<<"  ";
        }
        for(int y = 1;y <= star;y++){
            cout<<"* ";
        }
        star++;
        spc -= 2;
        cout<<endl;
    }
    for(int y = 1;y <= n;y++){
        cout<<"* ";
    }
    return 0;
}
