#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> row1;
vector<int> row2;

void input(vector<int> row1,vector<int> row2){
	//Input
	int n = 0;
	//Till 2 not found skip
	while(n != 2){
		for(int x = 0;x < 5;x++){
			cin>>n;
			row1.push_back(n);
			//found ?
			if(n == 2){
				break;
			}
		}
	}
	//2 found now next row
	//Till last row input
	while(row2.empty()){
		for(int x = 0;x < 5;x++){
				cin>>n;
				row2.push_back(n);
		}
		//Print directions
		directions(row1,row2);
		//Next 2 rows
		row1 = row2;
		row2.erase();
	}
	return;
}

void directions(vector<int> row1,vector<int> row2){
	vector<int> dist;
	//Pos of 2 in row1
	vector<int> :: iterator curr_pos;
	curr_pos = find(row1.begin(),row1.end(),2);
	//last row and last pos
	if(row2.empty() and row1.at(5) == 2){
		return;
	}
	//Last row ,not last pos
	if(row2.empty() and row1.at(5) != 2){
		dist = 5 - curr_pos;
		cout<<"R"<<dist(0)<<endl;
		return;
	}
	//Otherwise
	//pos of 1
	vector<int> :: iterator pos;
	pos = find(row1.begin(),row1.end(),1);
	//Distance
	dist = curr_pos - pos;
	//Print direction
	(curr_pos > pos) cout<<"L"<<dist(0) : cout<<"R"<<dist(0);\
	return;
}

int main(){
	input(row1,row2);
	return 0;
}

take 1 input row1 vector if not 2 found in vector row1 skip
if found then input row2
find the no. of steps down,left,right
if last row last pos then return
	else last row not last pos find dist
	dist = 5 - currpos
	print R(dist);
otherwise
	curr pos = 2
	then curr pos = curr pos - dist
	go from curr pos to 1
	then go down
	if not 1 found then go to (x,5)

