#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/// using unordered-map , sorting and binary search
// O(nlogn) , sorting is O(nlog n) and binary search is O(log n)
// so total time complexity O(nlogn) and space O(n) 
class Solution {
public:
    int lower_bound(vector<vector<int>> &v, int val) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid][0] < val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }


    vector<int> findRightInterval(vector<vector<int>>& arr) {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i][0]] = i;
        }
        sort(arr.begin(), arr.end());
        vector<int> res ( arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            int indx = lower_bound(arr, arr[i][1]);
            if(indx >= 0 && indx < arr.size()){
               int origIdx = map[arr[i][0]];
               indx = arr[indx][0];
               res[origIdx] = map[indx];
            }
        }
        return res;
    }

};

int main(){
    return 0 ;
}