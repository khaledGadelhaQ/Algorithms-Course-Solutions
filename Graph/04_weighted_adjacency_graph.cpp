#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<pair<int,int>>> Graph;

void directed_graph(Graph &graph,  int from , int to, int cost){
    graph[from].push_back({to,cost});
}

void undirected_graph(Graph &graph, int from, int to, int cost){
    graph[from].push_back({to,cost});
    graph[to].push_back({from,cost});
}

void print_graph(Graph &graph){
    int nodes = graph.size();
    for(int i = 0 ; i < nodes ; i++){
         
        cout << " The node " << i <<" has neighbours: ";
        for(auto val : graph[i])
            cout << "( to "<<val.first <<" with cost: "<< val.second<<") ";
        cout<<endl;
    }
}
 
int main(){
     
    cout << "Enter the number of nodes and the number of edges: \n";
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);
    for (int i = 0 ; i < edges ; i++ ){
        int from, to, cost;
        cin >> from >> to >> cost;
        directed_graph(graph, from , to, cost);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 

/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10

Output
Node 0 has neighbors: (to 5 cost 45)
Node 1 has neighbors: (to 4 cost 60)
Node 2 has neighbors: (to 1 cost 10) (to 5 cost 20) (to 0 cost 77) (to 3 cost 33)
Node 3 has neighbors:
Node 4 has neighbors:
Node 5 has neighbors: (to 4 cost 10)

 */

