#include <cmath>
using namespace std;

int getAbsSum(vector<int> v1) {
	int asum = 0;
	for(int x = 0;x < v1.size();x++){
        asum = asum + abs(v1[x]);
  }
	return asum;
}

/*edabit.com*/
