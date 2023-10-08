#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

void directed_graph(Graph &graph,  int from , int to){
    graph[from][to]++;
}

void undirected_graph(Graph &graph, int from, int to){
    graph[from][to]++;
    graph[to][from]++;
}

void print_graph(Graph &graph, int nodes){

    for(int i = 0 ; i < nodes ; i++){

        for(int j = 0 ; j < nodes ; j++){

            if(graph[i][j] > 0){
                cout<<"From "<<i<<" to "<<j<<" There are "<<graph[i][j]<<" edges\n";
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
        int from, to;
        cin >> from >> to;
        directed_graph(graph, from , to);
    }
    cout<<"\nOutput\n";
  
    print_graph(graph, vertices);
    
    cout<<"\nNo Run Time Error\n";

    return 0;
} 
/*
5 8
0 1
1 2
2 3
4 3
3 2
4 3
0 1
4 3

Output
From 0 to 1 there are 2 edges
From 1 to 2 there are 1 edges
From 2 to 3 there are 1 edges
From 3 to 2 there are 1 edges
From 4 to 3 there are 3 edges

 */
