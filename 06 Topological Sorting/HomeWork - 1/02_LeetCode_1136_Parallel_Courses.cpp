#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Graph;

void add_directed_graph(Graph& graph, int from, int to){
    graph[from].push_back(to);
}

class Solution{
private:
    int topo(Graph &adjList, int n){
        int sz = adjList.size();
        vector<int> indegree(sz, 0);
        for(int i = 0; i < sz; i++){
            for(auto val : adjList[i])
                indegree[val]++;
        }
            
            
        queue<int> q;
        for(int i = 0; i < sz; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int totalNumOfNodes = 0;
        int semester = 0;
        int currentLevel {0};

        while(!q.empty()){
            currentLevel = q.size();
            while(currentLevel--){
                int front = q.front();
                q.pop();
                totalNumOfNodes++;
                for(auto val: adjList[front]) 
                    if(--indegree[val] == 0)
                      q.push(val);
            }
            semester++;
        }

        return totalNumOfNodes == n ? semester : -1;
    }  

public:
    int minimumSemesters(int n, vector<vector<int>>& relations){
        Graph graph(n);

        for(int i = 0; i < relations.size(); i++){
            int from = relations[i][0]-1;
            int to = relations[i][1]-1;
            add_directed_graph(graph, from, to); 
        }
        
        return topo(graph, n); 
    }
};

int main(){
    Solution s;
    vector<vector<int>> v;
    v.push_back({1,3});
    v.push_back({2,3});
    
    cout << s.minimumSemesters(3, v);
}
