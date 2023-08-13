#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num(string trajectory,int a){
    //find number
    string s1 = "";
    while(trajectory.length() - 1 != ' '){

        //Number to string
        s1.push_back(trajectory.length() - 1);

        //Removing last char
        trajectory.erase(trajectory.length() - 1);
    }
    //To number
    reverse(s1.begin(),s1.end());
    return stoi(s1);
}

int hit(string trajectory,int ix,int iy){
    //Find b
    int b = num(trajectory,iy);

    //Removing space
    trajectory.erase(trajectory.end() - 1);

    //Find + or -
    char op = trajectory.length() - 1;

    //Removing space and x
    trajectory.erase(trajectory.end());
    trajectory.erase(trajectory.end());

    //Find m
    int m = num(trajectory,ix);

    //Hit?
    if(op == '+'){
        /*if(iy == m * ix - b){
            return true;
        }
        else{
            return false;
        }*/
        (iy == m * ix - b) ? return 1 : return 0;
    }
    else{
       /* if(iy == m * ix + b){
            return true;
        }
        else{
            return false;
        }*/
        (iy == m * ix + b) ? return 1 : return 0;
    }
    return false;
}

int main(){
    //Input
    string trajectory;
    getline(cin,trajectory);

    //Cords
    int ix,iy;
    cin>>ix>>iy;

    cout<<hit(trajectory,ix,iy);
    return 0;
}
