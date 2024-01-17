#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void findPath(int i, vector<int>& onePath ,vector<vector<int>>& graph){
        onePath.push_back(i);
        if(i == n-1){
            ans.push_back(onePath);
        }
        for(auto &val : graph[i]){
            findPath(val,onePath, graph);
        }
        onePath.pop_back();

        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> onePath;
        findPath(0,onePath, graph);
        return ans;
    }
};