
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
* Time complexity:
* sorting the array is O(nlog n)
* The two nested loops are O(n^2)
* Total is : O(n^2 log n) 
* space complexity: O(1)
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum {0};
        int sz = nums.size();
        for(int i = sz-1 ; i > 1 ; i--){
            
            for(int j = i-1, k = 0; j > k ; ){
                if(nums[i] < nums[k] + nums[j]){
                    sum += j - k;
                    j--;
                }else{
                    k++;
                }
            }
            
        }
        return sum;
    }
};

int main(){
    return 0 ;
}