#include <bits/stdc++.h>
using namespace std;

const int MAX = 2501;
int memory[2501];
class Solution {
private:
    int LIS(int i,vector<int>& nums){
        if( i >= nums.size())
            return 0 ;
        auto &ref = memory[i];
        if(ref != -1)
            return ref;
        ref = 0;
        for (int  j = i+1 ; j < nums.size() ; j++){
            if(nums[j] > nums[i])
                ref = max(ref, LIS(j,nums));
        }
        
        return ++ref;
    }  

    void LIS_Print(int i,vector<int>& nums){
        if( i >= nums.size())
            return ;
        int res = 0;
        for (int  j = i+1 ; j < nums.size() ; j++){
            if(nums[j] > nums[i])
                res = max(res, LIS(j,nums));
                LIS_Print(j,nums);
        }
        cout << res << " ";
    }
public:
    int lengthOfLIS(vector<int> nums) {
        memset(memory,-1,sizeof(memory));
        nums.insert(nums.begin(),INT16_MIN);
        int ans = LIS(0,nums) - 1;
        LIS_Print(0,nums);
        return  ans;
    }
};
int main(){
    Solution().lengthOfLIS({ 10, 9, 2, 5, 3, 7, 101, 18});
}