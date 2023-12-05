#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memo[MAX][MAX];

int dp(int i, int prev, vector<int>& nums) {
	if (i == (int) nums.size())
		return 0;

	auto &ret = memo[i][prev];

	if (ret != -1)
		return ret;

	int choice1 = dp(i + 1, prev, nums);	// Leave
	int choice2 = 0;
    if(prev+1 != i)
       choice2 = nums[i] + dp(i + 1, i, nums);

	return ret = max(choice1, choice2);
}
class Solution {
public:
    int rob(vector<int> nums) {
        memset(memo, -1, sizeof(memo));
        int ret = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            int st = dp(i,nums.size() , nums);
            ret = max(ret,st);
        }
        return ret;
    }
};
int main(){
    Solution s;
    cout<< s.rob({1,2,3,1});
}