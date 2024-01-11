#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

void directed_graph(Graph &graph,  int from , int to){
    graph[from].push_back(to);
}

void undirected_graph(Graph &graph, int from, int to){
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void print_graph(Graph &graph){
    int nodes = graph.size();
    for(int i = 0 ; i < nodes ; i++){
         
        cout << " The node " << i <<" has neighbours: ";
        for(auto val : graph[i])
            cout << val <<" ";
        cout<<endl;
    }
}
 
int main(){
     
    cout << "Enter the number of nodes and the number of edges: \n";
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);
    for (int i = 0 ; i < edges ; i++ ){
        int from, to;
        cin >> from >> to;
        directed_graph(graph, from , to);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 
/*

6 7
2 1
2 5
2 0
2 3
0 5
1 4
5 4

Output
Node 0 has neighbors: 5
Node 1 has neighbors: 4
Node 2 has neighbors: 1 5 0 3
Node 3 has neighbors:
Node 4 has neighbors:
Node 5 has neighbors: 4

 */
