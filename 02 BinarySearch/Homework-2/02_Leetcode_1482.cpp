#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
* Time complexity: O(nlog k) (k is the diffrence between min and max elements)
*  Space complexity: O(1)
*/

class Solution {
public:
    bool possible(vector<int> v , int mid, int m , int k){
        int sum {0}, count {0};
        for(auto val : v){
           if(mid >= val){
               count++;
               if(count == k){
                   sum++;
                   count = 0;
               }
               if(sum == m) return true;
           }else{
               count = 0;
           }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m > (bloomDay.size()/k) ) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int res {-1};
        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(bloomDay,mid, m , k)){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}