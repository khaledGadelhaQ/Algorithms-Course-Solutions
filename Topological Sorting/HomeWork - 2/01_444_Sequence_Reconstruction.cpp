#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<int,vector<int>> Graph;

void add_directed_graph(Graph &graph, int from, int to) {
    graph[from].push_back(to);
}

class Solution {
private:
    vector<int> topo(Graph &adjList) {
        unordered_map<int,int> indegree;
        
        for(auto pair : adjList){
            for(auto val : pair.second)
              indegree[val]++;
        }

        queue<int> q; // stores the nodes with indegree == 0 
        for(auto pair : adjList ){
            if(!indegree.count(pair.first))
              q.push(pair.first);
        }
        vector<int> order;
        while(!q.empty()){
            /*
             * for a unique order , we can't have more than one
             * node with indegree equal zero because then we will have 
             * multiply different orders
            */
            if(q.size() > 1)
                return vector<int>();
            int front = q.front();
            q.pop();
            order.push_back(front);
            for(auto val : adjList[front])
               if(--indegree[val] == 0)
                   q.push(val);
            
        }
        if(order.size() != adjList.size())
          return vector<int>();
        return order;

    }
    

public:
    bool sequenceReconstruction(vector<int> org, vector<vector<int>> &seqs) {
        Graph adjList(org.size());
        /// Building a directed graph
        for(auto seq : seqs){
            for(int i = 0 ; i < seq.size()-1 ; i++){
                add_directed_graph(adjList,seq[i],seq[i+1]);
            }
        }

        /// specail case for seq with one element
        for(auto seq : seqs){
            if(seq.size() == 1 && !adjList.count(seq[0]))
              adjList[seq[0]] = vector<int>(); // empty vector
        }

        //compare the order of the topological sort algorithm with the 'org'
        //they must be equal to return true as it is stated that a supersequence
        //is a sequence with unique order

        vector<int> order =  topo(adjList);
        
        return order == org;


    }
};

int main() {
    Solution s;
    vector<vector<int>> v;
    v.push_back({1, 2});
    v.push_back({2, 3});
    v.push_back({1, 3});

    cout << s.sequenceReconstruction({1, 2, 3}, v);
}
