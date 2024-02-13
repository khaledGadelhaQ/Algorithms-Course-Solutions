#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> mp;
    vector<int> ans;
    void dfs(int val, int prv){
        ans.push_back(val);
        for(auto j : mp[val]){
            if(j != prv)
                dfs(j, val);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto val : adjacentPairs){
            mp[val[0]].push_back(val[1]);
            mp[val[1]].push_back(val[0]);
        }
        for(auto val : mp){
            if(val.second.size() == 1){
                dfs(val.first,INT_MAX);
                break;
            }
        }
        return ans;
    }
};