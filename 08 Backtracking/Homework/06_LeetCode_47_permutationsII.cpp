#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    vector<bool> used;
    void solve(vector<int>& nums){
        if(res.size() == nums.size()){
            ans.push_back(res);
            return;
        }
        
        for(int j = 0 ; j < nums.size() ; j++){
            if(used[j] || j > 0 && nums[j] == nums[j-1] && !used[j-1] ){
                continue;
            }
            used[j] = true;
            res.push_back(nums[j]);
            solve(nums);
            res.pop_back();
            used[j] = false;

            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        used = vector<bool> (nums.size(), false);
        solve(nums);
        return ans;
    }
};