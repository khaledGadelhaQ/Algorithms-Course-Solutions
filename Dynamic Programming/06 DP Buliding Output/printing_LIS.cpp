#include <bits/stdc++.h>
using namespace std;


const int MAX = 2501;
int memory[2501][2501];

class Solution {
private:
int LIS(int indx, int prvIndx, vector<int> nums){
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

void LIS_Print(int indx, int prvIndx, vector<int> nums){
    if(indx >= nums.size())
        return;
    int optimal = LIS(indx,prvIndx,nums);
    int leave = LIS(indx+1 , prvIndx, nums);
    int pick = 0;
    if(prvIndx >= nums.size() || nums[prvIndx] < nums[indx])
        pick = 1 + LIS(indx+1 , indx, nums);
    
    if(optimal == leave){
        LIS_Print(indx+1, prvIndx, nums);
    }else{
        cout<<nums[indx] <<" ";
        LIS_Print(indx+1 , indx, nums);
    }
}
public:
    int lengthOfLIS(const vector<int>& nums) {
        memset(memory,-1,sizeof(memory));
        int ans = LIS(0, nums.size(), nums);
        LIS_Print(0,nums.size() , nums);
        return ans;
    }



};

int main(){
    Solution().lengthOfLIS({ 10, 9, 2, 5, 3, 7, 101, 18 });
    return 0;
}