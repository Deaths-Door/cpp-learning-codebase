#include <iostream>
#include <string>
using namespace std;

string subs1;

int toint(string subs1){
    int ans = 0;
    for(int x = 0;x < subs1.length();x++){
        ans = ans * 10 + (subs1[x] - '0');
    }
    return ans;
}
//use strfind to find substring instead of this

bool cbn(string subs1){
    int intsubs1 = toint(subs1);
    if(intsubs1 == 0 or intsubs1 == 1){
        return false;
    }
    int num[10] = {2,3,5,7,11,13
                    ,17,19,23,29};
    for(int x = 0;x < 10;x++){
        if(intsubs1 == num[x]){
            return true;
        }
        if(intsubs1 %num[x] != 0){
            return true;
        }
    }
}
//find 2 in sub
/*
bool cbn(string subs1){
    string num[10] = {"2","3","5","7","11","13"
                      ,"17","19","23","29"};
    for(int x = 0;x < 10;x++){
        if(subs1 == "0" or subs1 == "1"){
            return false;
        }
        if(subs1 == num[x]){
            return true;
        }
    }
}*/

bool valid(bool visited[],int s,int e){
    for(int x = s;x < e;x++){
        if(visited[x]){
            return false;
        }
    }
    return true;
}

int main() {
    //Input
    int l;
    cin>>l;
    cin.ignore();
    string s1;
    getline(cin,s1);
    bool visited[l];
    for(int x = 0;x < l;x++){
        visited[x] = false;
    }
    int count_of_cbn = 0;
    for(int x = 1;x <= l;x++){
        for(int len = 0;len <= l - x;len++){
            int e = x + len;
            subs1 = s1.substr(len,e - len);

            if(cbn(subs1) and valid(visited,x,e)){
                count_of_cbn++;
                for(int z = x;z < e;z++){
                    visited[z] = true;
                }
            }
        }
    }
    cout<<count_of_cbn;
    return 0;
}
