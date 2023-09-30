#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/// O(log n ) Time , O(1) Memory

class Solution {
public:
    int findpos(vector<int> &v , int val , bool first){
      int l=  0 , r = v.size()-1 ;
      int res {-1};
      while(l <= r){
        int mid = l + (r-l)/2 ; 
        if(v[mid] == val){
            res = mid;
            if(first)
              r = mid-1;
            else
              l = mid+1;
        }else if(v[mid] < val){
            l = mid+1;
        }else{
            r = mid-1;
        }

      }
      return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findpos(nums,target,true) , findpos(nums, target,false)};
    }
};

int main(){
    return 0 ;
}