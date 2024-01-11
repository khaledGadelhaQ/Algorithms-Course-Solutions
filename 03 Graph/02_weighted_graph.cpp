#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

void directed_graph(Graph &graph,  int from , int to, int cost){
    graph[from][to] = cost;
}

void undirected_graph(Graph &graph, int from, int to, int cost){
    graph[from][to] = cost;
    graph[to][from] = cost;
}

void print_graph(Graph &graph){
    int nodes = graph.size();
    for(int i = 0 ; i < nodes ; i++){

        for(int j = 0 ; j < nodes ; j++){

            if(graph[i][j] > 0){
                cout<<"From "<<i<<" to "<<j<<" The cost is "<<graph[i][j]<<"\n";
            }
        }
    }
}

 
int main(){
     
    cout << "Enter the number of vertices and the number of edges: \n";
    int vertices;
    int edges;
    cin >> vertices >> edges;

    Graph graph(vertices, vector<int>(vertices,0)  );
    for (int i = 0 ; i < edges ; i++ ){
        int from, to, cost;
        cin >> from >> to >> cost;
        directed_graph(graph, from , to , cost);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 