#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 +1 ;
int memo[MAX][MAX]; 

bool isValid(int prv, int indx, vector<vector<int>> &cuboids){
  return cuboids[prv][1] <= cuboids[indx][1] && cuboids[prv][2] <= cuboids[indx][2];
}

int LIS(int indx , int prv, vector<vector<int>> &cuboids){
   
    if(indx == cuboids.size())
      return 0; 

    auto &ret = memo[indx][prv];
    if(ret != -1)
       return ret;

    int leave = LIS(indx+1, prv, cuboids);
    int pick = 0 ;
    if(prv >= cuboids.size() || isValid(prv,indx,cuboids))
       pick = cuboids[indx][2] + LIS(indx+1, indx, cuboids);
    return ret = max(leave,pick);

    
}


class Solution {
public:
	int maxHeight(vector<vector<int>> &cuboids) {
        memset(memo, -1 , sizeof(memo));
        for(auto &c : cuboids)
           sort(c.begin(), c.end());

        sort(cuboids.begin(), cuboids.end());
        return LIS(0,cuboids.size(),cuboids);
        
	}
};

int main(){
    return 0;
}
/*
we need to find the subset that has the maximum height 
subset means we can choose some cuboid and leave some
so first thing come to mind is to sort the 3 values for every cuboid 
so that the height is the largest 
second thing is to sort the whole cuboids in the cuboids vector
now we the solution is to find the longest increasing sequence (LIS)
and that is the answer

*/