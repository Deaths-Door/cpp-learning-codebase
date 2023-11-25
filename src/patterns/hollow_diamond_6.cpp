#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int idx = (n/2) + 1;
    int star;
    for(int x = 1;x <= n;x++){
        int y;
        for(y = 1;y <= n;y++){
            if(x == 1 or x == n){
                cout<<"* ";
            }
            else if(x >= 2 and x <= (n/2) + 1){
                if(y < idx or y > idx){
                    cout<<"* ";
                }
                else if(y < n - star - x){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
            else{

            }
        }
        if((x >= 2 and x <= (n/2) + 1)){
            idx--;
            star = y;
        }
        cout<<endl;
    }
    return 0;
}


#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int idx = (n /2) + 1;
    int star = (n /2);
    for(int x = 1;x <= n;x++){
        int pspc = 1;
        for(int y = 1;y <= n;y++){
            if(y == idx){
                pspc = 0;
            }
            if(x == 1 or x == n){
                cout<<"* ";
            }
            else if(pspc == 0 and y <= n - star){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        if(x >= 2 and x <= (n/2) + 1){
            idx--;
            star--;
        }
        if(x == (n/2) + 1){
            idx += 1;
        }
        if(x < n and x >= (n/2) + 1){
            idx += 1;
            star = star + 2;
        }
        if(x == n - 1){
            //idx = (n/2) + 1;
            //star = (n/2);
            idx = (n/2);
        }
        cout<<endl;
    }
    return 0;
}

