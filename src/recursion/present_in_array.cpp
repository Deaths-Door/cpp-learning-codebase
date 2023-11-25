#include <iostream>
using namespace std;

int present(int n,int a[],int key,bool found){
    if(n == 0 or found == true){
        return found;
    }
    //cout<<n<<"-"<<key<<endl;
    if(a[n] == key){
        found = true;
    }
    present(n--,a,key,found);
}

int main(){
    int n,a[1000],key;
    cin>>n;
    for(int x = 0;x < n;x++){
        cin>>a[x];
    }
    cin>>key;
    int temp = present(n - 1,a,key,false);
    (temp == 1) ? cout<<"true" : cout<<"false";
}
