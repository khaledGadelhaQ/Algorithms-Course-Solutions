#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int l = 0 , r = nums.size()-1;
        while( l < nums.size()){
            if(nums[l] != tmp[l]){
                break;
            }
            l++;
        }
        if(l == nums.size()) return 0;
        while(r >= 0){
            if(nums[r] != tmp[r]){
                break;
            }
            r--;
        }
        nums = tmp;
        return r - l + 1;
    }
};

class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1 , r = nums.size()-1;
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int i = 0, j = nums.size()-1 ; i < nums.size() && j >= 0; i++, j--){
            maxVal = max(maxVal, nums[i]);
            if(nums[i] < maxVal) r = i;
            minVal = min(minVal, nums[j]);
            if(nums[j] > minVal) l = j;
        }
        return l == -1? 0 : r - l + 1;
    }
};

int main(){
    return 0;
}