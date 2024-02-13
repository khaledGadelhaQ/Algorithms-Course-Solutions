#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, cnt = 0;
        for(int i = nums.size()-1 ; i > 0 ;){
            int j = i-1;
            for(; j >=0 ; j--){
                if(nums[i] != nums[j]) break;
            }
            if(j < 0 ) break;
            cnt += i - j;
            res += cnt;
            i = j;
        }
        return res;
    }
};

class Solution2 {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int res = 0;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i] != nums[i-1])
                res += i;
        }
        return res;
    }
};