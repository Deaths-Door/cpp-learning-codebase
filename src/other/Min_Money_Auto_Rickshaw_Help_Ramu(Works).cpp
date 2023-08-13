#include <iostream>
using namespace std;

/**
1 3 7 19 - tickets
2 3 -  no. used ricks/cabs
2 5 -  no. of times used ricks
4 4 4 - no. of times used cabs
**/

int main(){
    //Testcases
    int t;
    cin>>t;
    while(t--){
        //Ticket costs
        int c1,c2,c3,c4;
        cin>>c1>>c2>>c3>>c4;

        //No. of rickshaws and cabs
        int n,m;
        cin>>n>>m;

        //No. of times rickshaws used
        int rickshaws;
        int cost_rickshaws = 0;
        for(int x = 0;x < n;x++){
            cin>>rickshaws;
            //Cost of rickshaws
            cost_rickshaws += min(rickshaws * c1,c2);
        }
        //Total cost of rickshaws
        cost_rickshaws = min(cost_rickshaws,c3);

        //No. of times cabs used
        int cab;
        int cost_cab = 0;
        for(int x = 0;x < m;x++){
            cin>>cab;
            //Cost of cabs
            cost_cab += min(cab * c1,c2);
        }
        //Total Cost of cabs
         cost_cab = min(cost_cab,c3);

        //Total Final cost
        int tfc = min(cost_rickshaws + cost_cab,c4);
        cout<<tfc<<endl;
    }
    return 0;
}

