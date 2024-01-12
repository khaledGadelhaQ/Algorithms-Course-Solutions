#include <bits/stdc++.h>
using namespace std;
/**
 * This solution is will give TLE when submiting it on LeetCode because of the 
 * time complexity which is O(k^N)
*/
class Solution {
public:
    vector<int> partitions;
    int sum;
    vector<int> nums;
    bool tryPartition(int idx){
        if(idx == nums.size()) return true;
        for(int p = 0 ; p < partitions.size() ; p++){
            if( partitions[p] + nums[idx] > sum) continue;
            partitions[p] += nums[idx];
            if(tryPartition(idx+1)) return true;
            partitions[p] -= nums[idx];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums_, int k) {
        int sum_ = accumulate(nums_.begin(), nums_.end(), 0);
        if(sum_ % k != 0) return false;
        this->nums = nums_;
        this->sum = sum_/k;
        partitions = vector<int>(k, 0);
        return tryPartition(0);
    }
};