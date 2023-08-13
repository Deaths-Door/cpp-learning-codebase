#include <iostream>
using namespace std;

int main(){
    int m,n,k,s;
    cin>>m>>n>>k>>s;
    char park[100][100];
    for(int rw = 0;rw < m;rw++){
        for(int cl = 0;cl < n;cl++){
            cin>>park[rw][cl];
        }
    }
    bool success = true;
    for(int rw = 0;rw < m;rw++){
        for(int cl = 0;cl < n;cl++){
            char ch = park[rw][cl];
            if(s < k){
                success = false;
                break;
            }
            if(ch == '*'){
                s += 5;
            }
            else if(ch == '.'){
                s -= 2;
            }
            else{
                break;
            }
            if(cl != n - 1){
                s--;
            }
        }
    }
    if(success){
        cout<<"Yes"<<endl<<s<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
