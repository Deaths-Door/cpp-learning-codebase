#include  <iostream>
using namespace std;

int main(){
    int m,n,k,s;
    cin>>m>>n>>k>>s;
    char park[100][100];
    //Take Input
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>park[i][j];
        }
    }
    //Piyush can get out of the park
    bool success = true;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            char ch = park[i][j];
            //Check
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
            //We loose 1 point when moving right except the last column
            if(j != n - 1){
                s--;
            }
        }
    }
    if(success){
        cout<<"Yes"<<endl;
        cout<<s<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
