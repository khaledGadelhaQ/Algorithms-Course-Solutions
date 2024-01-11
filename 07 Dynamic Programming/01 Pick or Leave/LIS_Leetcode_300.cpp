#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    const int MAX = 2501;

    int memory[2501][2501];

    int LIS(int indx, int prvIndx, vector<int>& nums){

        if(indx >= nums.size())
          return 0;

        auto &ref = memory[indx][prvIndx];
        if(ref != -1)
          return ref;

        int leave = LIS(indx+1 , prvIndx, nums);
        int pick = 0;
        if(prvIndx >= nums.size() || nums[prvIndx] < nums[indx])
            pick = 1 + LIS(indx+1 , indx, nums);

        return ref = max(leave,pick);
    }
            
    int lengthOfLIS(vector<int>& nums) {
        memset(memory,-1,sizeof(memory));
        return LIS(0, nums.size(), nums);
    }

};