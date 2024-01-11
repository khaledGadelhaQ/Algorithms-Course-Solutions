#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size() || arr[start] <0) return false;
        arr[start] = -arr[start];
        return arr[start] == 0 || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};