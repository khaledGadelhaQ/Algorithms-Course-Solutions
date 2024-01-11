#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int memo[2501];
        memset(memo, -1 , sizeof(memo));
        memo[0] = 1;
        nums.insert(nums.end(),INT_MAX);
        for(int i = 1 ; i < nums.size() ; i++){
            memo[i] = 1;
            for(int j = i - 1 ; j >= 0 ; j--){
                if(nums[j] < nums[i])
                    memo[i] = max(memo[i] , 1 + memo[j]);
            }
        }
        return memo[nums.size()-1]-1;
    }
};
