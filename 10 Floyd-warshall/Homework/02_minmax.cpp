#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 1e5;


void print(GRAPH &graph){
    for(int i  = 0 ; i < graph.size() ; i++){
        for(int j = 0 ; j < graph[0].size(); j++){
            if(graph[i][j] >= OO)
                cout << "OO" << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    } 
    cout<<"*****************\n";
}

void compute_min_max(GRAPH &graph){
    int n = graph.size();
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                int relax = max( graph[i][k] ,graph[k][j]);
                graph[i][j] = min(graph[i][j] , relax);
            }
        }
    }
    cout<<"Final array:\n";
    print(graph);
}


void readGraph(GRAPH &graph){
    int nodes, edges;
    cin >> nodes >> edges;
    graph = GRAPH(nodes, vector<int>(nodes,OO)); 
    // set the dignoal of the table with 0
    // to prevent self loops
    for(int i = 0 ; i < nodes ; i++)
        graph[i][i] = 0;
    for(int i = 0 ; i < edges ; i++){
        int to,from,weight;
        cin >> from >> to >> weight;
        if(from == to) continue;
        graph[from][to] = min(graph[from][to], weight);
    }
    cout<<"Input array: \n";
    print(graph);
}

int main(){

    GRAPH graph;
    readGraph(graph);
    compute_min_max(graph);
    
}

/*

INPUT:


 */