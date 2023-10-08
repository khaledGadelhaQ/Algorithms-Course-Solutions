#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/* Time complexity: O(N + E)
*  Space complexity: O(N + E)
*  N => number of nodes, E => number of edges
*/
typedef vector<vector<pair<int,int>>> Graph;

void add_directed_graph(Graph &graph,  int from , int to, int cost){
    graph[from].push_back({to,cost});
}

void add_undirected_graph(Graph &graph, int from, int to, int cost){
    graph[from].push_back({to,cost});
    graph[to].push_back({from,cost});
}

void print_graph(Graph &graph){
    int nodes = graph.size();
    for(int i = 0 ; i < nodes ; i++){

        for(auto val: graph[i]){
            cout<<"From "<<i<<" to "<<val.first
            <<" the cost = "<<val.second<<endl;
        }
    }
}

 
int main(){
     
    cout << "Enter Num of Nodes - Edges: \n";
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);
    for (int i = 0 ; i < edges ; i++ ){
        int from, to, cost;
        cin >> from >> to >> cost;
        add_directed_graph(graph, from , to , cost);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 

/*
Enter Num of Nodes - Edges:
5 10
0 1 10
1 2 7
0 1 7
2 3 9
2 3 15
3 4 50
0 4 52
0 4 30
2 4 36
4 0 150

Output
From 0 to 1 the cost = 10
From 0 to 1 the cost = 7
From 0 to 4 the cost = 52
From 0 to 4 the cost = 30
From 1 to 2 the cost = 7
From 2 to 3 the cost = 9
From 2 to 3 the cost = 15
From 2 to 4 the cost = 36
From 3 to 4 the cost = 50
From 4 to 0 the cost = 150

*/
