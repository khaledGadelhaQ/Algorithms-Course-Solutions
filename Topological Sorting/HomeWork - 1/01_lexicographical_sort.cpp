#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Graph;

void add_directed_graph(Graph& graph , int from , int to){
    graph[from].push_back(to);
}

void topo(Graph& adjList){

    int sz = adjList.size();
    vector<int> indegree(sz, 0);
    for(int i = 0 ; i < sz ; i++){
        for(auto val : adjList[i]){
            indegree[val]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i  = 0; i < sz; i++ ){
         
        if(indegree[i] == 0)
           pq.push(i);
    }
    
    int count {0} ;

    while(!pq.empty()){
        int front = pq.top();
        pq.pop();
        cout << front << " ";
        for(auto val : adjList[front])
            if(--indegree[val] == 0)
              pq.push(val);
            
    }
}

int main(){
   
   int nodes, edges;
   cin >> nodes >> edges;
   Graph graph(nodes);
   while(edges--){
        int from, to ;
        cin >> from >> to ;
        add_directed_graph(graph,from,to);
   }
   topo(graph);
   
}
/*
Test Case 1:
input:
9 10 
5 0
5 7
6 7
6 8
0 1
7 2
8 2
1 2
2 4
2 3
output:

*/