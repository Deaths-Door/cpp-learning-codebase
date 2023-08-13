#include <iostream>
#include <stack>
using namespace std;

/*
    Write a program that takes a stack as input and uses another stack to 
    sort the elements in the original stack in ascending order.
 */



int main(){
    int size;
    cin>>size;

    stack<int> input;
    for(int x = 0;x < size;x++){
        int y;
        cin>>y;
        input.push(y);
    }

    sort();
    return 0;
}